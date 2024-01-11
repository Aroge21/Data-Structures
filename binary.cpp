#include "binary.hpp"

binaryTree::binaryTree() {
    this->root = NULL;
}

vl binaryTree::treeDepth(tree *node) {
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

void binaryTree::treeInsert(tree **node, string insert) {
    
    if(*node == NULL) {
        *node = new tree;
        
        if(*node == NULL) {
            cout << "Memory Error!!!\n";
            exit(1);
        }

        (*node)->word = insert;
        (*node)->left = (*node)->right = NULL;
    } else {
        vl left = treeDepth((*node)->left);
        vl right = treeDepth((*node)->right);
        
        if(left <= right) {
            treeInsert(&(*node)->left, insert);
        } else {
            treeInsert(&(*node)->right, insert);
        }
    }

}

int binaryTree::wordSearch(tree *temp, string find) {
    int appear = 0;
    if(temp != NULL) {
        appear += (find.compare(temp->word) == 0) ? 1 : 0;
        if(find.compare(temp->word) >= 0){
            appear += wordSearch(temp->left, find);
        } else {
            appear += wordSearch(temp->right, find);
        }
    }
    return appear;
}