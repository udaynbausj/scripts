//
// Created by Uday B K on 06/05/20.
//

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head;
void printList();

void createList(){
    char choice;
    node* n = new node;
    node* temp;
    do{
        if(head== nullptr){
            cout<<"\nEnter the data into the head : ) ";
            cin>>n->data;
            n->next = nullptr;
            head = n;
            temp = head;
        }else{
            cout<<"\nEnter the data to place in node : ";
            node* n = new node;
            cin>>n->data;
            n->next = nullptr;
            temp->next = n;
            temp = n;
        }
        cout<<"\nDo you want to add more nodes ? ";
        cin>>choice;
    }while(choice!='n');
}

void insertAtBeginning(){
    char choice;
    do{
        node* n = new node;node* temp;
        if(head==nullptr){
            cout<<"\nHead is Null : ), so pushing data to head .";
            cout<<"\nEnter data to insert at head : ";
            cin>>n->data;
            n->next = nullptr;
            head = n;
            temp = head;
        }else{
            cout<<"\nEnter tha data to insert at beginning : ";
            cin>>n->data;
            n->next = head;
            head = n;
        }
        cout<<"\nDo you want to enter more sat beginnig ? ";
        cin>>choice;
    }while(choice!='n');
}

void insertAtEnd(){
    char choice;
    do{
        node* n = new node;
        node* temp;
        if(head== nullptr){
            cout<<"\nHead node is null :";
            cout<<"\nEnter the data to insert at head : ";
            cin>>n->data;
            n->next = nullptr;
            head = n;
            temp = head;
        }else{
            cout<<"\nEnter the data to insert at end of linkedlist : )";
            cin>>n->data;
            n->next = nullptr;
            temp = head;
            while(temp->next!= nullptr){
                temp = temp->next;
            }
            //now temp->next will be pointing at the NULL;
            //temp will be the last node
            temp->next = n;
        }
        cout<<"\nDo you want to enter more ? ";
        cin>>choice;
    }while(choice!='n');
}

void deleteNodeAtGivenPosition(){
    cout<<"Enter the position to delete the node : ";
    int position;cin>>position;
    //position is index+1;
    node* prev = head,*curr = head;
    position--;
    while(position--){
        prev = curr;
        curr = head->next;
    }
    cout<<"\nDeleted node is  : "<<curr->data;
    prev->next = curr->next;
    curr->next = nullptr;
    free(curr);
    printList();
}

void printList(){
    node* n  = head;
    while(n!=nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
}

void reverse_list() {
    if (head == nullptr)
        return;
    node* prev , *curr;
    prev = head;
    head = head->next;
    curr = head;
    prev->next = nullptr;
    while(head != nullptr) {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    head = prev;
}

int main(){
    createList();
    printList();
    insertAtBeginning();
    printList();
    insertAtEnd();
    printList();
    reverse_list();
    printList();
    deleteNodeAtGivenPosition();
}