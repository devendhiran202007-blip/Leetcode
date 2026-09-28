class Solution {
public:
    string reverseParentheses(string s) {
          int n=s.size();
         stack<string>st;
          for(auto p:s){
                if(p=='('||p>='a'&&p<='z') st.push(string(1,p));
                else {
                    string temp="";
                    while(!st.empty()&&st.top()!="("){
                           temp+=st.top();
                           st.pop();
                    }
                    st.pop();
             reverse(temp.begin(),temp.end());
                    st.push(temp);
                }
          } 
          string ans;
          while(!st.empty()) {
               ans+=st.top();
               st.pop();
          }
        reverse(ans.begin(),ans.end());
          return ans;
    }
};