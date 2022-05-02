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

void display() {
    struct Node* p = first;
    while (p) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    std::cout << "Display after create: ";
    display();

    std::cout << "Node Count: " << countNodes();
}