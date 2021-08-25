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

int findSumUtil(Node *root, int &sum)
{
    if(root==NULL)
        return 0;

    int curr = root->data + findSumUtil(root->left, sum) + findSumUtil(root->right, sum);

    sum = max(sum, curr);

    return curr ;
}

int findSum(Node *root)
{
    if(root==NULL)
        return 0;
    int sum=INT_MIN;
    findSumUtil(root, sum);
    return sum;
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
    root->right = new Node(-3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    cout << findSum(root);
    return 0;
}
