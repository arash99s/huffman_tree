//
// Created by arash on 22.01.20.
//

#include "Compress.h"
#include "iostream"
#include "vector"
#include "BitBuffer.h"

using namespace std;

Compress::Compress(std::string file_name) {
    this->file_name = file_name;
}

void
Compress::execute() {
    readFromFile();
    while(nodes.size() != 1) {
        sortNodes();
        Node *left_node = nodes.at(0);
        Node *right_node = nodes.at(1);
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        Node *heap = new Node;
        heap->left = left_node;
        heap->right = right_node;
        heap->frequency = left_node->frequency + right_node->frequency;
        heap->ch = NULL;
        nodes.push_back(heap);
    }
    cout<<"***************"<<endl;
    cout <<"root.frequency : "<< nodes.front()->frequency<<endl;

    encodeNodes(nodes.front() , "");
    nodes.erase(nodes.begin());  ///root
    cout<<"*************"<<endl;
    for (Node *node : nodes) {
        string s = "";
        s += node->ch;
        if (s == "\n") s = "enter";
        if (s == " ") s = "space";
        cout << s << " : " << node->code << endl;
    }
    ///////////////////
    if(!readAndWrite())
        cout << "cannot open readable file"<<endl;
}

bool
Compress::readFromFile() {
    ifstream myfile(file_name);
    if (!myfile.is_open()) {
        cout << "unable to open the file" << endl;
        return false;
    }
    vector<char> charackters;
    while (!myfile.eof()) {
        char myChar;
        myfile.get(myChar);
        if (!contain(charackters, myChar)) {
            charackters.push_back(myChar);
            Node *node = new Node();
            node->ch = myChar;
            node->frequency = 1;
            node->left = NULL;
            node->right = NULL;
            nodes.push_back(node);
        } else {
            inc_frequency(myChar);
        }
        cout << myChar;
    }
    myfile.close();
    cout << endl;
    for (Node *node : nodes) {
        string s = "";
        s += node->ch;
        if (s == "\n") s = "enter";
        if (s == " ") s = "space";
        cout << s << " : " << node->frequency << endl;
    }
    return true;
}

bool
Compress::contain(vector<char> charackters, char cur_char) {
    bool exist = false;
    for (char ch : charackters) {
        if (ch == cur_char)
            exist = true;
    }
    return exist;
}

void
Compress::inc_frequency(char ch) {
    for (Node *node : nodes) {
        if (node->ch == ch)
            node->frequency++;
    }
}

void
Compress::sortNodes() {
    vector<Node*> sorted;
    int length = nodes.size();
    for(int i=0;i<length ; i++) {
        int min_frequency = nodes.at(0)->frequency;
        int iterator = 0;
        for (int j = 0; j < nodes.size(); j++) {
            Node *node = nodes.at(j);
            if (node->frequency < min_frequency) {
                min_frequency = node->frequency;
                iterator = j;
            }
        }
        sorted.push_back(nodes.at(iterator));
        nodes.erase(nodes.begin() + iterator);
    }
    nodes.clear();
    nodes = sorted;
    sorted.clear();

//    cout<<"***************"<<endl;
//    for(Node* node : nodes)
//        cout << node->frequency<<endl;
}

void
Compress::encodeNodes(Node *root , string code) {
    if(root->left == NULL && root->right == NULL) {
        root->code = code;
        nodes.push_back(root);
        return;
    }
    encodeNodes(root->left , code+"0");
    encodeNodes(root->right , code+"1");
}

string
Compress::findCode(char input) {
    for(Node *node : nodes){
        if(node->ch == input)
            return node->code;
    }
    return "";
}

bool
Compress::readAndWrite() {
    ifstream myfile(file_name);
    if (!myfile.is_open()) {
        cout << "unable to open the file" << endl;
        return false;
    }
    BitBuffer bitBuffer;
    bitBuffer.file = ofstream("../compressed", ios::out | ios::binary);
    while (!myfile.eof()) {
        char myChar;
        myfile.get(myChar);
        string myCode = findCode(myChar);
        for (int i=0;i<myCode.length();i++){
            if(myCode.at(i)=='0') bitBuffer.outputBit(0);
            else bitBuffer.outputBit(1);
        }
    }
    myfile.close();
    bitBuffer.file.close();
    return true;
}