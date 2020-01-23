//
// Created by arash on 22.01.20.
//

#ifndef DATASTRUCTURE_EXTRACT_H
#define DATASTRUCTURE_EXTRACT_H

#include "iostream"
#include "fstream"
#include "vector"
#include "bitset"
class Extract {
private:
    std::string file_name;
    bool readFromFile();
    struct NodeDetails{
        char ch;
        int bit_number;
        int code ;
        //std::string code;
    };
    std::vector<NodeDetails> details;
    std::vector<unsigned char> my_buffer;
    std::string integer2bin(int input);
    std::string integer2bin(int input , int bit_number);
    bool findChar(char &mychar , std::string code);
    std::string convert2byte(std::string byte_s);
    int bin2integer(std::string bin);
public:
    Extract(std::string file_name);
    void execute();
};


#endif //DATASTRUCTURE_EXTRACT_H
