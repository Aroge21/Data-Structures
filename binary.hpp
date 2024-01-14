#ifndef BINARY
#define BINARY

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef long long int vl;

template<typename T>
class treeBase {
    public:
    T word;
    treeBase *right;
    treeBase *left;
};

class binaryTree {
    public:
        treeBase<string> *root;
        binaryTree();
        ~binaryTree();
        vl treeDepth(treeBase<string>* node);
        void rmData(treeBase<string>* &node);
};

class balanacedTree: public binaryTree {
    string setup;
    public:
        balanacedTree() { setup = "Balanced Tree: "; };
        string message() { return setup; };
        void insert(treeBase<string>* &node, string insert);
        int search(treeBase<string>* temp, string find);
};

class searchTree: public binaryTree {
    string setup;
    public:
        searchTree() { setup = "Search Tree: "; };
        string message() { return setup; };
        void insert(treeBase<string>* &node, string insert);
        int search(treeBase<string>* temp, string find);
};

#endif