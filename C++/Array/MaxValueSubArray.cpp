#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    cout<<"\nAll the sub-arrays of the array are: \n";
    int sum=0, maxSum=INT_MIN, ini=0, fin=0;
    cout<<maxSum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k <=j; k++)
            {
                sum+=arr[k];
            }
            if(sum>maxSum){
                maxSum=sum;
                ini=i;
                fin=j;
            }
            sum=0;
        }
    }
    

    cout<<"\nSub-array with maximum sum is: " <<endl;
    for (int i = ini; i <=fin; i++)
    {
        cout<< arr[i] <<"   ";
    }
    cout<<"\nAnd sum of this subarray is: " <<maxSum;
    

    return 0;
}