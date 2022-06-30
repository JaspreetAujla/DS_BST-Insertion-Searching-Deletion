#include <iostream>  
using namespace std;  
struct Branch {  
    int data;  
    Branch *left;  
    Branch *right;  
};  
Branch* create(int item)  
{  
    Branch* branch = new Branch;  
    branch->data = item;  
    branch->left = branch->right = NULL;  
    return branch;  
}  

void inorder(Branch *root)  
{  
    if (root == NULL)  
        return;  
    inorder(root->left);  
    cout<< root->data << "   ";   
    inorder(root->right); 
}  
Branch* least(Branch* current)   
{  
    while(current->left != NULL) {  
        current = current->left;  
    }  
    return current;  
}  
Branch* insertion(Branch* root, int item) 
{  
    if (root == NULL)  
        return create(item);  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  
void search(Branch* &current, int item, Branch* &parent)  
{  
    while (current != NULL && current->data != item)  
    {  
        parent = current;  
        if (item < current->data)  
            current = current->left;  
        else  
            current = current->right;  
    }  
}  
void deletion(Branch*& root, int item)  
{  
    Branch* parent = NULL;  
    Branch* current = root;  
    search(current, item, parent); 
    if (current == NULL)  
        return;  
    if (current->left == NULL && current->right == NULL)   
    {  
        if (current != root)  
        {  
            if (parent->left == current)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
        free(current);       
    }  
    else if (current->left && current->right)  
    {  
        Branch* succ  = least(current->right);  
        int val = succ->data;  
        deletion(root, succ->data);  
        current->data = val;  
    }  
    else  
    {  
        Branch* child = (current->left)? current->left: current->right;  
        if (current != root)  
        {  
            if (current == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
        else  
            root = child;  
        free(current);  
    }  
}  
int main()  
{  
  Branch* root = NULL;  
  root = insertion(root, 42);  
  root = insertion(root, 33);  
  root = insertion(root, 60);  
  root = insertion(root, 48);  
  root = insertion(root, 63);  
  root = insertion(root, 26);  
   
  printf("The inorder traversal of the given binary tree is - \n");  
  inorder(root);  
  deletion(root, 26);  
  printf("\n\nAfter deleting node 26 - \n");  
  inorder(root);   
  insertion(root, 72);  
  printf("\n\nAfter inserting node 72 - \n");  
  inorder(root);  
  return 0;  
}  