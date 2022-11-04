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
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }
        
        n = n/k;
        ListNode *prev, *curr, *next, *nextHead, *prevHead;
        curr = head;
        prevHead = head;
        for(int i=0; i<n; i++){
            prev = NULL;
            nextHead = curr;
            for(int j=0; j<k; j++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(i == 0) head = prev;
            else prevHead->next = prev;
            prevHead = nextHead;
        }
        prevHead->next = curr;
        return head;
    }
};