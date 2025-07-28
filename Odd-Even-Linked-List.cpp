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
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode* evenStart = head;
        ListNode* oddStart = head->next;
        ListNode* oddStartTemp = oddStart;
        while (oddStartTemp && oddStartTemp->next) {
            evenStart->next = oddStartTemp->next;
            evenStart = evenStart->next;
            oddStartTemp->next = evenStart->next;
            oddStartTemp = oddStartTemp->next;
        }
        evenStart->next = oddStart;
        return head;
    }
};