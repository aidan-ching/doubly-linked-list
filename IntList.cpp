//
// Created by Aidan Ching on 4/5/2021.
//

#include "IntList.h"

IntList::IntList()
{
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList()
{
    IntNode *currNode = dummyHead;
    while (currNode != nullptr)
    {
        IntNode* next = currNode->next;
        delete currNode;
        currNode = next;
    }
    delete currNode;

}

void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);
    IntNode *after = dummyHead->next;
    dummyHead->next = newNode;
    newNode->next = after;
    after->prev = newNode;
    newNode->prev = dummyHead;
}

void IntList::pop_front()
{
    if (this->empty())
    {
        return;
    }
    IntNode *remove = dummyHead->next;
    IntNode *sucNode = remove->next;
    dummyHead->next = sucNode;
    sucNode->prev = dummyHead;
    delete remove;
}

void IntList::push_back(int value)
{
    IntNode *newNode = new IntNode(value);
    IntNode *before = dummyTail->prev;
    dummyTail->prev = newNode;
    newNode->prev = before;
    before->next = newNode;
    newNode->next = dummyTail;
}

void IntList::pop_back()
{
    if (this->empty())
    {
        return;
    }
    IntNode *remove = dummyTail->prev;
    IntNode *sucNode = remove->prev;
    dummyTail->prev = sucNode;
    sucNode->next = dummyTail;
    delete remove;
}

bool IntList::empty() const
{
    if (dummyHead->next == dummyTail)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void IntList::printReverse() const
{
    IntNode *currNode = dummyTail->prev;
    while (currNode != dummyHead)
    {
        cout << currNode->data << " ";
        currNode = currNode->prev;
    }
}

ostream & operator <<(ostream &out, const IntList &rhs)
{
    if (rhs.empty())
    {
        return out;
    }

    IntNode *currNode = rhs.dummyHead->next;
    while (currNode->next != rhs.dummyTail)
    {
        out << currNode->data << " ";
        currNode = currNode->next;
    }

    out << currNode->data;
    return out;
}