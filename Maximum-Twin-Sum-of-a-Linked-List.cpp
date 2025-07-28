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
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            len++;
        }
        int half = len/2;
        vector<int> sum(half, 0);
        int count = 0;
        while (head) {
            if (count >= half) {
                sum[len-count-1] += head->val;
            } else {
                sum[count] += head->val;
            }
            head = head->next;
            count++;
        }
        int max = 0;
        for (int i = 0; i < half; i++) {
            if (sum[i] > max) max = sum[i];
        }
        return max;
    }
};