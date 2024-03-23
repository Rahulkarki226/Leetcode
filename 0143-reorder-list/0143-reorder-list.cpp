/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middle(ListNode *head)
    {
        ListNode *fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev=NULL,*cur=head,*next;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *first=head;
        ListNode *mid=middle(head);
        ListNode *second=mid->next;
        mid->next=NULL;
        second=reverse(second);

        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(first || second)
        {
            if(first)
            {
                cur->next=first;
                cur=cur->next;
                first=first->next;
            }
            if(second)
            {
                cur->next=second;
                cur=cur->next;
                second=second->next;
            }
        }
        head=dummy->next;
        
    }
};