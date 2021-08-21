#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int sum(Node *root)
{
    if(root==NULL)
        return 0;
    return (sum(root->left) + root->data + sum(root->right));
}

int toSumTree(Node *root)
{
    int ls, rs;

    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 1;

    ls=sum(root->left);
    rs=sum(root->right);

    if(root->data == ls+rs && toSumTree(root->left) && toSumTree(root->right))
        return 1;

    return 0;
}

int main()
{
//            11
//          /   \
//         4     3
//       /   \
//      4
//    /
//   0
    Node * root = new Node(11);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//    root->left->left->left = new Node(0);
    if(toSumTree(root))
        cout << "Tree is a Sum Tree.";
    else
    cout << "Tree is not a Sum Tree.";
    return 0;
}
