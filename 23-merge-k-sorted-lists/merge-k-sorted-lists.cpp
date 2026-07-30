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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : lists){
            while(it){
                pq.push(it -> val);
                it = it -> next;
            }
        }

        if(!pq.empty()){
            ListNode* ans = new ListNode(pq.top());
            ListNode* temp = ans;
            pq.pop();
            while(!pq.empty()){
                ListNode* curr = new ListNode(pq.top());
                temp -> next = curr;
                temp = curr;
                pq.pop();
            }
            return ans;
        }
        return NULL;
    }
};