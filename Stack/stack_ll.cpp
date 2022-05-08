#include <iostream>

// Stack using linked list

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *p;
    p = new struct Node;

    if (p == NULL) {
        std::cout << "stack is full\n";
    } else {
        p->data = x;
        p->next = top;
        top = p;
    }
}

int pop() {
    int x = -1;
    if (top == NULL) {
        std::cout << "Stack is empty\n";
    } else {
        struct Node *p;
        p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}

void Display() {
    struct Node *p = top;
    for (int i = 0; p != NULL; p) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    std::cout << "Display elements in stack: ";
    Display();

    pop();

    std::cout << "After Pop: ";
    Display();
    return 0;
}