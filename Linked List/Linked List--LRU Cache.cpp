#include "Solution.h"
#include "ListNode.h"

/**
 * Linked List
 * No.146 LRU Cache
 */
struct ListNode {
  int key;
  int value
  ListNode *next;
  ListNode(int x) : key(x), val(x), next(NULL) {}
};

class LRUCache
{
public:
	int capacity;
	int count;
	ListNode* dummy_head;
	ListNode* tail;
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        this->dummy_head = new ListNode(-1);
        this->tail = new ListNode(-1);
        this->count = 0;
    }
    
    int get(int key) 
    {
        ListNode *ptr = dummy_head->next;
        while(ptr)
        {
        	if(ptr->key == key)
        		return ptr->value;
        }
        return -1;
    }
    
    void set(int key, int value) 
    {
    	count++;
    	ListNode *ptr = dummy_head->next;
    	if(get(key))
    	{
    		while(ptr)
	        {
	        	if(ptr->key == key)
	        		ptr->value = value;
	        }
    	}
    	else
    	{
    		if(count > capacity)
    		{
    			ListNode *tmp = dummy_head->tmp;
    			dummy_head->next = dummy_head->next->next;
    			delete tmp;
    		}
    	}
    }
};