#include "Solution.h"

/**
 * Linked List
 * No.2 Add Two Numbers 
 * 空头节点式建立链表
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode* head = new ListNode(-1);
	ListNode* ptr1 = l1, *ptr2 = l2;
	ListNode* worker = head;
	int carray = 0;
	int sum = 0;
	int digit = 0;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		sum = ptr1->val + ptr2->val + carray;
		carray = sum / 10;
		digit = sum % 10;
		ListNode *tmp = new ListNode(digit);
		worker->next = tmp;
		worker = tmp;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	while(ptr1 != NULL)
	{
		sum = ptr1->val + carray;
		carray = sum / 10;
		digit = sum % 10;
		ListNode *tmp = new ListNode(digit);
		worker->next = tmp;
		worker = tmp;
		ptr1 = ptr1->next;
	}

	while(ptr2 != NULL)
	{
		sum = ptr2->val + carray;
		carray = sum / 10;
		digit = sum % 10;
		ListNode *tmp = new ListNode(digit);
		worker->next = tmp;
		worker = tmp;
		ptr2 = ptr2->next;
	}

	if(carray != 0)
	{
		ListNode *tmp = new ListNode(carray);
		worker->next = tmp;
	}

	return head->next;
}
