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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        vector<int> arr1;
        vector<int> arr2;
        ListNode* temp = head;
        while(slow && temp){
            arr1.push_back(slow -> val);
            arr2.push_back(temp -> val);
            //if(slow -> next)
            slow = slow -> next;
            //else break;
            //if(temp -> next)
            temp = temp -> next;
            //else break;
        }
        int ans = 0;
        reverse(arr2.begin(), arr2.end());
        for(int i = 0; i < arr1.size(); i++){
            ans = max(ans, arr1[i] + arr2[i]);
        }
        return ans;
    }
};