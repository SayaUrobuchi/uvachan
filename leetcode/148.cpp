/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
	struct ListNode *p1, *p2, *p0;
    if (!head || !(head->next))
    {
    	return head;
    }
    p1 = head;
    p2 = head->next;
    while (p2 && p2->next)
    {
    	p1 = p1->next;
    	p2 = p2->next;
    	p2 = p2->next;
    }
    p2 = p1->next;
    p1->next = NULL;
    p1 = sortList(head);
    p2 = sortList(p2);
    head = NULL;
    p0 = NULL;
    while (p1 && p2)
    {
    	if (p1->val < p2->val)
    	{
    		if (!p0)
    		{
    			p0 = p1;
    			head = p0;
    		}
    		else
    		{
    			p0->next = p1;
    			p0 = p0->next;
    		}
    		p1 = p1->next;
    	}
    	else
    	{
    		if (!p0)
    		{
    			p0 = p2;
    			head = p0;
    		}
    		else
    		{
    			p0->next = p2;
    			p0 = p0->next;
    		}
    		p2 = p2->next;
    	}
    }
    while (p1)
    {
    	p0->next = p1;
    	p0 = p0->next;
    	p1 = p1->next;
    }
    while (p2)
    {
    	p0->next = p2;
    	p0 = p0->next;
    	p2 = p2->next;
    }
    p0->next = NULL;
    return head;
}
