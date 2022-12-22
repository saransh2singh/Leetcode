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
    bool hasCycle(ListNode *head) {
        ListNode *temp = new ListNode(0);
        ListNode *curr = head;
        while( curr != NULL ){
            if(curr -> next == NULL){
            return false;
        }
        if( curr -> next == temp ){
            return true;
        }
            ListNode * next = curr -> next;
            curr -> next = temp;
            curr = next;
        }
        return false;
    }
};
