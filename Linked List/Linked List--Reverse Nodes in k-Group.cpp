#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.25 Reverse Nodes in k-Group
 * 倒置K段链表
 * 部分链表的原地倒置，一定是头插法的运用！！
 */
ListNode *reverseKGroup(ListNode *head, int k)
{
	if(head == NULL)
		return head;
	ListNode *ptr = head;
	int length = 0;
	while(ptr)
	{
		length++;
		ptr = ptr->next;
	}
	if(length < k)
		return head;

	int reverse_times = length / k;
	int step = 1;
	int cost_time = 1;
	ListNode *ptr1, *ptr2, *prev;
	ListNode *dummy_head = new ListNode(-1);
	dummy_head->next = head;
	prev = dummy_head;
	ptr1 = head;
	ptr2 =ptr1->next;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(step < k)
	    {
	    	ptr1->next = ptr2->next;
	    	ptr2->next = prev->next;
	    	prev->next = ptr2;
	    	ptr2 = ptr1->next;
	    	step++;
	    }
	    else
	    {
	    	cost_time++;
	    	step = 1;
	    	if(cost_time > reverse_times)
	    		break;
	    	else
	    	{
	    		prev = ptr1;
	    		ptr1 = ptr2;
	    		ptr2 = ptr1->next;
	    	}
	    }
	}
	return dummy_head->next;
}