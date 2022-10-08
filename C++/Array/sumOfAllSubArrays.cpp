#include<iostream>
using namespace std;

int main(){
    int n, sum=0, currSum=0;
    cout<< "Enter the no. of values to be entered into array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the individual elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n\t arr[" <<i <<"]: ";
        cin>> arr[i];    
    } 

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currSum+=arr[j]
        }
        cout<<"\nCurrent sum of Subarray is: " <<currSum;
        sum+=currSum;        
    }
    cout<<"\nSum of all Subarray is: " << sum;

    return 0;
}