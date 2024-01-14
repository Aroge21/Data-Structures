#include "list.hpp"

template<class T>
List<T>::List() {
    top->first = top->last = NULL;
}

template<class T>
List<T>::~List() {
    if(top->first == NULL){
        top->last = NULL;
        return;
    }

    while(top->first != NULL) {
        listBase* delete = top->first;
        top->first = top->first->next;
        free(delete);
    }

    l->last = NULL;
}