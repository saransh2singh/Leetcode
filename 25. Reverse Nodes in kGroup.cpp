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
        ListNode *checker = head;
        for(int i=1;i<=k;i++){
            if(checker == NULL){
                return head;
            }
            checker = checker -> next;
        }
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        int count = 1;
        while(curr != NULL && count<=k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL){
            ListNode *newwhead = reverseKGroup(next,k);
            head -> next = newwhead;
        }
        return prev;
    }
};
