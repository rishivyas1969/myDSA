#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data ;
    Node *left;
    Node *right;
};

Node* createNode(int val)
    {
        Node *newNode = new Node();
        if(!newNode)
        {
            cout << "\n Error: Memory!";
            return NULL;
        }

        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

Node *insertNode(Node *root, int num)
{
    if(root == NULL )
    {
        root = createNode(num) ;
        return root;
    }

    queue<Node*> q ;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = createNode(num);
            return root;
        }

        if(temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = createNode(num);
            return root;
        }

    }
}

void printTree(Node *root)
{
    if(root == NULL)
        return ;

    cout << root->data << " " ;
    printTree(root->left);
    printTree(root->right);
}

void deleteLastNode(Node *root, Node *lastNode)
{
    queue<Node*> q ;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp == lastNode)
        {
            temp = NULL;
            delete(temp);
            return ;
        }

        if(temp->left)
        {
            if(temp->left == lastNode)
            {
                temp->left = NULL;
                delete(lastNode);
                return;
            }
            else
                q.push(temp->left);
        }
        if(temp->right)
        {
            if(temp->right == lastNode)
            {
                temp->right = NULL;
                delete(lastNode);
                return;
            }
            else
                q.push(temp->right);
        }
    }

}

Node *deletion(Node* root, int num)
{
    if(root == NULL)
        return NULL ;

    if( root->left == NULL && root->left == NULL)
    {
        if(root->data == num)
            return NULL ;
        else
            return root ;
    }

    queue<Node*> q ;
    q.push(root);
    Node *num_node = NULL ;
    Node* temp ;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == num)
            num_node = temp;

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    if(num_node != NULL)
    {
        int x = temp->data;
        deleteLastNode(root, temp);
        num_node->data = x ;
    }
    return root;
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    deletion(root, 5);

    printTree(root);
    return 0;
}
