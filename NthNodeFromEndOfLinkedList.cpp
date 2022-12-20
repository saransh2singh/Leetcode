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
        if(head==NULL){
            return head;
        }
        ListNode *curr = head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        if(len<n){
            return head;
        }
        if(len==n){
            ListNode *temp = head;
            head = head -> next;
            delete(temp);
            return head;
        }
        curr = head;
        for(int i=1;i<(len-n);i++){
            curr = curr -> next;
        }
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
            return head;
    }
};
