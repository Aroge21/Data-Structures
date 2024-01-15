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
class treeHead {
    public:
        treeBase<T>* root;
};

template<class T>
class binaryTree {
    public:
        treeHead<T> top;
        binaryTree();
        ~binaryTree();
        vl treeDepth(treeHead<T> node);
        void rmData(treeHead<T> &node);
};

template<class T>
class balanacedTree: public binaryTree<T> {
    string setup;
    public:
        balanacedTree() { setup = "Balanced Tree: "; };
        string message() { return setup; };
        void insert(treeHead<T> &node, T insert);
        int search(treeHead<T> node, T find);
};

template<class T>
class searchTree: public binaryTree<T> {
    string setup;
    public:
        searchTree() { setup = "Search Tree: "; };
        string message() { return setup; };
        void insert(treeHead<T> &node, T insert);
        int search(treeHead<T> node, T find);
};

#endif