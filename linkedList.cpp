#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtEnd(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
    void insertAtStart(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void insertAtPos(int d, int pos)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *curr = head;
        int i = 0;
        while (i < pos - 1)
        {
            curr = curr->next;
            i++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = NULL;
    }
    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtPos(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        Node *curr = head;
        int i = 0;
        while (i < pos - 1)
        {
            curr = curr->next;
            i++;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    //searching
    int search(int d){
        Node *curr = head;
        int count =-1;
        while(curr!=NULL){
            count++;
            if(curr->data == d){
                return count;
            }
            else{
                curr = curr->next;
            }
        
        }
        return -1;
    }
};

int main(){
    LinkedList list;
    
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(45);
    list.insertAtEnd(100);
    //list.deleteAtPos(3);
    list.print();
    int result = list.search(120);
    result==-1?cout<<"Data Not Found"<<endl:cout<<"Data found at "<< result<<endl;
}