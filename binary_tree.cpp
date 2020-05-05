//
// Created by Uday B K on 05/05/20.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
};

Node* new_node(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = n->right = nullptr;
    return n;
}

void print_vector(vector<int>&container) {
    for (int i : container) {
        cout<<i<<"\n";
    }
}

void print_in_order(Node* root) {
    if (root== nullptr)
        return;
    print_in_order(root->left);
    cout<<root->data<<"\n";
    print_in_order(root->right);
}

void print_pre_order(Node* root) {
    if (root == nullptr)
        return;
    cout<<root->data<<"\n";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void print_post_order(Node* root) {
    if (root == nullptr)
        return;
    print_post_order(root->left);
    print_post_order(root->right);
    cout<<root->data<<"\n";
}

int height_of_tree(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(height_of_tree(root->left) , height_of_tree(root->right));
}

void print_level_order_recursion_util(Node* root , int level) {
    if (root == nullptr)
        return;
    if (level == 1) {
        cout<<root->data<<" ";
    } else if (level > 1) {
        print_level_order_recursion_util(root->left,level-1);
        print_level_order_recursion_util(root->right,level-1);
    }
}

void print_level_order_recursion(Node* root) {
    int height = height_of_tree(root);
    for (int i = 1 ; i <= height ; i++ ) {
        print_level_order_recursion_util(root,height);
        cout<<"\n";
    }
}

void print_level_order(Node* root) {
    if (root == nullptr)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        if (current->left!= nullptr)
            q.push(current->left);
        if (current->right!= nullptr)
            q.push(current->right);
    }
}

int main() {

}