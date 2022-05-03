#include <iostream>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* first = NULL;

void create(int A[], int n) {
    struct Node *p, *last;

    p = new struct Node;
    p->data = A[0];
    p->next = p->prev = NULL;
    first = p;
    last = first;

    for (int i = 1; i < n; i++) {
        p = new struct Node;
        p->data = A[i];
        last->next = p;
        p->prev = last;
        p->next = NULL;
        last = p;
    }
}

int countNodes() {
    int count = 0;
    struct Node* p = first;
    while (p) {
        count++;
        p = p->next;
    }

    return count;
}

void insertNodeATPos(int data, int pos) {
    struct Node *p = first, *q;
    if (pos > countNodes()) {
        std::cout << "Invalid Position: " << pos << std::endl;
    }

    if (pos == 0) {
        q = new struct Node;
        q->data = data;
        q->prev = NULL;
        q->next = first;
        first = q;
        return;
    }

    if (pos == countNodes()) {
        while (p->next) p = p->next;
        q = new struct Node;
        q->data = data;
        q->next = NULL;
        q->prev = p;
        p->next = q;
        return;
    }
    p = first;
    for (int i = 0; i < pos; i++) p = p->next;

    q = new struct Node;
    q->data = data;
    q->next = p;
    q->prev = p->prev;
    p->prev = q;
    q->prev->next = q;

    return;
}

void deleteNodeAtPos(int pos) {
    if (pos > countNodes()) {
        std::cout << "Invalid Position: " << pos << std::endl;
    }
    struct Node *p = first, *q;
    if (pos == 0) {
        first = first->next;
        if (first) first->prev = NULL;
        delete p;
        return;
    }
    if (pos == countNodes() - 1) {
        while (p->next) p = p->next;
        p->prev->next = NULL;
        delete p;
        return;
    }
    for (int i = 0; i < pos; i++) p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    return;
}

void reverse() {
    struct Node *p = first, *q;
    while (p) {
        q = p->next;
        p->next = p->prev;
        p->prev = q;
        p = p->prev;
        if ((p != NULL) && (p->next == NULL)) first = p;
    }
}

// Finding middle node in a linked list (same logic works for single linked
// list)
/*
   Move p by 1 position and q by 2 positions, when q reaches NULL, p is at the
   middle of the list
*/

struct Node* findMiddle() {
    struct Node *p = first, *q = first;
    while (q) {
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }
    return p;
}

void display() {
    struct Node* p = first;
    while (p) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

void freeNodes() {
    struct Node *p = first, *q;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    first = NULL;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    std::cout << "Display after create: ";
    display();

    std::cout << "Node Count: " << countNodes() << std::endl;
    std::cout << "Insert at Position : ";
    insertNodeATPos(31, 5);
    display();
    std::cout << "Delete at Position : ";
    deleteNodeAtPos(5);
    display();

    std::cout << "Reverse: ";
    reverse();
    display();

    std::cout << "Middle Node: " << findMiddle()->data << std::endl;

    freeNodes();
}