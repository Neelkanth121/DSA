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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        ListNode* temp = head;
        for(int i=0;i<n;i++) {
            fastptr = fastptr->next;
        }
        while(fastptr != nullptr) {
            fastptr = fastptr->next;
            temp = slowptr;
            slowptr = slowptr->next;
        }
        temp->next = slowptr->next;
        if(temp == slowptr) return head->next;
        return head;
    }
};