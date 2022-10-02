// Give an algorithm for finding the maximum element in binary tree without recursion.

#include <climits>
#include <iostream>
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

int findmax(node *root)
{

    node *temp;
    int max = INT_MIN;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (max < temp->data)
        {
            max = temp->data;
        }

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    return max;
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

    cout << "Max - " << findmax(root);

    return 0;
}