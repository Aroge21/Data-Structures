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


template<class T>
class binaryTree {
    protected:
        void rmData(treeBase<T>* &node);
    public:
        treeBase<T>* top;
        binaryTree();
        ~binaryTree();
        vl treeDepth(treeBase<T>* node);
};

template<class T>
class balanacedTree: public binaryTree<T> {
    string setup;
    public:
        balanacedTree() { setup = "Balanced Tree: "; };
        string message() { return setup; };
        void insert(treeBase<T>* &node, T insert);
        int search(treeBase<T>* node, T find);
};

template<class T>
class searchTree: public binaryTree<T> {
    string setup;
    public:
        searchTree() { setup = "Search Tree: "; };
        string message() { return setup; };
        void insert(treeBase<T>* &node, T insert);
        int search(treeBase<T>* node, T find);
};

#endif