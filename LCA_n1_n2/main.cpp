#include <iostream>
#include <vector>

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

bool makePath(Node *root, vector<int> &path, int n1)
{
    if(root==NULL)
        return false;

    path.push_back(root->data);

    if(root->data==n1)
        return true;

    if( (root->left && makePath(root->left, path, n1) ) || (root->right && makePath(root->right, path, n1)))
        return true;

    path.pop_back();
    return false;
}

int findDescendant(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if( !makePath(root, path1, n1) || !makePath(root, path2, n2))
        return -1;

    int i;
    for(i=0 ; i<path1.size() && i<path2.size() ; i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
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
    root->left->left->left = new Node(6);

    cout << findDescendant(root, 4, 3);
    return 0;
}
