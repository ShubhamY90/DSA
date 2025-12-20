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
        ListNode* oddHead = NULL;
        ListNode* oddList = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int i = 1;
        while(curr){
            if(i % 2 == 0){
                ListNode* temp = curr;
                if(prev){
                    prev -> next = temp -> next;
                    //temp -> next = NULL;
                }
                else{
                    //temp -> next = NULL;
                    head = curr -> next;
                }
                curr = curr->next;
                temp -> next = NULL;
                if(oddList){
                    oddList -> next = temp;
                    oddList = oddList -> next;
                }
                else{
                    oddHead = temp;
                    oddList = oddHead;
                }
            }
            else {
                // keep curr
                prev = curr;
                curr = curr->next;
            }
            i++;
            // prev = curr;
            // curr = curr -> next;
        }
        
        if(head){
            prev -> next = oddHead;
            return head;
        }
        return oddHead;
    }
};