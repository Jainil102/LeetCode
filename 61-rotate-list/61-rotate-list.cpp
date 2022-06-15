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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        
        if(n == k || n == 0 || n == 1 || k == 0 || k%n == 0){
            return head;
        }
        else if(n < k){
            k = k%n;
        }
        
        k = n - k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=0; i<k; i++){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = NULL;
        temp = curr;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        head = curr;
        return head;
    }
};