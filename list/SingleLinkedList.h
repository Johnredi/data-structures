#include <iostream>
#include <cstdarg>

#ifndef DSA_SINGLELINKEDLIST_H
#define DSA_SINGLELINKEDLIST_H

template<typename T>
struct SingleLinkedListNode {
    T data;
    SingleLinkedListNode *next;
};

template<typename T>
class SingleLinkedList {
private:
    SingleLinkedListNode<T> *head;
    SingleLinkedListNode<T> *tail;

public:
    SingleLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    };

    explicit SingleLinkedList(T item, ...) {
        this->head = nullptr;
        this->tail = nullptr;

        va_list arguments;

        va_start (arguments, item);
        for (int x = 0; x < item; x++) {
            this->add(va_arg (arguments, T));
        }
        va_end (arguments);
    };

    /**
     * Adds an item at the end
     * @param item item to be inserted
     */
    void add(T item);

    /**
     * Adds an item at specified `index`
     * @param index position of item to be inserted
     * @param item item to be inserted
     * @return return true if `index` is a valid index
     */
    void add(int index, T item);

    /**
     * Adds an element where predicate is true otherwise at the end of lst
     * @param item item to be inserted
     */
    void addWhere(T item, std::function<bool(T, T)>);

    /**
     * Add an item at head of list
     * @param item item to be inserted
     */
    void addFirst(T item);

    /**
     * clears the whole list
     */
    void clear();

    /**
     * get element at `index`
     * @param index index of item starts from 0
     * @return returns element at `index`
     */
    T get(int index);

    /**
     * returns first element of list
     * @return returns first element of list
     */
    T getFirst();

    /**
     * returns last element of list
     * @return returns last element of list
     */
    T getLast();

    /**
     * return index of first occurrence of `item`
     * @param item item to search
     * @return index of `item` of found else -1
     */
    int indexOf(T item);

    /**
     * return index of last occurrence of `item`
     * @param item item to search
     * @return index of `item` of found else -1
     */
    int lastIndexOf(T item);

    /**
     * removes last item
     * @return return removed item
     */
    T remove();

    /**
     * removes
     * @param index
     * @return return removed item
     */
    T removeByIndex(int index);

    int remove(T item);

    int removeRight(T item);

    T removeFirst();

    /**
     * replace nth element with new item
     * @param index
     * @param item
     */
    T set(int index, T item);

    /**
     * find size of linked list
     * @return size of the linked list
     */
    int size();
};


#endif //DSA_SINGLELINKEDLIST_H
