#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
// searching in BST
void search(int num, struct node* temp) {
    if(temp == NULL) {
        cout<<"Tree is Empty";
    }
    else if(num < temp->data) {
        search(num, temp->left);
    }
    else if(num > temp->data) {
        search(num, temp->right);
    }
    else {
        cout<<"Element is Found"<<endl;
        return;
    }
}
// insert a value in BST
struct node* insertion(int val, struct node* temp) {
    if(temp == NULL) {
        struct node* tmp = new node();
        tmp->data = val;
        tmp->right = tmp->left = NULL;
    }
    else if(val < temp->data) {
        temp->left = insertion(val, temp->left); 
    }
    else if(val > temp->data) {
        temp->right = insertion(val, temp->right);
    }
    return temp;
}
// deleting in BST
struct node* deletion(int num, struct node* temp) {
    if(temp == NULL) {
        cout<<"Element is not Found";
        return temp;
    }
    else if(temp->data < num) {
        temp->right = deletion(num, temp->right);
    }
    else if(temp->data > num) {
        temp->left = deletion(num, temp->left);
    }
    else {
        if(temp->left == NULL) {
            struct node* tmp = temp->right;
            free(temp);
            return tmp;
        }
        if(temp->right == NULL) {
            struct node* tmp = temp->left;
            free(temp);
            return tmp;
        }
        struct node* tmp = findMin(temp->right);
        temp->data = tmp->data;
        temp->right = deletion(temp->data, temp->right);
    }
    return temp;
}
// find Min in BST
struct node* findMin(struct node* temp) {
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
// struct node* findMax(struct node* temp) {
//     if(temp->right != NULL) {
//         findMax(temp->right);
//     }
//     else {
//         return temp;
//     }
// }
// find Max in BST
struct node* findMax(struct node* temp) {
    while(temp->right != NULL) {
        temp = temp->right;        
    }
    return temp;
}
// inorder in BST
void inorder(struct node* temp) {
    if(temp != NULL) {
        inorder(temp);
        cout<<temp->data;
        inorder(temp);
    }
}
// preorder in BST
void preorder(struct node* temp) {
    if(temp != NULL) {
        cout<<temp->data;
        preorder(temp);
        preorder(temp);
    }
}
// postorder in BST
void postorder(struct node* temp) {
    if(temp != NULL) {
        postorder(temp);
        postorder(temp);
        cout<<temp->data;
    }
}
