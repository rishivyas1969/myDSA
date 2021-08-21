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

bool checkLeafUtil(Node *root, int level, int *leafLevel)
{
    if(root==NULL)
        return true;

    if( root->left==NULL && root->right==NULL)
    {
        if(*leafLevel==0)
        {
            *leafLevel = level;
            return true;
        }

        return (level == *leafLevel);
    }

    return (checkLeafUtil(root->left, level+1, leafLevel) && checkLeafUtil(root->right, level+1, leafLevel));
}

int checkLeaf(Node *root)
{
    int leafLevel=0, level=0;
    return checkLeafUtil(root, level, &leafLevel);
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
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//    root->left->left->left = new Node(6);
    if(checkLeaf(root))
        cout << "Leaf on same level." ;
    else
        cout << "Leaf not on same level." ;
    return 0;
}
