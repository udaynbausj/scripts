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

void diagonal_traversal_util(Node* root , map<int,vector<int>>&mp , int level) {
    if (root == nullptr) {
        return;
    }
    mp[level].push_back(root->data);
    diagonal_traversal_util(root->right , mp , level);
    diagonal_traversal_util(root->left , mp , level+1);
}

map<int , vector<int>> diagonal_traversal(Node* root){
    map<int,vector<int> >mp;
    diagonal_traversal_util(root , mp , 0);
    for (auto & iter : mp) {
        for (int i = 0 ; i < iter.second.size() ; i++ ) {
            cout<<iter.second[i]<<" ";
        }cout<<"\n";
    }
    return mp;
};

void print_left_boundary(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr) ) {
        return;
    }
    cout<<root->data<<"\n";
    print_left_boundary(root->left);
    if (root->left == nullptr) {
        print_left_boundary(root->right);
    }
}

void print_leaves(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr &&  root->right == nullptr) {
        cout<<root->data<<" ";
    }
    print_leaves(root->left);
    print_leaves(root->right);
}

void root_to_leaf_path_util(Node* root , vector<vector<int> >&paths , vector<int>current) {
    if (root == nullptr) {
        return;
    }
    current.push_back(root->data);
    if ((root->left == nullptr && root->right == nullptr)) {
        paths.push_back(current);
    }
    root_to_leaf_path_util(root->left , paths , current);
    root_to_leaf_path_util(root->right , paths, current);
}

vector<vector<int>> root_to_leaf_paths(Node* root) {
    vector<vector<int> >paths;
    vector<int>current;
    root_to_leaf_path_util(root , paths , current);
    for (auto & path : paths) {
        for (int j : path) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return paths;
}

int main() {
    Node* root = new_node(20);
    root->left = new_node(8);
    root->left->left = new_node(4);
    root->left->right = new_node(12);
    root->left->right->left = new_node(10);
    root->left->right->right = new_node(14);
    root->right = new_node(22);
    root->right->right = new_node(25);
    root_to_leaf_paths(root);
}