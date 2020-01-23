//
// Created by arash on 22.01.20.
//

#ifndef DATASTRUCTURE_COMPRESS_H
#define DATASTRUCTURE_COMPRESS_H

#include "iostream"
#include "fstream"
#include "vector"
#include "bitset"
class Compress {
private:
    //std::ifstream myfile;
    std::string file_name;
    bool readFromFile();
    bool contain(std::vector<char> charackters , char cur_char);
    struct Node{
        char ch;
        int frequency;
        Node *left , *right;
        std::string code = "";
    };
    std::vector<Node *> nodes;
    void inc_frequency(char ch);
    void sortNodes();
    void encodeNodes(Node *root , std::string code);
    std::string findCode(char input);
    bool readAndWrite();
public:
    Compress(std::string file_name);
    void execute();
};


#endif //DATASTRUCTURE_COMPRESS_H
