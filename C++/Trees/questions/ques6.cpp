// Give an algorithm for finding the size of binary tree.

#include <climits>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *init(int data)
{
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert_left(node *root, int data)
{
    root->left = init(data);
}
void insert_right(node *root, int data)
{
    root->right = init(data);
}

void delete_left(node *root)
{

    node *todel = root->left;
    root->left = NULL;
    delete todel;
}
void delete_right(node *root)
{

    node *todel = root->right;
    root->right = NULL;
    delete todel;
}

// Recursive

int sizeoftree(node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return sizeoftree(root->left) + 1 + sizeoftree(root->right);
    }
}

// Iterative

int sizeoftree_(node * root){

    node *temp;
    queue<node*> q;
    int count = 0;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        count++;
        
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }    
    }

    return count;
    
  
}
int main()
{
    node *root = NULL;

    root = init(1); // root node

    //       1

    insert_left(root, 2);
    insert_right(root, 3);

    //        1
    //       / \'
    //      2   3

    insert_left(root->left, 4);
    insert_right(root->left, 5);

    //        1
    //       / \'
    //      2   3
    //      / \'
    //     4   5

    insert_left(root->right, 6);
    insert_right(root->right, 7);

    //        1
    //       / \'
    //       2   3
    //      / \' / \'
    //     4   5 6  7

    cout << "size = " << sizeoftree(root)<<endl;
    cout << "size = " << sizeoftree_(root->left)<<endl;

    return 0;
}