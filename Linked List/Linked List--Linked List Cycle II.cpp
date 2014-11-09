#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.143 Reorder List
 */
 void reorderList(ListNode *head)
 {
 	ListNode *slow = head;
 	ListNode *fast = head;

    //找到中间指针，拆分链表为两个链表
 	while(fast && fast->next)
 	{
 		slow = slow->next;
 		fast = fast->next->next;
 	}
 	if(head == NULL || slow->next == NULL)
 		return;
 	ListNode *head1 = head;
 	ListNode *head2 = slow->next;
 	slow->next = NULL;
    
    //倒置链表2
 	ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head2;
 	if(head2->next != NULL)
 	{
	 	ListNode *tail = head2;
	 	ListNode *cur = tail->next;

	 	while(cur != NULL)
	 	{
	 		tail->next = cur->next;
	 		cur->next = dummy_head->next;
	 		dummy_head->next = cur;
	 		cur = tail->next;
	 	}
	 	head2 = dummy_head->next;
 	}
	 	
    //将两个链表合并，将链表2交叉插入链表1
 	ListNode *ptr1 = head1;
 	ListNode *ptr2 = head2;

 	while(ptr2 != NULL)
 	{
 		ListNode *tmp1 = ptr1->next;
 		ListNode *tmp2 = ptr2->next;
 		ptr1->next = ptr2;
 		ptr2->next = tmp1;
 		ptr1 = tmp1;
 		ptr2 = tmp2;
 	}
 }

