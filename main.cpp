#include <fstream>
#include <chrono>
#include "binary.hpp"
using namespace std;
using namespace chrono;

template<class T>
void execute(string prompt) {

    T data;
    string temp;

    fstream myfile("fairy_tails.txt");
    auto start = high_resolution_clock::now();

    if(myfile.is_open()) {
        while(getline(myfile, temp)){
            data.insert(data.root, temp);
        }
    }
    myfile.close();

    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;

    cout << data.prompt << duration.count() << " seconds";

    cout << "Please Enter a word to search: ";
    cin >> temp;
    int result = data.search(data.root, temp);
    cout << temp << ": " << result << endl;

}

int main(int argc, char* argv[]){

    execute<searchTree>();
 
}