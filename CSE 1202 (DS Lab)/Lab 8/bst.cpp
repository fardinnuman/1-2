#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);

    return root;
}

Node *minValueNode(Node *node)
{
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

Node *deleteBST(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteBST(root->left, val);
    else if (val > root->data)
        root->right = deleteBST(root->right, val);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    ifstream file("bst.txt");
    int val;

    Node *root = NULL;

    while (file >> val)
    {
        if (val == -1)
            break;
        root = insertBST(root, val);
    }

    cout << "Inorder after insertion: ";
    inorder(root);

    root = deleteBST(root, 50);

    cout << "\nInorder after deletion: ";
    inorder(root);

    return 0;
}

