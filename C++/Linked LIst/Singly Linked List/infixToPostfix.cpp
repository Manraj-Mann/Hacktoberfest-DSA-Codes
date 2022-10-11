#include<iostream>
#include<cstring>
using namespace std;


class Stack{
    public:
        char *arr;
        int size;
        int top;
        Stack(){
            size=5;
            arr=new char[5];
            top=-1;
        }
        Stack(int size){
            this->size=size;
            arr=new char[size];
            top=-1;
        }
    
        bool isFull(){
            if(top==size-1){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        
        void push(char val){
            if(isFull()){
                cout<<"\nStack Overflow" <<endl;
            }
            else{
                arr[++top]=val;
                cout<<"\n" <<val <<" is Pushed into the Stack" <<endl;
            }
        }

        char pop(){
            if(isEmpty()){
                cout<<"\n\nStack Underflow" <<endl;
                return -1;
            }
            else{
                char val=arr[top--];
                cout<<"\n" <<val <<" is Popped from the Stack" <<endl;
                return val;
            }
        }

        char stackTop(){
            if(isEmpty()){
                cout<<"\n\nStack Underflow" <<endl;
                return -1;
            }
            else{
                char c=arr[top];
                cout<<"\n" <<c <<" is present at top of Stack." <<endl;
                return c;   
            }
        }
};

bool isOperator(char val){
    if(val=='+' || val=='-' || val=='*' || val=='/' || val=='^' || val=='(' || val==')'){
        return true;
    }
    return false;
}

int precedence(char val){
    if(val=='^'){
        return 3;
    }
    else if(val=='*' || val=='/'){
        return 2;
    }
    else if(val=='+' || val=='-'){
        return 1;
    }
    else if(val=='#'){
        return -1;
    }
    else{
        return 0;                   // if(val=='(' || val==')')
    }
}

char* infixToPostfix(char *infix, int len){
    Stack ds(len);
    char *postfix=(char *)malloc(sizeof(char)*len);
    int p=0, i=0;
    ds.push('#');
    while(infix[i]!='\0')
    {
        if(isOperator(infix[i])){
            if(infix[i]=='('){
                ds.push(infix[i++]);
            }
            else if(infix[i]==')'){
                while(ds.stackTop()!='('){
                    postfix[p++]=ds.pop();
                }
                ds.pop();       // to remove '(' the opening parenthesis
            }
            else if(precedence(infix[i]) > precedence(ds.stackTop())){
                ds.push(infix[i++]);
            }
            else{
                postfix[p++]=ds.pop();
            }
        }
        else{
            postfix[p++]=infix[i++];
        } 
        cout<<"\n\n" <<postfix  <<"\ni: " <<i <<endl;  
    }
    while(ds.stackTop()!='#'){
        char c=ds.stackTop();
        if(c=='(' || c==')'){
            ds.pop();
            continue;
        }
        postfix[p++]=ds.pop();
    }   
    postfix[p]='\0';
    return postfix;
}


int main(){

    char infix[50];
    cout<<"\nEnter an infix expression to be converted into postfix \n\t>>";
    cin>>infix;

    int len=strlen(infix);
    
    cout<<"\n\nPostfix expression of above will be: " <<infixToPostfix(infix, len);

    return 0;
}

//  Testcase
// >> (A–(B/C)*D+E)*F+G