/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/


class Solution {
  public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node *prev = nullptr, *curr = head, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Reverse both lists to start from least significant digit
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* sum = NULL;
        int carry = 0;

        // Traverse both lists until all digits and carry are processed
        while (head1 != NULL || head2 != NULL || carry != 0) {
            int newVal = carry;

            if (head1) {
                newVal += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                newVal += head2->data;
                head2 = head2->next;
            }

            carry = newVal / 10;
            newVal %= 10;

            // Insert the new digit at the front of the result list
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
        }

        // Remove leading zeros, if any
        while (sum != NULL && sum->data == 0) {
            Node* temp = sum;
            sum = sum->next;
            delete temp;
        }

        // If result is empty, return single node with 0
        if (sum == NULL) {
            return new Node(0);
        }
        return sum;
    }
};