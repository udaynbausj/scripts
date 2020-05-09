//
// Created by Uday B K on 06/05/20.
//

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createList(node* head){
    char choice;
    node* n = new node;
    node* temp = nullptr;
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
    return head;
}

void insertAtBeginning(node* head){
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

void insertAtEnd(node* head){
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

void deleteNodeAtGivenPosition(node* head){
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
}

void printList(node* head){
    node* n  = head;
    while(n!=nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
}

void reverse_list(node* head) {
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

node* add_two_lists(node* head1 , node* head2) {
    if (head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }
    node* temp1 = head1 , *temp2 = head2;
    node* new_node , *temp = nullptr, *head = nullptr;
    int carry = 0 , sum = 0;
    while(temp1 != nullptr ||  temp2 != nullptr) {
        if (temp1 != nullptr) {
            sum = sum + temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != nullptr) {
            sum = sum + temp2->data;
            temp2 = temp2->next;
        }
        sum = sum + carry;
        new_node = new node();
        new_node->data = sum%10;
        new_node->next = nullptr;
        if (head == nullptr) {
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
        carry = sum / 10;
        sum=0;
    }
    if (carry != 0) {
        new_node = new node();
        new_node->data = carry;
        temp->next = new_node;
        temp = new_node;
    }
    return head;
};

int main(){
    node* head1 = nullptr;
    node* head2 = nullptr;
    head1 = createList(head1);
    head2 = createList(head2);
    node* head = add_two_lists(head1 , head2);
    reverse_list(head);
    printList(head);
}