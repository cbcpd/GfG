
class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        int n = s.size();
        bool ans = false;
        
        stack<char>st;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){
                st.push(s[i]);
            } else if(s[i] == ')'){
                bool operation = false;
                while(!st.empty() && st.top()!='('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        operation = true;
                    }
                    st.pop();
                }
                if(!st.empty())st.pop();
                if(!operation)ans = true;
            }
        }
        
        return ans;
    }
};

