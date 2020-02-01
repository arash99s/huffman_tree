#include <iostream>
#include "Compress.h"
#include "Extract.h"
#include "string.h"

using namespace std;

int main(int argc , char** argv) {
    cout << "1 : compress" << endl;
    cout << "2 : extract " << endl;
    cout << "enter number of choice :";
//    int number ;
//    cin >> number;
    if(strcmp(argv[1] , "1") == 0) {
        Compress compress = Compress(argv[2]);
        compress.execute();
    }else{
        Extract extract = Extract(argv[2]);
        extract.execute();
    }
    return 0;
}

