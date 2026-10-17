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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode=nullptr;
        ListNode* temp=head;

        while(temp!=nullptr){
            ListNode* nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
        }

        return prevNode;




    }
};