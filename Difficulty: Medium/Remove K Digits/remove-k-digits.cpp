
class Solution {
  public:
    string removeKdig(string &num, int k) {
        stack<char> st;

        for (char ch : num) {
            while (!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k> 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') idx++;

        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;
    }
};