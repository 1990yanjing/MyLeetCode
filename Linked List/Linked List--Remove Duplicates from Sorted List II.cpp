#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.82 Remove Duplicates from Sorted List II
 * 注意：
 *   边界条件的判断，时刻都要先判断链表是否到头了【cur != NULL】!!
 */
ListNode *deleteDuplicates(ListNode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode *dummy_head = new ListNode(head->val + 1);
	dummy_head->next = head;
	ListNode *cur = dummy_head->next;
	ListNode *prev = dummy_head;
	bool equal = false;

	while(cur != NULL)
	{
		if(cur->next != NULL && cur->val == cur->next->val)
		{
			equal = true;
			prev->next = cur->next;
			ListNode *tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		else
		{
			if(equal)
			{
				prev->next = cur->next;
				ListNode *tmp = cur;
				cur = cur->next;
				delete tmp
				equal = false;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
	return dummy_head->next;
}
