//
// Created by Aidan Ching on 4/5/2021.
//

#ifndef LAB_2_INTLIST_H
#define LAB_2_INTLIST_H

#include <iostream>
#include <ostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    void printReverse() const;
    friend ostream & operator<<(ostream &, const IntList &);
private:
    IntNode* dummyHead;
    IntNode* dummyTail;
};



#endif //LAB_2_INTLIST_H
