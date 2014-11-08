#include "Solution.h"
#include "RandomListNode.h"

/**
 * Linked List
 * No.138 Copy List with Random Pointer 
 * 对于带有随机指针
 *（除了next指针外，还有一个随机指向链表中节点的指针，也可能指向NULL）
 *　链表的深拷贝
 * 好巧妙的算法，无法形容。。。
 */
RandomListNode *copyRandomList(RandomListNode *head)
{
	RandomListNode *ptr = head;
	while(ptr)
	{
		RandomListNode *tmp = new RandomListNode(ptr->label);//深拷贝
		tmp->next = ptr->next;
		ptr->next = tmp;
		ptr = tmp->next;
	}

	ptr = head;
	while(ptr)
	{
		if(ptr->random != NULL)
			ptr->next->random = ptr->random->next;
		ptr = ptr->next->next;
	}

	RandomListNode *dummy_head = new RandomListNode(-1);
	ptr = head;
	RandomListNode *new_ptr = dummy_head;
	while(ptr)
	{
		new_ptr->next = ptr->next;
		new_ptr = new_ptr->next;
		ptr->next = ptr->next->next;
		ptr = ptr->next;
	}

	return dummy_head->next;
}