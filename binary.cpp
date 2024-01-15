#include "binary.hpp"

// Fucntions for Binary Tree Class

template<class T>
binaryTree<T>::binaryTree() {
    top->root = NULL;
}

template<class T>
binaryTree<T>::~binaryTree() {
    rmData(this->top);
}

template<class T>
void binaryTree<T>::rmData(treeHead<T> &node) {
    if(node != NULL){
        rmData(node->left);
        rmData(node->right);
        delete node;
    }
}

template<class T>
vl binaryTree<T>::treeDepth(treeHead<T> node) {
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
void balanacedTree<T>::insert(treeHead<T> &node, T word) {
    
    if(node == NULL) {
        node = new treeBase<string>;
        
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

template<class T>
int balanacedTree<T>::search(treeHead<T> temp, T find) {
    int appear = 0;
    if(temp != NULL) {
        appear += (find.compare(temp->word) == 0) ? 1 : 0;
        appear += search(temp->left, find);
        appear += search(temp->right, find);
    }
    return appear;
}

// Funtions for Search Tree

template<class T>
void searchTree<T>::insert(treeHead<T> &node, T word) {
    
    if(node == NULL) {
        node = new treeBase<string>;
        
        if(node == NULL) {
            cout << "Memory Error!!!\n";
            exit(1);
        }

        node->word = word;
        node->left = node->right = NULL;
        
    } else {
        int result = node->word.compare(word);
        
        if(result >= 0) {
            insert(node->left, word);
        } else {
            insert(node->right, word);
        }
    }
}

template<class T>
int searchTree<T>::search(treeHead<T> temp, T find) {
    int result = 0;
    if(temp != NULL) {
        result += (temp->word.compare(find) == 0) ? 1 : 0;
        if(temp->word.compare(find) >= 0) {
            result += search(temp->left, find);
        } else {
            result += search(temp->right, find);
        }
    }

    return result;
}