//
// Created by WiktorW on 3/11/2018.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

typedef struct ForwardList{
    int value;
    struct ForwardList* next;
}ForwardList;

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
