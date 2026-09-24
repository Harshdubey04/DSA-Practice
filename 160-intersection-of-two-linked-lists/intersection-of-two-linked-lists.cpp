/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // map<ListNode*,int>mpp;
        // ListNode *temp1=headA;
        // while(temp1!=NULL){
        //     mpp[temp1]=1;
        //     temp1=temp1->next;
        // }
        // ListNode *temp2=headB;
        // while(temp2!=NULL){
        //     if(mpp.find(temp2)!=mpp.end()){
        //         return temp2;
        //     }
        //     temp2=temp2->next;
        // }
        // return NULL;

        //     ListNode* temp1=headA;
        //     ListNode* temp2=headB;
        //     int len1=0,len2=0;
        //     while(temp1!=NULL){
        //         len1++;
        //         temp1=temp1->next;
        //     }
        //     while(temp2!=NULL){
        //         len2++;
        //         temp2=temp2->next;
        //     }

        //     temp1=headA;
        //     temp2=headB;

        //    if(len1>len2){
        //     int d=len1-len2;
        //     while(d--){
        //         temp1=temp1->next;
        //     }
        //    }
        //    else{
        //     int d=len2-len1;
        //     while(d--){
        //         temp2=temp2->next;
        //     }
        //    }

        //    while(temp1!=NULL && temp2!=NULL){
        //     if(temp1==temp2)return temp1;
        //     temp1=temp1->next;
        //     temp2=temp2->next;
        //    }

        //    return NULL;

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            temp1=temp1==NULL?headB:temp1->next;
            temp2=temp2==NULL?headA:temp2->next;
        }
        return temp1;

    }
};