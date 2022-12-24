/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void copy(Node *head){
            Node *curr = head;
            Node *n = curr->next;
            while(curr != NULL ){
            Node *copyElem = new Node(curr -> val);
            curr -> next = copyElem;
            copyElem -> next = n;
            curr = n;
            if(n != NULL){
                n = n->next;
            }
        }
    }
    
    void random(Node *head){
        Node *curr = head;
        while(curr != NULL){
            if(curr -> random != NULL){
            curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
    }
    
    Node *detach(Node *head){
        Node *curr = head;
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        while(curr != NULL){
            tail -> next = curr -> next ;
            tail = tail -> next ;
            curr -> next = tail -> next;
            curr = curr -> next;
        }
        return dummy -> next;
    }
    
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        copy(head);
        random(head);
        return detach(head);
    }
};
