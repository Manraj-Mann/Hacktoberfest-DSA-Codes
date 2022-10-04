#include<bits/stdc++.h>
using namespace std;
// creating a queue using list
class Queue
{
  public:
  list<int> L;
  void Push(int i) //adding elements
  {
    cout<<“Pushing the element : “<<(i)<<endl;
    L.push_back(i);
  }
  int pop() //pop/delete used to remove elements
  {
    if(L.empty()) {cout<<“The queue is empty”<<endl;}
    int a=L.front();
    L.pop_front();
    cout<<“Popping the last element : “<<a<<endl;
    return a;
  }
  void Show() //printing the queue
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