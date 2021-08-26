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

void printPath(vector<int> &path, int j)
{
    int i;
    for(i=j ; i<path.size() ; i++)
        cout << path[i] << " ";
    cout << endl;
}

void printKPathUtil(Node *root, vector<int> &path, int k)
{
    if(root==NULL)
        return;

    path.push_back(root->data);

    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);

    int f=0;
    for(int j=path.size()-1 ; j>=0 ; j--)
    {
        f+=path[j];

        if(f==k)
            printPath(path, j);
    }
    path.pop_back();
}

void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
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
    Node * root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    printKPath(root, 5);
    return 0;
}
