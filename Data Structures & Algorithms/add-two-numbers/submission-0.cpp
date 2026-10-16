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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return dfs(l1,l2, 0);
    }
    ListNode *dfs(ListNode *l1, ListNode *l2, int carry){
        if(l1 == nullptr && l2 == nullptr && carry == 0){ return nullptr; }
        int v1 = 0, v2 = 0;
        if(l1){ v1 = l1->val; }
        if(l2){ v2 = l2->val; }
        int sum = v1+v2+carry;
        ListNode *nextNode = dfs(
            l1?l1->next: nullptr,
            l2?l2->next: nullptr,
            sum/10
        );
        return new ListNode(sum%10, nextNode);
    }
};
