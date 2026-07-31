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
        if(head == nullptr) return nullptr;
        ListNode* prev = nullptr;
        ListNode* after = head->next;
        while(after != nullptr) {
            head->next = prev;
            prev = head;
            head = after;
            after = after->next; 
        }
        head->next = prev;
        return head;

    }
};