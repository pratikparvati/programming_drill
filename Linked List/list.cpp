#include <climits>
#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *second;
struct Node *third;
struct Node *dummy;

void create(int A[], int size) {
    struct Node *new_node, *prev_node;
    first = new struct Node;
    first->data = A[0];
    first->next = NULL;
    prev_node = first;

    for (int i = 1; i < size; i++) {
        new_node = new struct Node;
        prev_node->next = new_node;
        new_node->data = A[i];
        new_node->next = NULL;
        prev_node = new_node;
    }
}

void create2(int A[], int size) {
    struct Node *new_node, *prev_node;
    second = new struct Node;
    second->data = A[0];
    second->next = NULL;
    prev_node = second;

    for (int i = 1; i < size; i++) {
        new_node = new struct Node;
        prev_node->next = new_node;
        new_node->data = A[i];
        new_node->next = NULL;
        prev_node = new_node;
    }
}

void create3(int A[], int size) {
    struct Node *new_node, *prev_node;
    third = new struct Node;
    third->data = A[0];
    third->next = NULL;
    prev_node = third;

    for (int i = 1; i < size; i++) {
        new_node = new struct Node;
        prev_node->next = new_node;
        new_node->data = A[i];
        new_node->next = NULL;
        prev_node = new_node;
    }
}

void display() {
    struct Node *p = first;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void display(struct Node *n_ptr) {
    struct Node *p = n_ptr;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// recursive display
void recursiveDisplay(struct Node *p) {
    if (p != NULL) {
        std::cout << p->data << " ";
        recursiveDisplay(p->next);
    } else {
        std::cout << std::endl;
    }
}

int countNodes() {
    struct Node *p = first;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

// recursive count
int recCountNodes(struct Node *p) {
    if (p == NULL) return 0;
    return 1 + recCountNodes(p->next);
}

int Sum() {
    struct Node *p = first;
    int sum = 0;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recursiveSum(struct Node *p) {
    if (p == NULL) return 0;
    return p->data + recursiveSum(p->next);
}

void freeNodes() {
    struct Node *p = first, *node_to_free;
    while (p) {
        node_to_free = p;
        p = p->next;
        delete node_to_free;
    }
}

int max() {
    struct Node *p = first;
    int mx = INT_MIN;
    while (p) {
        if (p->data > mx) mx = p->data;
        p = p->next;
    }
    return mx;
}

int maxRecursive(struct Node *p) {
    if (p == NULL) return INT_MIN;
    return (p->data > maxRecursive(p->next)) ? p->data : maxRecursive(p->next);
}

int min() {
    struct Node *p = first;
    int mx = INT_MAX;
    while (p) {
        if (p->data < mx) mx = p->data;
        p = p->next;
    }
    return mx;
}

int minRecursive(struct Node *p) {
    if (p == NULL) return INT_MAX;
    return (p->data < minRecursive(p->next)) ? p->data : minRecursive(p->next);
}

struct Node *search(int key) {
    struct Node *p = first;
    while (p) {
        if (p->data == key)
            return p;
        else {
            p = p->next;
        }
    }
    return NULL;
}

struct Node *recursiveSearch(struct Node *p, int key) {
    if (p == NULL) return NULL;
    if (p->data == key) return p;
    return recursiveSearch(p->next, key);
}

// Linear search - Moving the search element to the first element of the linked
// list
struct Node *linearSearch(int key) {
    struct Node *p = first, *q = NULL;
    while (p) {
        if (p->data == key) {
            q->next = p->next;
            p->next = first;
            first = p;
            break;
        }
        q = p;
        p = p->next;
    }
    return p;
}

void insertNode(int data) {
    struct Node *p = new struct Node;
    p->data = data;
    p->next = first;
    first = p;
}

void insertNodeAtPos(int data, int pos) {
    struct Node *p = first, *q = NULL;
    if (pos > countNodes()) {
        std::cout << "Invalid position: " << pos << '\n';
        return;
    }
    for (int i = 0; i < pos - 1; i++) p = p->next;
    q = new struct Node;
    q->data = data;
    q->next = p->next;
    p->next = q;
}

void sortNodes() {
    struct Node *p = first;

    while (p) {
    }
}

bool isSorted() {
    struct Node *p = first;
    int x = INT_MIN;
    while (p != NULL) {
        if (p->data < x) return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

// reverse linked list using sliding pointer
void reverse() {
    struct Node *p = first, *q = NULL, *r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recursiveReverse(struct Node *p, struct Node *q) {
    if (p != NULL) {
        recursiveReverse(p->next, p);
        p->next = q;
    } else {
        first = q;
    }
}

void concatList(struct Node *list1, struct Node *list2) {
    struct Node *p = list1;
    while (p->next) {
        p = p->next;
    }

    p->next = list2;
}

void deleteNode(int pos) {
    struct Node *p = first, *q = NULL;
    if (pos == 0) {
        first = first->next;
        delete p;
        return;
    }
    for (int i = 0; i < pos; i++) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
}

void Merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if (p->data < q->data) {
        dummy = last = p;
        p = p->next;
        dummy->next = NULL;
    } else {
        dummy = last = q;
        q = q->next;
        dummy->next = NULL;
    }
    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {11, 21, 31, 41, 51};
    int C[] = {12, 22, 32, 42, 52};

    create(A, 5);
    create2(B, 5);
    create3(C, 5);
    display();
    recursiveDisplay(first);

    std::cout << "Number of Nodes: " << countNodes() << std::endl;
    std::cout << "Number of Nodes (recursive): " << recCountNodes(first)
              << std::endl;
    std::cout << "Sum of Nodes: " << Sum() << std::endl;
    std::cout << "Sum of Nodes (recursive): " << recursiveSum(first)
              << std::endl;
    std::cout << "Max Value in the Nodes: " << max() << std::endl;
    std::cout << "Max Value in the Nodes (recursive): " << maxRecursive(first)
              << std::endl;
    std::cout << "Min Value in the Nodes: " << min() << std::endl;
    std::cout << "Min Value in the Nodes (recursive): " << minRecursive(first)
              << std::endl;
    std::cout << "Search for key in Nodes: "
              << (search(30) ? "Key found" : "Key not found") << std::endl;
    std::cout << "Search for key in Nodes (recursive): "
              << (recursiveSearch(first, 80) ? "Key found" : "Key not found")
              << std::endl;
    std::cout << "Linear Search for key in Nodes: "
              << (linearSearch(40) ? "Key found" : "Key not found")
              << std::endl;
    display();
    insertNode(70);
    display();
    insertNodeAtPos(80, 2);
    display();
    deleteNode(1);
    display();
    std::cout << "Is sorted? : " << std::boolalpha << isSorted() << '\n';
    std::cout << "reverse: ";
    reverse();
    display();
    std::cout << "reverse (recursive): ";
    recursiveReverse(first, NULL);
    display();
    concatList(first, second);
    std::cout << "concatenate: ";
    display();

    Merge(third, second);
    std::cout << "Merge: ";
    display(second);

    freeNodes();
}