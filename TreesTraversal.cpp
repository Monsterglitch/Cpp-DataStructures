#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

node* newnode(int val) {
    node* Node = new node();
    Node->data = val;
    Node->left = Node->right = NULL;
}

void inorder(struct node* Node) {
    if(Node == NULL){return;}
    inorder(Node->left);
    cout<<Node->data<<" ";
    inorder(Node->right);
}
void preorder(struct node* Node) {
    if(Node == NULL){return;}
    cout<<Node->data<<" ";
    preorder(Node->left);
    preorder(Node->right);
}
void postorder(struct node* Node) {
    if(Node == NULL){return;}
    postorder(Node->left);
    postorder(Node->right);
    cout<<Node->data<<" ";
}
int main() {
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    int n;
    cout<<"Enter your choice,\n1) Pre-Order, 2) In-Order, 3) Post Order: ";cin>>n;
    switch(n){
        case 1:
            preorder(root);break;
        case 2:
            inorder(root);break;
        case 3:
            postorder(root);break;
    }
    return 0;    
}
