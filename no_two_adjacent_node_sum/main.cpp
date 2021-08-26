#include <iostream>
#include <map>

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

int getMaxSum(Node *root, map<Node*, int> m);

int getmaxSumGrand(Node *root, map<Node*, int> &m)
{
    int sum = 0;

    if(root->left)
        sum += getMaxSum(root->left->left, m) + getMaxSum(root->left->right, m);

    if(root->right)
        sum += getMaxSum(root->right->left, m) + getMaxSum(root->right->right, m);

    return sum;
}

int getMaxSum(Node *root, map<Node*, int> m)
{
    if(root==NULL)
        return 0;

    if(m.find(root) != m.end())
        return m[root];

    int incl = root->data + getmaxSumGrand(root, m);

    int excl = getMaxSum(root->left, m) + getMaxSum(root->right, m);

    m[root] = max(incl, excl);

    return m[root];
}

int sumOfNoTwoAdjacent(Node *root)
{
    if(root==NULL)
        return 0;

    map<Node*, int> m;
    return getMaxSum(root, m);
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

    cout << sumOfNoTwoAdjacent(root);
    return 0;
}
