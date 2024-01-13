#include <fstream>
#include <chrono>
using namespace std; 

#include "binary.hpp"


int main(){
    binaryTree example;
    string fileText;

    fstream myfile("fairy_tails.txt");
    if(myfile.is_open()) {
        while(getline(myfile, fileText)){
            example.treeInsert(example.root, fileText);
        }
    }
    myfile.close();

    cout << "Please Enter a word to search: ";
    cin >> fileText;
    int result = example.wordSearch(example.root, fileText);
    cout << fileText << ": " << result << endl;
 
}