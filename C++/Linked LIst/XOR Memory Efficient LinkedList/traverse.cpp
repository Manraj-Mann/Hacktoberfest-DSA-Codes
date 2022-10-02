#include <iostream>
using namespace std;
typedef struct LL
{
    int data;
    LL *ptrdiff;
}ll;

ll * xor_opr (ll *a, ll *b)
{
    return (ll*) ((uintptr_t) a ^ (uintptr_t) b);  // unsigned integer type capable of holding a pointer
}

void traverse(ll * head ){

    ll * current = head;
    ll * prev  = NULL , * next;

    cout<<"Items are : ";

    while (current != NULL)
    {
        cout<<current->data<<" ";
        next = xor_opr(prev , current->ptrdiff);
        prev = current;
        current = next;
    }

}

int main()
{

    LL *head;

    LL *node1, *node2, *node3, *node4;

    node1 = new LL;
    node2 = new LL;
    node3 = new LL;
    node4 = new LL;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;

    head = node1;

    node1->ptrdiff = xor_opr(NULL , node2);
    node2->ptrdiff = xor_opr(node1 , node3);
    node3->ptrdiff = xor_opr(node2 , node4);
    node4->ptrdiff = xor_opr(node3 , NULL);

    traverse(head);

    return 0;
}