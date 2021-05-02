//
// Created by Aidan Ching on 4/5/2021.
//
#include <iostream>
using namespace std;
#include "IntList.h"



int main()
{
    IntList testing;

    for (unsigned i = 1; i <= 10; ++i)
    {
        testing.push_front(i);
    }


    cout << endl << testing << endl;



    cout << testing << endl;

}

