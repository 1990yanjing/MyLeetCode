#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.86 Partition List 
 * 按照X的值，将原链表分区
 * 做两个链表，一个是小于X，一个是大于等于X的，然后将这两个链表链接起来
 */
ListNode *partition(ListNode *head, int x)
{
	ListNode *left_head = new ListNode(-1);
	ListNode *right_head = new ListNode(-1);
	ListNode *left_ptr = left_head;
	ListNode *right_ptr = right_head;


	ListNode *cur =  head;

	while (cur != NULL)
	{
		if(cur->val < x)
		{
			left_ptr->next = cur;
			left_ptr = cur;
		}
		else
		{
			right_ptr->next = cur;
			right_ptr = cur;
		}
		cur = cur->next;
	}

	left_ptr->next = right_head->next;
	right_ptr->next = NULL;

	return left_head->next;
}
