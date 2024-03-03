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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head,*second=head;
        while(first!=NULL &&n--)
        {
            first=first->next;
        }
        if(first==NULL)
        {
            head=head->next;
            return head;
        }
        ListNode *prev=NULL;
        while(first!=NULL)
        {
            prev=second;
            second=second->next;
            first=first->next;
        }
        prev->next=second->next;
    
    return head;
    }
};