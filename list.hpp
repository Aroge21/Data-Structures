#ifndef LIST
#define LIST

#include <cstdlib>
#include <string>
using namespace std;

template <class T>
class listBase {
    public:
        T word;
        listBase *next;
};

template <class T>
class listHead {
    public:
        listBase<T>* first;
        listBase<T>* last;
};

template <class T>
class List {
    public:
        listHead<T> top;
        List();
        ~List();
};

template <class T>
class queuedList: public List<T> {
    string setup;
    public:
        queuedList() { setup = "Queued List: "; };
        string message() { return setup; };
        void insert(listHead<T> &fhead, T insert);
        int search(listHead<T> fhead, T find);
        T pop(listHead<T> &fhead);
};

template <class T>
class sortedList: public List<T> {
    string setup;
    public:
        sortedList() { setup = "Sorted List: "; };
        string message() { return setup; };
        void insert(listHead<T> &fhead, T insert);
        int search(listHead<T> fhead, T find);
};

#endif