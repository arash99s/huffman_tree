//
// Created by arash on 23.01.20.
//

#include "BitBuffer.h"
#include "iostream"
using namespace std;

void
BitBuffer::outputBit(bool bit) {
    //buffer <<= 1;         // Make room for next bit.
    bits.operator<<=(1);
    if (bit) {
        //buffer |= 1; // Set if necessary.
        bits.operator|=(1);
    }
    count++;              // Remember we have added a bit.
    if (count == 8) {
        //file.write((char *)  &buffer, sizeof(buffer)); // Error handling elided.
        file.write((char *) &bits, 1);
        cout << "write : " << bits << endl;
        bits = {0b00000000};
        count = 0;
    }
}