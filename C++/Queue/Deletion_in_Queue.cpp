// Here goes the following algorithm that tells us how to dequeue / delete elements from a queue.

// Let’s say the queue is actually built in a linked list. Here we have used a predefined linkedlist that us available inside C++ Standard template library (List in STL), and made a class where there is a member variable of that type.
// Now Queue is first in first out. So the popping out or deletion of elements will be dine in the front of the list.  You can obtain that differently in C too.
// That means, if the queue is empty, we have to show that the queue is empty and you cannot print anything from an empty queue, because it is empty of elements.
// Otherwise we will simply pop the element from the front of the list and deallocate the memory from there (If it is not a static queue).

#include<bits/stdc++.h>
using namespace std;

class Queue
{
  public:
  list<int> L;
  // Function to insert the element in the queue
  void Push(int i)
  {
    cout<<“Pushing the element : “<<(i)<<endl;
    L.push_back(i);
  }
  // Function to remove the element from the queue
  int pop()
  {
    if(L.empty()) {cout<<“The queue is empty”<<endl;}
    int a=L.front();
    L.pop_front();
    cout<<“Popping the last element : “<<a<<endl;
    return a;
  }
  // Function to display the queue
  void Show()
  {
    cout<<“The present queue is:”<<endl;
    for(auto i:L)
    cout<<i<<” “;
    cout<<endl;
  }
};

int main()
{
  Queue q;
  q.Push(2);q.Push(9);q.Push(3);
  q.Show();q.pop();
  q.Push(5);
  q.pop();q.pop();
  q.Show();
}  
