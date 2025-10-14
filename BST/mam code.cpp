#include <iostream>
using namespace std;

// Create a Binary Search Tree structure
struct node
{
    int data;
    node *left, *right;
};

// Create node
node *createNode(int value)
{
    node *temp; // declare a node
    temp = new node();
    temp->data = value; // assign data
    temp->left = NULL;  // any new node that we create, will have no children
    temp->right = NULL;
    return temp; // return new node
}

node *main_root = NULL; // initially root points to NULL to signify an empty BST

// Search for a node which contains the value "key"
node *searchNode(node *root, int key)
{
    if (root == NULL || root->data == key) // if key is found or if we have reached the end of tree, return that node
        return root;
    if (key < root->data) // if key is lesser than root, search the left subtree of root
        return searchNode(root->left, key);
    if (key > root->data) // if key is greater than root, search the right subtree of root
        return searchNode(root->right, key);
}

// Find minimum value from a BST
node *minimumValue(node *root)
{
    while (root->left != NULL) // The leftmost value is the minimum value
        root = root->left;
    return root;
}

// Find maximum value from a BST
node *maximumValue(node *root)
{
    while (root->right != NULL) // The rightmost value is the maximum value
        root = root->right;
    return root;
}

// Insert a node in the BST
node *insertNode(node *root, int key)
{
    if (root == NULL) // if tree is empty, just create a new node with "key"
        return createNode(key);

    if (key < root->data) // if "key" to be inserted is lesser than the parent, insert in left subtree
        root->left = insertNode(root->left, key);
    else if (key > root->data) // if "key" to be inserted is greater than the parent, insert in right subtree
        root->right = insertNode(root->right, key);
    return root;
}

// Traverse BST in inorder traversal
void inorder(node *root) // l->p->r
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traverse BST in preorder traversal
void preorder(node *root) // p->l->r
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traverse BST in postorder traversal
void postorder(node *root) // l->r->p
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Delete node having "key"
node *deleteNode(node *root, int key)
{
    // If the tree is empty, return root
    if (root == NULL)
        return root;

    // Find node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // If node has 0 or 1 child
        if (root->left == NULL)
        {
            node *temp = root->right; // if node has no left child, it will be replaced by its right child
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left; // if node has no right child, it will be replaced by its left child
            delete root;
            return temp;
        }
        // Node has both children
        node *temp;
        // temp = minimumValue(root->right); // Replacing deleted node with minimum value of Right Subtree
        temp = maximumValue(root->left); // Replacing deleted node with maximum value of Left Subtree
        root->data = temp->data;
        // root->right = deleteNode(root->right, temp->data); // delete the node with minimum value from node's Right Subtree
        root->left = deleteNode(root->left, temp->data); // delete the node with minimum value from node's Right Subtree
    }
    return root;
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

    cout << "\ninorder" << endl;
    inorder(main_root);
    cout << "\npreorder" << endl;
    preorder(main_root);
    cout << "\npostorder" << endl;
    postorder(main_root);

    cout << "\nThe node value " << searchNode(main_root, 5)->data << " is found" << endl;

    main_root = deleteNode(main_root, 3);
    cout << "\ninorder" << endl;
    inorder(main_root);

    main_root = deleteNode(main_root, 4);
    cout << "\ninorder" << endl;
    inorder(main_root);
    cout << endl;
}