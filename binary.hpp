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
    public:
        tree<string> *root;
        binaryTree();
        ~binaryTree();
        vl treeDepth(tree<string>* node);
};

class balTree: public binaryTree {
    public:
        void treeInsert(tree<string>* &node, string insert);
        int wordSearch(tree<string>* temp, string find);
};

class searchTree: public binaryTree {

};

#endif