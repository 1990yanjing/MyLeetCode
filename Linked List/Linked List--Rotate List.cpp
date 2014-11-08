#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.61 Rotate List
 * 向右旋转K个元素（是指将从右面数第k个元素作为头，左面剩余元素链接在尾部）
 * 首先，将链表首尾相连；然后，找到第len-K个元素，将其后面的节点作为新的头结点，将第len-k个元素作为尾节点。
 * 注意：
 * 	   链表判空！！
 */
ListNode *rotateRight(ListNode *head, int k)
{
	if(head == NULL || k == 0)
		return head;

	ListNode* ptr = head;
	int length = 1;

	while(ptr->next)//找到链表的尾部
	{
		ptr = ptr->next;
		length++;
	}
	ptr->next = head; //将链表组织为环
	k = length - k % length;
	for(int i = 0; i < k; ++i)
		ptr = ptr->next;
	head = ptr->next;
	ptr->next = NULL;
	return head;
}