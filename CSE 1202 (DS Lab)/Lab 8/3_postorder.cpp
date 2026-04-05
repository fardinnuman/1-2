#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTreeFromFile(string filename)
{
    ifstream file(filename);
    int l[100], r[100], v[100];
    Node *nodes[101];
    int n = 0;

    while (true)
    {
        int li, vi, ri;
        file >> li >> vi >> ri;
        if (li == -1 && vi == -1 && ri == -1)
            break;
        l[n] = li;
        v[n] = vi;
        r[n] = ri;
        n++;
    }

    for (int i = 1; i <= n; i++)
        nodes[i] = new Node(v[i - 1]);
    for (int i = 1; i <= n; i++)
    {
        if (l[i - 1] != 0)
            nodes[i]->left = nodes[l[i - 1]];
        if (r[i - 1] != 0)
            nodes[i]->right = nodes[r[i - 1]];
    }

    return nodes[1];
}

void postorder(Node *root)
{
    if (!root)
        return;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    Node *root = buildTreeFromFile("file.txt");
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}