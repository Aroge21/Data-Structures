#ifndef BINARY
#define BINARY

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef long long int vl;

class tree {
    public:
    string word;
    tree *right;
    tree *left;
};

class binaryTree {
    public:
        tree *root;
        binaryTree();
        vl treeDepth(tree *node);
        void treeInsert(tree **node, string insert);
        int wordSearch(tree *temp, string find);
};

#endif