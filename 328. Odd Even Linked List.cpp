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
        ListNode *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
        ListNode * curr = head;
        int count = 1;
        while (curr != NULL){
            if(count % 2 == 0){
                if(es == NULL){
                    es = curr;
                    ee = es;
                }
                else{
                    ee -> next = curr;
                    ee = ee -> next;
                }
            }
            else{
                if(os == NULL){
                    os = curr;
                    oe = os;
                }
                else{
                    oe -> next = curr;
                    oe = oe -> next;
                }
            }
            curr = curr -> next;
            count++;
        }
        if(os == NULL || es == NULL){
            return head;
        }
        oe -> next = es;
        ee -> next = NULL;
        return os;
    }
};
