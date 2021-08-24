#include <iostream>
#include <unordered_set>

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

bool hasDuplicateHelper(Node *root, unordered_set<int> &s)
{
    if(root==NULL)
        return false ;
    unordered_set<int>::iterator it = s.find(root->data) ;

    if(it != s.end() )
    {
        return true;
    }

    s.insert(root->data);
    return hasDuplicateHelper(root->left, s) || hasDuplicateHelper(root->right, s);
}

bool hasDuplicate(Node *root)
{
    unordered_set<int> s;
    return hasDuplicateHelper(root, s);


//    unordered_set<int>::iterator it;

//    it = s.find(2);
//    if((it++)!=s.end())
//        cout << *it << "\n";
//
//    for(it=s.begin() ; it!=s.end() ; it++)
//        cout << *it << " " ;
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
    root->left->right = new Node(3);
    root->left->left->left = new Node(6);

    if(hasDuplicate(root))
        cout << "Yeah Duplicate present.";
    else
        cout << "No Duplicate Found!";
    return 0;
}
