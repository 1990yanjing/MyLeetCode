#ifndef _LIST_NODE_H
#define _LIST_NODE_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif