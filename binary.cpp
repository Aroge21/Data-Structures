#include "binary.hpp"
// Fucntions for Binary Tree Class

template<class T>
binaryTree<T>::binaryTree() {
    top = NULL;
}

template<class T>
binaryTree<T>::~binaryTree() {
    rmData(top);
}

template<class T>
void binaryTree<T>::rmData(treeBase<T>* &node) {
    if(node != NULL){
        rmData(node->left);
        rmData(node->right);
        delete node;
    }
}

template<class T>
vl binaryTree<T>::treeDepth(treeBase<T>* node) {
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

// Funtions for Balanced Tree

template<class T>
void balanacedTree<T>::insert(treeBase<T>* &node, T insert) {
    if(filter.top.first == NULL) {
        node = new treeBase<T>;
        filter.insert(filter.top, this->top);
    }

    treeBase<T>* temp = filter.pop(filter.top);
    temp->word = insert;

    temp->left = new treeBase<T>;
    temp->left->left = temp->left->right = NULL;
    temp->right = new treeBase<T>;
    temp->right->left = temp->right->right = NULL;

    filter.insert(filter.top, temp->left);
    filter.insert(filter.top, temp->right);
}

template<class T>
int balanacedTree<T>::search(treeBase<T>* temp, T find) {
    int appear = 0;
    if(temp != NULL) {
        appear += (temp->word == find) ? 1 : 0;
        appear += search(temp->left, find);
        appear += search(temp->right, find);
    }
    return appear;
}

// Funtions for Search Tree

template<class T>
void searchTree<T>::insert(treeBase<T>* &node, T word) {
    
    if(node == NULL) {
        node = new treeBase<T>;
        
        if(node == NULL) {
            cout << "Memory Error!!!\n";
            exit(1);
        }

        node->word = word;
        node->left = node->right = NULL;
        
    } else {
        if(word < node->word) {
            insert(node->left, word);
        } else {
            insert(node->right, word);
        }
    }
}

template<class T>
int searchTree<T>::search(treeBase<T>* temp, T find) {
    int result = 0;
    if(temp != NULL) {
        result += (find == temp->word) ? 1 : 0;
        if(find < temp->word) {
            result += search(temp->left, find);
        } else {
            result += search(temp->right, find);
        }
    }

    return result;
}