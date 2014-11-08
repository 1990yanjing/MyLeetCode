#ifndef _RANDOM_LIST_NODE_H
#define _RANDOM_LIST_NODE_H

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

#endif