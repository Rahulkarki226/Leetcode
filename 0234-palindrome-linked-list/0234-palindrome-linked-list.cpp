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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev=NULL,*curr=head,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode * middle(ListNode *head)
    {
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *left=head;
        ListNode *mid=middle(head);
        ListNode *right=mid->next;
        mid->next=NULL;
        right=reverse(right);

        while(left && right)
        {
            if(left->val!=right->val)
               return false;
            
            left=left->next;
            right=right->next;
        }
        return true;
    }
};