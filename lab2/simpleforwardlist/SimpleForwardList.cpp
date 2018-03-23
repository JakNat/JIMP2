//
// Created by WiktorW on 3/11/2018.
//

#include <array>
#include "SimpleForwardList.h"
using namespace std;

ForwardList *CreateNode(int value)
{
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = nullptr;
    return  node;
}

void DestroyList(ForwardList *list){
    ForwardList* itr = list;

    while (itr != nullptr)
    {
        ForwardList* tmp = itr;
        itr = itr->next;
        delete tmp;
    }
}