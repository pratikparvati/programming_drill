#include <iostream>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->S = new int[st->size];
}

void Display(struct Stack st) {
    for (int i = st.top; i >= 0; i--) {
        std::cout << st.S[i] << ' ';
    }
    std::cout << std::endl;
}

void push(struct Stack *st, int x) {
    if (st->top == st->size - 1) {
        std::cout << "Stack Overflow\n";
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if (st->top == -1) {
        std::cout << "Stack Underflow\n";
    } else {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int idx) {
    int x = -1;
    if (st.top - idx < 0) {
        std::cout << "Invalid Index\n";
    }
    x = st.S[st.top - idx + 1];
    return x;
}

int isEmpty(struct Stack st) {
    if (st.top == -1) return 1;
    return 0;
}

int isFull(struct Stack st) {
    if (st.top == st.size - 1) return 1;
    return 0;
}

int stackTop(struct Stack st) {
    if (!isEmpty(st)) return st.S[st.top];
    return -1;
}

int main() {
    struct Stack st;
    create(&st, 5);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    std::cout << "After pushing 5 elements to stack: ";
    Display(st);
    std::cout << "Pop an element: " << pop(&st) << std::endl;
    std::cout << "Stack elemets after pop: ";
    Display(st);
    std::cout << "peek at: " << peek(st, 3) << std::endl;
    std::cout << "Is empty: " << isEmpty(st) << std::endl;
    std::cout << "Is full: " << isFull(st) << std::endl;
    std::cout << "Stack top: " << stackTop(st) << std::endl;
    return 0;
}
