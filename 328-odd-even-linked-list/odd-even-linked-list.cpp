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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==NULL || head->next==NULL)return head;
        // vector<int>arr;
        // ListNode* temp=head;
        // int i=0;

        

        // while(temp!=NULL && temp->next!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next->next;
        //     i++;
        // }

        // if(temp){
        //     arr.push_back(temp->val);
        // }

        // temp=head->next;
        // while(temp!=NULL && temp->next!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next->next;
        //     i++;
        // }

        // if(temp){
        //     arr.push_back(temp->val);
        // }
        // temp=head;

        // for(int i=0;i<arr.size();i++){
        //     temp->val=arr[i];
        //     temp=temp->next;
        // }

        // return head;
        
        if(head==NULL || head->next==NULL)return head;
        ListNode* o=head;
        ListNode* e=head->next;
        ListNode* evenHead=head->next;

        while(e!=NULL && e->next!=NULL){
            o->next=o->next->next;
            e->next=e->next->next;

            o=o->next;
            e=e->next;
        }
        o->next=evenHead;
        return head;
    }
};