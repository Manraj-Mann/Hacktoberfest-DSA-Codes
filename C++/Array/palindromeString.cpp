#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    char test[n+1];
    cin>>test;

    for (int i = 0; i<=(n)/2; i++)
    {
        if(test[i]!=test[n-1-i]){
            cout<<"Given testcase is not a palindrome.";
            n=0;
            break;
        }
    }
    if(n!=0){
        cout<<"Given testcase is a palindrome.";
    }


    return 0;
}