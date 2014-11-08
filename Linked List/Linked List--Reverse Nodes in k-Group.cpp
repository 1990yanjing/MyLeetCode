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
	while(ptr)//获得链表长度
	{
		length++;
		ptr = ptr->next;
	}
	if(length < k)
		return head;

	int reverse_times = length / k;//判断需要倒置几组链表段儿
	int step = 1;//控制每组的倒置长度
	int cost_time = 1;//控制倒置了几组
	ListNode *ptr1, *ptr2, *prev;
	ListNode *dummy_head = new ListNode(-1);
	dummy_head->next = head;
	prev = dummy_head;
	ptr1 = head;
	ptr2 =ptr1->next;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(step < k)//每组的倒置实现（头插法），保持每组的尾节点，并跟踪后记节点
	    {
	    	ptr1->next = ptr2->next;
	    	ptr2->next = prev->next;
	    	prev->next = ptr2;//头插
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