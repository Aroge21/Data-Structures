#ifndef BINARY
#define BINARY

#include <iostream>
#include <cstdlib>
#include <string>

using std::cout, std::string, std::endl;

typedef long long int vl;

template<typename T>
class tree {
    public:
    T word;
    tree *right;
    tree *left;
};

class binaryTree {
    void rmTree(tree<string>* &node);
    virtual void insert() = 0;
    virtual void search() = 0;
    public:
        tree<string> *root;
        binaryTree();
        ~binaryTree();
        vl treeDepth(tree<string>* node);
};

class balanacedTree: public binaryTree {
    public:
        void insert(tree<string>* &node, string insert);
        int search(tree<string>* temp, string find);
};

class searchTree: public binaryTree {

};

#endif