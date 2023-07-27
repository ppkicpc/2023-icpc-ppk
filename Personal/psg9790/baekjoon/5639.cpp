#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;

    void PostOrder()
    {
        if (left != nullptr)
            left->PostOrder();
        if (right != nullptr)
            right->PostOrder();
        cout << value << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Node *root = new Node;
    Node *curNode = root;

    int val;
    cin >> val;
    root->value = val;

    while (cin >> val)
    {
        Node *newNode = new Node;
        newNode->value = val;

    RETRY:
        if (newNode->value > curNode->value)
        {
            if (curNode->right == nullptr)
            {
                curNode->right = newNode;
                newNode->parent = curNode;
                // cout << curNode->value << " -> " << newNode->value << '\n';

                continue;
            }
            else
            {
                curNode = curNode->right;
                // cout << "curNode change " << curNode->value << '\n';
                goto RETRY;
            }
        }

        if (newNode->value < curNode->value)
        {
            if (curNode->left == nullptr)
            {
                curNode->left = newNode;
                newNode->parent = curNode;
                // cout << curNode->value << " -> " << newNode->value << '\n';
                continue;
            }
            else
            {
                curNode = curNode->left;
                // cout << "curNode change " << curNode->value << '\n';
                goto RETRY;
            }
        }
    }

    root->PostOrder();
}