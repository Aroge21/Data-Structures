#ifndef BINARY
#define BINARY

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef long long int vl;

template<typename T>
class tree {
    public:
    T word;
    tree *right;
    tree *left;
};

class binaryTree {
    public:
        tree<string> *root;
        binaryTree();
        ~binaryTree();
        vl treeDepth(tree<string>* node);
        void rmTree(tree<string>* &node);
};

class balanacedTree: public binaryTree {
    string prompt;
    public:
        balanacedTree() { prompt = "Balanced Tree: "; };
        string message() { return prompt; };
        void insert(tree<string>* &node, string insert);
        int search(tree<string>* temp, string find);
};

class searchTree: public binaryTree {
    string prompt;
    public:
        searchTree() { prompt = "Search Tree: "; };
        string message() { return prompt; };
        void insert(tree<string>* &node, string insert);
        int search(tree<string>* temp, string find);
};

#endif