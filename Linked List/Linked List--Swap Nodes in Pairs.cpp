#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.24 Swap Nodes in Pairs
 * 交换相邻节点
 * 注意：
 *     边界条件的判断
 */
ListNode *swapPairs(ListNode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* dummy_head = new ListNode(-1);
	dummy_head->next = head;
	ListNode *ptr1, *ptr2, *prev;
	prev = dummy_head;
	ptr1 = head;
	ptr2 = ptr1->next;
	while(ptr1 != NULL && ptr2 != NULL)
	{
		ListNode *tmp = ptr2->next;
		prev->next = ptr2;
		ptr2->next = ptr1;
		ptr1->next = tmp;
		prev = ptr1;
		ptr1 = tmp;
		if(ptr1)
			ptr2 = ptr1->next;
	}
	return dummy_head->next;
}