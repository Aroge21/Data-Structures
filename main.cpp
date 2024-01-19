#include <fstream>
#include <chrono>
#include "binary.hpp"
#include "binary.cpp"
#include "list.hpp"
#include "list.cpp"
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
            data.insert(data.top, temp);
        }
    } else {
        cout << "Not a valid file name!!!" << endl;
        exit(1);
    }
    myfile.close();

    auto end = hrc::now();
    duration<double> elapsed = end - start;
    cout << data.message() << elapsed.count() << " seconds" << endl;

    //cin >> temp;
    temp = "hello";
    start = hrc::now();
    int result = data.search(data.top, temp);
    cout << temp << ": " << result << endl;
    end = hrc::now();
    elapsed = end - start;

    cout << "Search Time: " << elapsed.count() << " seconds" << endl;
    cout << endl;
 
}

int main(int argc, char* argv[]){

    if(argc != 2) { 
        cout << "Please enter file input" << endl;
        exit(1);
    }

    cout << "\nFile Name: " << argv[1] << "\n" << endl;

    execute<balanacedTree<string> >(argv[1]);
    execute<searchTree<string> >(argv[1]);
    execute<queuedList<string> >(argv[1]);
    execute<sortedList<string> >(argv[1]);

    return 0;
}