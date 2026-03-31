//Problem: https://leetcode.com/problems/merge-k-sorted-lists/
//Difficulty: Hard

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b)
    {
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        ListNode* result;
        if (a->val > b->val)
        {
            result = b;
            b = a;
            a = result;
        }
        else
        {
            result = a;
        }

        while (true)
        {
            if (a->next == nullptr)
            {
                a->next = b;
                break;
            }
            else if (b == nullptr)
                break;

            if (a->next->val > b->val)
            {
                ListNode* temp = b->next;
                b->next = a->next;
                a->next = b;
                b = temp;
            }
            else
            {
                a = a->next;
            }
        }
        return result;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result;
        if (lists.size() <= 0)
            return nullptr;

        return mergeRecurs(lists, 0, lists.size() - 1);
    }

    ListNode* mergeRecurs(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeRecurs(lists, left, mid);
        ListNode* l2 = mergeRecurs(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
};