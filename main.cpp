#include <fstream>
#include <chrono>
#include "binary.hpp"
using namespace std;
using namespace chrono;

template<class T>
void execute(char fileName[]) {
    typedef high_resolution_clock hrc;

    T data;
    string temp;

    fstream myfile(fileName);
    auto start = hrc::now();

    if(myfile.is_open()) {
        while(getline(myfile, temp)){
            data.insert(data.root, temp);
        }
    } else {
        cout << "Not a valid file name!!!" << endl;
        exit(1);
    }
    myfile.close();

    auto end = hrc::now();
    duration<double> elapsed = end - start;
    cout << data.message() << elapsed.count() << " seconds" << endl;

    cout << "Search word: hello";
    //cin >> temp;
    start = hrc::now();
    int result = data.search(data.root, "hello");
    cout << temp << ": " << result << endl;
    end = hrc::now();
    elapsed = end - start;
    cout << data.message() << elapsed.count() << " seconds" << endl;

}

int main(int argc, char* argv[]){

    if(argc != 2) { 
        cout << "Please enter file input" << endl;
    }

    execute<searchTree>(argv[1]);
    execute<balanacedTree>(argv[1]);
 
}