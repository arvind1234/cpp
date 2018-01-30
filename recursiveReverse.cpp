#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

void recursiveReverse(Node** headRef);

Node * newNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtFront(Node** headRef, int data) {
    Node *_newNode = newNode(data);

    if (!*headRef) {
        // cout << "\n Inserting first node:" << data;
        *headRef = _newNode;
    } else {
        // cout << "\n Inserting middle node:" << data;
        _newNode->next = *headRef;
        *headRef = _newNode;
    }
}

void printList(Node *head) {
    cout << endl;
    while(head) {
        cout << head->data;
        head = head->next;
        if (head) {
            cout << "->";
        }
    }

    cout << endl;
}

void reverse(Node **headRef) {
    Node *curr = *headRef;
    if (!curr || !curr->next) {
        return;
    }

    Node *tempNext, *tail = NULL;

    while(curr) {
        tempNext = curr->next;
        curr->next = tail;
        tail = curr;
        curr = tempNext;
    }

    *headRef = tail;
}

void recursiveReverse(Node** headRef) {
    if (!*headRef || !(*headRef)->next) {
        return;
    }

    Node *curr = *headRef;
    Node *rest = (*headRef)->next;

    recursiveReverse(&rest);

    curr->next->next = curr;
    curr->next = NULL;
    *headRef = rest;

    // cout << "curr:" << curr->data << "rest:" << rest->data;
}

void insertNth(Node **headRef, int n, int data) {
    if (n == 0) {
        insertAtFront(headRef, data);
        return;
    }

    int i = 0;
    Node *curr = *headRef;
    while(curr) {
        if (i == n - 1) break;

        i++;
        curr = curr->next;
    }

    // && i <= n - 1
    if (!curr) {
        cout << "index too far" << endl;
    } else {
        // cout << ((curr == NULL) ? "curr is null" : "curr is not null") << endl;
        Node *_newNode = newNode(data);
        _newNode->next = curr->next;
        curr->next = _newNode;
    }
}

int main() {
    int count = 5;
    // cout << "\nEnter number of nodes:";
    // cin >> count;

    Node *head = NULL;

    while(count > 0) {
        insertAtFront(&head, count);
        count--;
    }

    printList(head);
    recursiveReverse(&head);
    printList(head);
    reverse(&head);
    printList(head);

    cout << "\nInserting -1 at 0:";
    insertNth(&head, 0, -1);
    printList(head);
    cout << "\nInserting 6 at 6:";
    insertNth(&head, 6, 6);
    printList(head);
    cout << "\nInserting 7 at 7:";
    insertNth(&head, 7, 7);
    printList(head);
    cout << "\nInserting 8 at 8:";
    insertNth(&head, 8, 8);
    printList(head);
    cout << "\nInserting 10 at 10:";
    insertNth(&head, 10, 10);
}