#include "list.hpp"

// Funtions for Base List

template<class T>
List<T>::List() {
    top.first = top.last = NULL;
}

template<class T>
List<T>::~List() {
    if(top.first == NULL){
        top.last = NULL;
        return;
    }

    listBase<T>* temp;
    while(top.first != NULL) {
        temp = top.first;
        top.first = top.first->next;
        delete temp;
    }

    top.last = NULL;
}

// Funtions for Queued List

template <class T>
void queuedList<T>::insert(listHead<T> &fhead, T insert) {
    listBase<T>* qnode = new listBase<T>;
    if(qnode == NULL) {
        printf("Out of Memory!!!\n");
        exit(1);
    }
    qnode->next = NULL;
    qnode->word = insert;

    if(fhead.first == NULL){
        fhead.first = fhead.last = qnode;
    } else {
        fhead.last->next = qnode;
        fhead.last = qnode;
    }
}

template <class T>
int queuedList<T>::search(listHead<T> fhead, T find) {
    int result = 0;
    while(fhead.first != NULL) {
        result += (fhead.first->word == find) ? 1 : 0;
        fhead.first = fhead.first->next;
    }

    return result;
}

// Funtions for Sorted List

template <class T>
void sortedList<T>::insert(listHead<T> &fhead, T insert) {
    
    listBase<T>* snode = new listBase<T>;
    if(snode == NULL) {
        printf("Out of Memory!!!\n");
        exit(1);
    }
    
    snode->word = insert;
    snode->next = NULL;

    if(fhead.first == NULL || insert < fhead.first->word) {
        snode->next = fhead.first;
        fhead.first = snode;
        return;
    }

    listBase<T>* temp = fhead.first;
    while(temp->next != NULL && insert > temp->next->word) {
        temp = temp->next;
    }

    snode->next = temp->next;
    temp->next = snode;
}

template <class T>
int sortedList<T>::search(listHead<T> fhead, T find) {
    int result = 0;
    while((fhead.first != NULL) && (find >= fhead.first->word)) {
        result += (fhead.first->word == find) ? 1 : 0;
        fhead.first = fhead.first->next;
    }

    return result;
}
