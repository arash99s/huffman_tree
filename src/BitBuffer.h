//
// Created by arash on 23.01.20.
//

#ifndef DATASTRUCTURE_BITBUFFER_H
#define DATASTRUCTURE_BITBUFFER_H

#include "bitset"
#include "fstream"
using namespace std;
class BitBuffer {
private:
    //unsigned char buffer = 0;
    bitset<8> bits{0b00000000};
    unsigned count = 0;
public:
    ofstream file; // Initialization skipped.
    bool outputBit(bool bit);
};


#endif //DATASTRUCTURE_BITBUFFER_H
