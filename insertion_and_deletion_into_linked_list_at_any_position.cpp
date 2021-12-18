#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    friend class SinglyList;
};

class SinglyList
{
private:
    Node *head;

public:
    SinglyList()
    {
        head = NULL;
    }
    void append(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node(data);
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertData(int data, int pos)
    {
        Node *temp = head, *new_node = new Node(data);
        if (pos == 1)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        while (temp->next && pos > 2)
        {
            temp = temp->next;
            pos--;
        }
        if (pos > 2 || pos < 2)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void deleteNode(int pos)
    {
        Node *temp = head;
        if (pos == 1 && head)
        {
            head = head->next;
            return;
        }

        while (temp->next && temp->next->next && pos > 2)
        {
            temp = temp->next;
            pos--;
        }
        // cout<<pos<<endl;
        if (pos > 2 || pos < 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        temp->next = temp->next->next;
    }
};

int main()
{

    SinglyList list;

    list.append(1);
    list.append(2);
    list.append(4);
    cout << "Before Insertion: ";
    list.print();
    cout << "After Insertion: ";
    list.insertData(3, 2);
    list.print();
    list.append(6);
    cout << "Before Deletion: ";
    list.print();
    list.deleteNode(2);
    cout << "After Deletion: ";
    list.print();
    return 0;
}