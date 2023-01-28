#include <iostream>
#include <stack>

using namespace std;

string reverse(string str){
        int s = 0;
        int e = str.size() - 1;
        char temp;
        while(s < e){
            temp = str[s];
            str[s] = str[e];
            str[e] = temp;
            s++;e--;
        }
        return str;
    }
    string removeTheStars(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i<n; i++){
            if(s[i] == '*'){
                if(!st.empty()){
                    st.pop();
                    
                }
            }
            else{
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s = s + st.top();
            
            st.pop();
        } 
        return reverse(s);
    }
int main(){
    string s = "Hel**loWo*rl*d";
    string res = removeTheStars(s);
    cout << res;
}
