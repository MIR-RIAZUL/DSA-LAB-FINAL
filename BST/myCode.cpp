#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left, *right;
};

node *main_root = NULL;

node *createNode(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node *searchNthNode(node *root,int key)
{
    if(root==NULL || root->data==key)
    {
        return root;
    }
    else if (root->data<key)
    {
        return searchNthNode(root->right,key);
    }
    else if (root->data>key)
    {
        return searchNthNode(root->left,key);
    }
    
    
}

node *insertNode(node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    else if (root->data < key)
    {
        root->right = insertNode(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = insertNode(root->left, key);
    }
    return root;
}

// this is inorder traversal

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root !=NULL)
    {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root !=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    main_root = insertNode(main_root, 6);
    insertNode(main_root, 4);
    insertNode(main_root, 7);
    insertNode(main_root, 2);
    insertNode(main_root, 5);
    insertNode(main_root, 8);
    insertNode(main_root, 3); 

    cout << "inorder traversal: "; 
    inorder(main_root);
    cout<<endl;
    cout<<"preorder traversal: ";
    preorder(main_root);
    cout<<endl;

    cout<<"post order traversal: ";
    postorder(main_root);

    int key=5;

    node*result= searchNthNode(main_root,key);

    if(result !=NULL)
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }
}