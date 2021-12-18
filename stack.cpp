#include <bits/stdc++.h>

using namespace std;

class Node{
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
    friend class Stack;
};

class Stack {
private:
    Node *head;
public:
    Stack() {
        head = NULL;
    }
    void push(int data){
        if(head == NULL) {
            head = new Node(data);
            return;
        }
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    bool isEmpty() {
        if(head == NULL) return true;
        return false;
    }
    int top() {
        return head->data;
    }
    void pop() {
        head = head->next;
        return;
    }
};

void printStack(Stack s) {
    while(!s.isEmpty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    printStack(s);

    return 0;
}