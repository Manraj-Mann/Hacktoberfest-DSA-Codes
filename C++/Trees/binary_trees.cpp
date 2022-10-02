#include <iostream>
using namespace std;

// This program introduces just to the basic structure of the tree

struct node
{
    int data;
    node *left;
    node *right;
};

node * init(int data)
{
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->left = NULL;
    return n;
}
void insert_left(node *root , int data)
{   
    root->left = init(data);

}
void insert_right(node *root , int data)
{   
    root->right = init(data);
}

void delete_left(node * root  ){

    node * todel = root->left;
    root->left = NULL;
    delete todel;
}
void delete_right(node * root  ){

    node * todel = root->right;
    root->right = NULL;
    delete todel;
}


int main()
{
    node * root = init(1); // root node

    //       1

    insert_left(root , 2);
    insert_right(root , 3);

    //        1
    //       / \'
   //       2   3

    insert_left(root->left , 4);
    insert_right(root->left , 5);

    //        1
    //       / \'
   //       2   3
  //       / \'
   //     4   5

   cout<<root->data<<"\n";

   cout<<root->left->data<<"\n";
   cout<<root->right->data<<"\n";

   cout<<root->left->left->data<<"\n";
   cout<<root->left->right->data<<"\n";
   
   cout<<root->right->left->data<<"\n";
   cout<<root->right->right->data<<"\n";


    return 0;
}