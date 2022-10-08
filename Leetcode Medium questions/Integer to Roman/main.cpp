class Solution {
public:
   string intToRoman(int num) {
       vector<int> s_in = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
       vector<string> s = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       vector<string> str;
       for(int i = 0; i<s_in.size(); i++){
           while(num >= s_in[i]){
               str.push_back(s[i]);
               num = num - s_in[i];
           }
       }
       
       string ans = "";
       for(auto x: str){
           ans = ans + x;
       }
       
       
       return ans;
       
   }
};