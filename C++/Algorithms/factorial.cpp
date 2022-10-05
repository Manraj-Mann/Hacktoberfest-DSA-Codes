#include<iostream>

using namespace std;

main()
{
    int i,f=1,x;

    cin>>x;

    for(i=1;i<=x;i++)
    f=f*i;

    cout<<"Factorial:"<<f;
}
