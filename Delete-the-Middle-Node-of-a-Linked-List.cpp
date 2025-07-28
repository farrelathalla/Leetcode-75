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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        int len = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            len++;
        }
        int count = 0;
        ListNode* first = head;
        ListNode* second = head->next;
        while (count < len/2-1) {
            first = first->next;
            second = second->next;
            count++;
        }
        first->next = second->next;
        return head;
    }
};