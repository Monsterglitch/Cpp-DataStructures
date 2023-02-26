#include<iostream>
using namespace std;

// structure of AVL
struct node {
    int data;
    struct node *left, *right;
    int height;
};
// left Rotation in AVL
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T = y->left;
    x->right = T;
    y->left = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
// right Rotation in AVL
struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T = x->right;
    x->right = y;
    y->left = T;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return x;
}
// height of a node
int height(struct node* temp) {
    if(temp == NULL) {
        return 0;
    }
    else return temp->height;
}
// balance of a node
int getbalance(struct node* temp) {
    if(temp == NULL){
        return 0;
    }
    else return height(temp->left) - height(temp->right);
}
// maximum of two values
int max(int a, int b) {
    return a>b ? a : b;
}
// searching in AVL
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
// insert a value in AVL
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
        temp->right = (val, temp->right);
    }
    temp->height = 1 + max(height(temp->left), height(temp->right));
    int balance = getbalance(temp);
    if(balance > 1 && val < temp->left->data) {
        return rightRotate(temp);
    }
    if(balance > 1 && val > temp->left->data) {
        temp->left = leftRotate(temp);
        return rightRotate(temp);
    }
    if(balance < -1 && val > temp->right->data) {
        return leftRotate(temp);
    }
    if(balance < -1 && val <temp->right->data) {
        temp->right = rightRotate(temp);
        return leftRotate(temp);
    }
    return temp;
}
// deleting in AVL
struct node* deletion(int num, struct node* temp) {
    if(temp == NULL) {
        cout<<"Element is not Found";
        return temp;
    }
    else if(temp->data < num) {
        temp->right = (num, temp->right);
    }
    else if(temp->data > num) {
        temp->left = (num, temp->left);
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
    temp->height = 1 + max(height(temp->left), height(temp->right)); 
    int balance = getbalance(temp);
    if(balance > 1 && getbalance(temp->left) >= 0) {
        return rightRotate(temp);
    }
    if(balance > 1 && getbalance(temp->left) < 0) {
        temp->left = leftRotate(temp);
        return temp->right;
    }
    if(balance < -1 && getbalance(temp->right) <= 0) {
        return leftRotate(temp);
    }
    if(balance < -1 && getbalance(temp->right) > 0) {
        temp->right = rightRotate(temp);
        return leftRotate(temp);
    }
    return temp;
}
// finding Minimum value in AVL
struct node* findMin(struct node* temp) {
    while(temp != NULL) {
        temp = temp->left;
    }
    return temp;
}
// finding Maximum value in AVL
struct node* findMax(struct node* temp) {
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
    
}
// inorder in AVL
void inorder(struct node* temp) {
    if(temp != NULL) {
        inorder(temp);
        cout<<temp->data;
        inorder(temp);
    }
}
// preorder in AVL
void preorder(struct node* temp) {
    if(temp != NULL) {
        cout<<temp->data;
        preorder(temp);
        preorder(temp);
    }
}
// postorder in AVL
void postorder(struct node* temp) {
    if(temp != NULL) {
        postorder(temp);
        postorder(temp);
        cout<<temp->data;
    }
}
