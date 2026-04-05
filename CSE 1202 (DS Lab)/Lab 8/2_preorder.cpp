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

void preorder(Node *root)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

int main()
{
    Node *root = buildTreeFromFile("file.txt");
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    return 0;
}