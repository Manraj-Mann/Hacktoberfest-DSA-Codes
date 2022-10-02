// Give an algorithm for finding maximum element in binary tree.

#include <climits>
#include <iostream>
#include <stack>

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

    int rootval, left, right, max = INT_MIN;

    if (root != NULL)
    {
        rootval = root->data;
        left = findmax(root->left);
        right = findmax(root->right);
        //   cout<<"left = "<<left<<endl;
        //    cout<<"right = "<<right<<endl;

        if (left < right)
        {
            max = right;
        }
        else
        {

            max = left;
        }

        if (rootval > max)
        {
            max = rootval;
        }
    }

    // cout<<"returned "<<max<<endl;

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