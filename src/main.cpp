#include <iostream>
#include "Compress.h"
#include "Extract.h"

using namespace std;

int main() {
    cout << "1 : compress" << endl;
    cout << "2 : extract " << endl;
    cout << "enter number of choice :";
    int number ;
    cin >> number;
    if(number == 1) {
        Compress compress = Compress("/home/arash/github_repositories/huffman_tree/data.txt");
        compress.execute();
    }else{
        Extract extract = Extract("/home/arash/github_repositories/huffman_tree/data.txt_compressed");
        extract.execute();
    }
    return 0;
}

