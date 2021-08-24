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

bool check(Node *root, Node *root2)
{
    if(root==NULL && root2==NULL)
        return true;

    if(root==NULL || root2==NULL)
        return false;

    if(root->data == root2->data && check(root->right, root2->left) && check(root->left, root2->right))
        return true;
}

int main()
{
//            1
//          /   \
//         2     3
//       /   \
//      4     5
//    /
//   6
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(9);

    Node * root2 = new Node(1);
    root2->right = new Node(2);
    root2->left = new Node(3);
    root2->right->right = new Node(4);
    root2->right->left = new Node(5);
    root2->right->right->right = new Node(6);

    if(check(root, root2))
        cout << "Mirrored.";
    else
        cout << "Naah.";
    return 0;
}
