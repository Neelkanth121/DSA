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
        if(head->next == nullptr) return nullptr;
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        ListNode* temp = head;
        while((fastptr->next != nullptr) && (fastptr->next->next != nullptr)) {
            fastptr = fastptr->next->next;
            temp = slowptr;
            slowptr = slowptr->next;
        }
        while(fastptr->next != nullptr) {
            fastptr = fastptr->next;
            temp = slowptr;
            slowptr = slowptr->next;
        }
        temp->next = slowptr->next;
        return head;
    }
};