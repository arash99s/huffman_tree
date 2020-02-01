//
// Created by arash on 22.01.20.
//

#include "Extract.h"

using namespace std;
Extract::Extract(string file_name){
    this->file_name = file_name;
}

void
Extract::execute() {
    readFromFile();
    string buff = "";
    ofstream extracted(file_name + ".txt");
    if(!extracted.is_open())
        cout << "unable to open extracted file" << endl;
    for(unsigned char ch : my_buffer){
        int input = (int) ch;
        string byte_buff = integer2bin(input);
        byte_buff = convert2byte(byte_buff);
        for (int i = 0;i<byte_buff.length();i++){
            buff += byte_buff.at(i);
            char mychar;
            if(findChar(mychar , buff)){
                //cout << mychar ;
                extracted << mychar;
                buff = "";
            }
        }
    }
    cout <<endl;
    extracted.close();
}

bool
Extract::readFromFile() {
    ifstream myfile(file_name , ios::in | ios::binary);
    if (!myfile.is_open()) {
        cout << "unable to open the file" << endl;
        return false;
    }
    NodeDetails detail_number;
    myfile.read((char *) &detail_number , sizeof(NodeDetails));
    cout << detail_number.ch << " : "<< detail_number.code <<endl;
    for (int i=0;i<detail_number.code;i++){
        NodeDetails detail;
        myfile.read((char *) &detail , sizeof(NodeDetails));
        cout << detail.ch << " : " << integer2bin(detail.code , detail.bit_number) << endl;
        details.push_back(detail);
    }
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(myfile), {});
    my_buffer = buffer;
    cout << "size of buffer : " << my_buffer.size() << endl;
    myfile.close();
    return true;
}

string
Extract::integer2bin(int input) {
    string output_r = "";
    while(input >= 2){
        if(input % 2 == 0) output_r+="0";
        else output_r += "1";
        input /= 2;
    }
    output_r += to_string(input);
    string output = "";
    for(int i=output_r.length()-1;i>=0;i--){
        output += output_r.at(i);
    }
    return output;
}

bool
Extract::findChar(char &mychar, string code) {
    for (NodeDetails node : details){
        if(code == integer2bin(node.code , node.bit_number)){
            //cout << "code is : "<< code << endl;
            mychar = node.ch;
            return true;
        }
    }
    return false;
}

string
Extract::convert2byte(string byte_s) {
    string output = "";
    if(byte_s.length() < 8){
        for (int i=0;i<8-byte_s.length();i++){
            output += "0";
        }
    }
    output += byte_s;
    return output;
}


string
Extract::integer2bin(int input, int bit_number) {
    string s = integer2bin(input);
    string output = "";
    if(s.length() < bit_number){
        for (int i=0;i<bit_number-s.length();i++){
            output += "0";
        }
    }
    output += s;
    return output;
}
