#include "binary.hpp"

// Fucntions for Binary Tree Class

binaryTree::binaryTree() {
    this->root = NULL;
}

binaryTree::~binaryTree() {
    rmTree(this->root);
}

void binaryTree::rmTree(tree<string>* &node) {
    if(node != NULL){
        rmTree(node->left);
        rmTree(node->right);
        delete node;
    }
}

// Funtions for Balanaced Tree

vl binaryTree::treeDepth(tree<string> *node) {
    if(node != NULL) {
        vl leftval = treeDepth(node->left);
        vl rightval = treeDepth(node->right);

        if(leftval > rightval) {
            return leftval + 1;
        } else {
            return rightval + 1;
        }
    }

    return 0;
}

void balanacedTree::insert(tree<string>* &node, string word) {
    
    if(node == NULL) {
        node = new tree<string>;
        
        if(node == NULL) {
            cout << "Memory Error!!!\n";
            exit(1);
        }

        node->word = word;
        node->left = node->right = NULL;
    } else {
        vl left = treeDepth(node->left);
        vl right = treeDepth(node->right);
        
        if(left <= right) {
            insert(node->left, word);
        } else {
            insert(node->right, word);
        }
    }

}

int binaryTree::wordSearch(tree<string> *temp, string find) {
    int appear = 0;
    if(temp != NULL) {
        appear += (find.compare(temp->word) == 0) ? 1 : 0;
        appear += wordSearch(temp->left, find);
        appear += wordSearch(temp->right, find);
    }
    return appear;
}