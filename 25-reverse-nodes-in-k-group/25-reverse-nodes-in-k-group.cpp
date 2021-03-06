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
        ListNode* prevHead = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        ListNode* nextHead;
        
        int n = 0;
        ListNode* t = head;
        while(t!=NULL){
            t = t->next;
            n++;
        }
        int c = n/k;
        
        while(c>0){
            nextHead = curr;
            for(int i=1; i<=k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(c == n/k){
                head = prev;
            }
            else{
                prevHead->next = prev;
            }
            prevHead = nextHead;
            c--;
        }
        prevHead->next = curr;
        return head;
    }
};