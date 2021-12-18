#include <bits/stdc++.h>

using namespace std;

class Node {
private:
    int data;
    Node *next;
public:
    Node() {
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        next = NULL;
    }
    friend class Queue;
};

class Queue {
private:
    Node *head, *trail;
public:
    Queue() {
        head = NULL;
        trail = NULL;
    }
    void enQueue(int data) {
        if(head == NULL) {
            head = new Node(data);
            trail = head;
            return;
        }
        trail->next = new Node(data);
        trail = trail->next;
    }
    bool isEmpty() {
        if(head == NULL) return true;
        return false;
    }
    void deQueue() {
        head = head->next;
    }
    int front() {
        return head->data;
    }
};

void printQueue(Queue q) {
    while(!q.isEmpty()) {
        cout<<q.front()<<" ";
        q.deQueue();
    }
}

int main() {

    Queue q;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);

    printQueue(q);

    return 0;
}