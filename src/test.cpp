#include <iostream>
#include <bitset>
#include <vector>
#include "Compress.h"
#include "BitBuffer.h"
#include "Extract.h"

using namespace std;

int main() {
    BitBuffer bitBuffer;
    bitBuffer.file = ofstream("student", ios::out | ios::binary);

    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);
    bitBuffer.outputBit(0);

    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(1);
    bitBuffer.outputBit(0);


    bitBuffer.file.close();

    /////////////////////////////////////////////////////////reading
    ifstream file2("student", ios::in | ios::binary);
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file2), {});
    file2.close();


    cout << "size of buffer : " << sizeof(buffer) << endl;

    cout << "size of buffer : " << buffer.size() << endl;

    cout << (int) buffer.at(0) << endl;
    cout << (int) buffer.at(1) << endl;

    cout << "1 : compress" << endl;
    cout << "2 : extract " << endl;
    cout << "enter number of choice :";
    int number ;
    cin >> number;
    if(number == 1) {
        Compress compress = Compress("/home/arash/Desktop/dataStructure/data.txt");
        compress.execute();
    }else{
        Extract extract = Extract("/home/arash/Desktop/dataStructure/compressed");
        ifstream file3("/home/arash/Desktop/dataStructure/compressed", ios::in | ios::binary);
        std::vector<unsigned char> buffer2(std::istreambuf_iterator<char>(file3), {});
        file2.close();

        cout << "size of buffer : " << sizeof(buffer2) << endl;

        cout << "size of buffer : " << buffer2.size() << endl;

        cout << (int) buffer2.at(0) << endl;
        cout << (int) buffer2.at(1) << endl;
    }
    return 0;
}

