#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.92 Reverse Linked List II
 * 倒置给定链表中，指定位置之间的节点
 * 我自己的方法
 * 建立一个栈将需要倒置的值入栈并记录倒置序列的前后指针节点，再将栈中的值出栈链接到首尾指针之间
 */
ListNode *reverseBetween(ListNode *head, int m, int n) 
{
	ListNode* start = new ListNode(-1);
	ListNode* end = NULL;
	ListNode* pre = new ListNode(-1), *worker = head;
	stack<int> cache;

	int step = 1;
	while(worker != NULL)
	{
		if(step == m)
			start = pre;
		if(step >= m && step <= n)
			cache.push(worker->val);
		if(step == n + 1)
		{

			end = worker;
			break;
		}		
		step++;
		pre = worker;
		worker = worker->next;
	}
	worker = start;
	while(cache.size() != 0)
	{
		ListNode *tmp = new ListNode(cache.top());
		worker->next = tmp;
		worker = tmp;
		cache.pop();
	}
	worker->next = end;

	if(m == 1)
		return start->next;
	else
		return head;
}
/**
 *头插法
 *首先找到起始位置之前的指针节点，作为倒置段的头指针；将起始位置的next作为尾指针，后面元素不断插入
 *到头指针之后（头插法），用尾指针联结之后的节点！！
 */
ListNode *reverseBetween(ListNode *head, int m, int n) 
{
	ListNode *blank_head = new ListNode(-1);
	blank_head->next = head;
	ListNode *prev = blank_head;

	for(int i = 0; i < m - 1; ++i)
		prev = prev->next;

	ListNode *reverse_head = prev;
	prev = prev->next;
	ListNode *cur = prev->next;

	for(int i = m; i < n; ++i)
	{
		prev->next = cur->next;
		cur->next = reverse_head->next;
		reverse_head->next = cur;
		cur = prev->next;
	}

	return blank_head->next;
}

























