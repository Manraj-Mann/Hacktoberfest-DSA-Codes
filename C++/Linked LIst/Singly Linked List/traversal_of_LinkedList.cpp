#include <iostream>
using namespace std;

typedef struct Admission
{
    int clas ;
    int rollno;
    string name;
    Admission * next;
}   LinkedList ;


int Traverse( LinkedList * head){

    int count  = 0;
    LinkedList * current = head;
    while (current != NULL)
    {
        cout<<" Name - "<<current->name<<endl;
        cout<<" Class - "<<current->clas<<endl;
        cout<<" Roll no - "<<current->rollno<<endl;

        current = current->next;

        cout<<"--------------------------------------------------------\n";
        count++;
    }
    return count;

 //   Time Complexity: O(n), for scanning the list of size n.
 //   Space Complexity: O(1), for creating a temporary variable.
    
}
int main(){


    // Majorly this is impelemtation in c in c++ it will be uite smooth

    LinkedList *  ad_data;

    LinkedList node1, node2 , node3 , node4;

   ad_data = &node1;

    node1.clas = 9;
    node1.rollno = 9;
    node1.name = "Ankita";
    node1.next = &node2;

    node2.clas = 9;
    node2.rollno = 32;
    node2.name = "Manraj";
    node2.next = &node3;

    node3.clas = 9;
    node3.rollno = 9;
    node3.name = "Ankita";
    node3.next = &node4;

    node4.clas = 9;
    node4.rollno = 32;
    node4.name = "Manraj";
    node4.next = NULL;

    int Traverse_ = Traverse(ad_data);

    cout<<" Total nodes are "<<Traverse_;

   
    


    
return 0;
}