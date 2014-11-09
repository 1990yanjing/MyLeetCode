#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.141 Linked List Cycle
 * 判断一个是否有环
 * 算法：
 *	   设置两个指针，从头节点开始，快指针每次走两步；慢指针每次走1步；
 *     如果快指针追上了慢指针则一定有环！！
 */
 bool hasCycle(ListNode *head)
 {
 	if(head == NULL || head->next == NULL)
 		return false;
 	ListNode *ptr1 = head->next;
 	ListNode *ptr2 = head->next->next;
 	while(ptr1 != NULL && ptr2 != NULL)
 	{
 		if(ptr1 == ptr2)
 			return true;
 		ptr1 = ptr1->next;
 		if(ptr2->next)
 			ptr2 = ptr2->next->next;
 		else
 			ptr2 = NULL;
 	}
 	return false;
 }