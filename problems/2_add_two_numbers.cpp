//Problem: https://leetcode.com/problems/add-two-numbers/
//Difficulty: Medium

// Basic (O(n))
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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode results(0);
        ListNode *current = &results;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int l1_val = 0;
            if (l1 != nullptr)
            {
                l1_val = l1->val;
                l1 = l1->next;
            }
            int l2_val = 0;
            if (l2 != nullptr)
            {
                l2_val = l2->val;
                l2 = l2->next;
            }
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;
            int result_val = sum%10;
            
            current->next = new ListNode(result_val);
            current = current->next;

        }
        return results.next;
    }
};
