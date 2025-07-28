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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* start = head;
        ListNode* second = head->next;
        while (second->next) {
            ListNode* startTemp = start;
            start = second;
            ListNode* secondTemp = second;
            second = second->next;
            secondTemp->next = startTemp;
        }
        second->next = start;
        head->next = nullptr;
        head = second;
        return head;
    }
};