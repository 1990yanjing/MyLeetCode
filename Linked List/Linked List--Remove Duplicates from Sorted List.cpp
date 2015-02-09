#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.83 Remove Duplicates from Sorted List
 * 注意:
 * 判空！！即链表是空的
 */
ListNode *deleteDuplicates(ListNode *head)
{
	if(head == NULL)
		return head;
	ListNode *cur = head->next;
	ListNode *prev = head;

	while(cur != NULL)
	{
		if(cur->val == prev->val)
		{
			prev->next = cur->next;
			ListNode *tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
