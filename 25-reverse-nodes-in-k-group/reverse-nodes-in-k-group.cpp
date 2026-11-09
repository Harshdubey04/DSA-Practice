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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;

            temp = temp->next;
        }
        
        int cnt=0;

        while(curr!=NULL && cnt<k){
            cnt++;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        if(next!=NULL){
            ListNode* restHead=reverseKGroup(next,k);
            head->next=restHead;
        }
        return prev;
    }
};