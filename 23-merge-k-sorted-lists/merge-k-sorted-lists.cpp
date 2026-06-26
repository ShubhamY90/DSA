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
        vector<int> arr;
        for(auto l : lists){
            ListNode* temp = l;
            while(temp){
                arr.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        if(arr.size() < 1) return nullptr;
        sort(arr.begin(), arr.end());
        ListNode* head1 = new ListNode(arr[0]);
        ListNode* curr = head1;
        for(int i = 1; i < arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            curr -> next = temp;
            curr = temp;
        }
        return head1;
    }
};