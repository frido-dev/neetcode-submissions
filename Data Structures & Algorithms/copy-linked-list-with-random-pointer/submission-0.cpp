/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* head1 = new Node(head->val);
        mp.insert({head, head1});

        Node* pointerNode = head;
        Node* curr = head1;

        while(pointerNode->next != NULL) {
            pointerNode = pointerNode->next;
            Node* newNode = new Node(pointerNode->val);
            curr->next = newNode;
            curr = curr->next;
            mp.insert({pointerNode, curr});
        }

        pointerNode = head;
        curr = head1;

        while(pointerNode != NULL) {
            if (pointerNode->random != NULL) {
                curr->random = mp[pointerNode->random];
            }

            pointerNode = pointerNode->next;
            curr = curr->next;
        }

        return head1;
    }
};
