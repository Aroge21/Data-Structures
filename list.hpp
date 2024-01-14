#ifndef LIST
#define LIST

template <class T>
class listBase {
    T word;
    listBase *next;
};

template <class T>
class listHead {
    listBase* first;
    listBase* last;
};

template <class T>
class List {
    string searchTime;
    public:
        listHead<T> top;
        List();
        ~List();
};

template <class T>
class queuedList: public List<T> {

    

};


#endif