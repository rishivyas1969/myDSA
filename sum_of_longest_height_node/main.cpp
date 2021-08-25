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

void sumHeightUtil(Node *root, int sum, int len, int &maxlen, int &maxsum)
{
    if(root==NULL)
    {
        if(maxlen<len)
        {
            maxlen=len;
            maxsum=sum;
        }
        else if(maxlen==len && maxsum<sum)
            maxsum=sum;
        return;
    }

    sumHeightUtil(root->left, sum+(root->data), len+1, maxlen, maxsum);
    sumHeightUtil(root->right, sum+(root->data), len+1, maxlen, maxsum);
}

int sumHeight(Node *root)
{
    if(root==NULL)
        return 0;
    int maxsum=INT_MIN, maxlen=0;
    sumHeightUtil(root, 0, 0, maxlen, maxsum);
    return maxsum;
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

    cout << sumHeight(root);
    return 0;
}
