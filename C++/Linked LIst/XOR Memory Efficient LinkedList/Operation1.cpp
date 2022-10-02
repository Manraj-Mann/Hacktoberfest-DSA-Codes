#include <iostream>
using namespace std;
typedef struct LL
{
    int data;
    LL *ptrdiff;

} ll;

LL *head = NULL, *tail = NULL;

ll *xor_opr(ll *a, ll *b)
{
    return (ll *)((uintptr_t)a ^ (uintptr_t)b); // unsigned integer type capable of holding a pointer
}

void traverse(ll *head, int type)
{
        ll * current;
        ll * prev = NULL, *next;

    cout << "Items are : ";
    if (type == 1) // same order printing
    {
         current = head;
       
        while (current != NULL)
        {
            cout << current->data << " ";
            next = xor_opr(prev, current->ptrdiff);
            prev = current;
            current = next;
        }
    }
    else if(type == 2) { // reverse order printing 

        current = tail;

         while (current != NULL)
        {
            cout << current->data << " ";
            next = xor_opr(prev, current->ptrdiff);
            prev = current;
            current = next;
        }

    }

    cout << endl;
}

// Method 1 - using head and tail for insertion and deletion

void insert(int data, bool at_last)
{
     //     if at_last - true = insert at last
    //        - false = insert at first

    ll *newnode = new ll;
    newnode->data = data;

    if (head == NULL) // If list is empty
    {
        // cout<<"1st executed\n";

        newnode->ptrdiff = NULL;
        head = tail = newnode;

        // cout<<" head = "<<head<<" tail = "<<tail;

        return;
    }
    if (at_last) // If the element is to be inseted at last
    {
        //  cout<<"2nd executed\n";

        newnode->ptrdiff = xor_opr(tail, NULL);
        tail->ptrdiff = xor_opr(newnode, xor_opr(tail->ptrdiff, NULL));
        tail = newnode;
    }
    else
    { 
        // If insetion is a top
        //  cout<<"3rd executed\n";

        newnode->ptrdiff = xor_opr(NULL, head);
        head->ptrdiff = xor_opr(newnode, xor_opr(NULL, head->ptrdiff));
        head = newnode;
    }

}

void remove_(bool from_tail){

    ll * ptr;
    if (head == NULL)
    {
        cout<<"Empty List\n";
        return;
    }

    if (from_tail) // Removing the ladt node 
    {
        ptr = tail;

        ll * prev = xor_opr(ptr->ptrdiff , NULL); // getting prev node 

        if (prev == NULL)    // if there is only one node in the list
        {
            head = NULL; // deleting the node 
        }
        else {            // if above is false and there are more than 1 node 

            // making the prev node to point the null or the node after the last node is removed which is null

            prev->ptrdiff = xor_opr(ptr , xor_opr(prev->ptrdiff ,NULL ));  

            tail = prev;   // shifted tail 
        }
        
    }
    else{       // removing the very first node

        ptr = head;

        ll* next = xor_opr(NULL , ptr->ptrdiff); // getting the next node

        if (next == NULL) // If there is only one node 
        {
            tail = NULL; // deleting the last remaining node 
        }
        else{
              // making the next node to point the next node in list as next node will now have the null and its usual  node in xor

            next->ptrdiff = xor_opr(ptr , xor_opr(NULL , next->ptrdiff));

            head = next;
        }
        
    }

    delete ptr;
     
    
    
}


int main()
{

    insert(1, 0);
    traverse(head , 1);
    insert(2, 1);
    traverse(head, 1);
    insert(0, 0);
    traverse(head, 1);
    remove_(1);
    traverse(head, 1);
    traverse(head, 2);
    remove_(0);
    traverse(head, 1);
 

    return 0;
}

// These results are based on the above implementation :

// ----------------- Insertion ----------------------//

// Worst case time complexity: Θ(1)
// Average case time complexity: Θ(1)
// Best case time complexity: Θ(1)
// Space complexity: Θ(1)

// --------------------------------------------------//


// ----------------- Deletion ----------------------//

// Worst case time complexity: Θ(1)
// Average case time complexity: Θ(1)
// Best case time complexity: Θ(1)
// Space complexity: Θ(1)

// --------------------------------------------------//


// ----------------- Display ------------------------//

// Worst case time complexity: Θ(n)
// Average case time complexity: Θ(n)
// Best case time complexity: Θ(n)
// Space complexity: Θ(1)

// --------------------------------------------------//