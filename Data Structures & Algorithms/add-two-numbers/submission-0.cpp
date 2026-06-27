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
        ListNode* head = new ListNode(0);
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* curr = head;
        int carry = 0;

        while(head1 && head2) {
            int sum = head1->val + head2->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(nodeVal);
            curr->next = newNode;
            curr = curr->next;
            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1) {
            int sum = head1->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(nodeVal);
            curr->next = newNode;
            curr = curr->next;
            head1 = head1->next;
        }

        while(head2) {
            int sum = head2->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(nodeVal);
            curr->next = newNode;
            curr = curr->next;
            head2 = head2->next;
        }

        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = curr->next;
        }

        return head->next;
    }
};
