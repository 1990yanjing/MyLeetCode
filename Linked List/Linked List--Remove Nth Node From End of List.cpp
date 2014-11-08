#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.19 Remove Nth Node From End of List
 * 删除链表中倒数第n个节点
 * 注意：
 *     当头结点会被删除的时候，考虑使用空头结点作为前赴节点的初值，免去条件判断！！
 */
ListNode *removeNthFromEnd(ListNode *head, int n) 
{
	if(head == NULL || n <= 0)
		return head;

	ListNode *dummy_head = new ListNode(-1);
	dummy_head->next = head;
	ListNode* ptr1, *ptr2, *prev;
	ptr1 = ptr2 = head;
	prev = dummy_head;
	int step = 0;
	while(ptr2 != NULL)
	{
		if(step >= n)
		{
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2 = ptr2->next;
		step++;
	}
	prev->next = ptr1->next;
	delete ptr1;
	return dummy_head->next;
}