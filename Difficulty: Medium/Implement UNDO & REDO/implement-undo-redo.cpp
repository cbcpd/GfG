
class Solution {
    stack<char> st;
    stack<char> redoSt;

public:
    void append(char x) {
        st.push(x);
        // new action clears redo history
        while (!redoSt.empty()) redoSt.pop();
    }

    void undo() {
        if (!st.empty()) {
            redoSt.push(st.top());
            st.pop();
        }
    }

    void redo() {
        if (!redoSt.empty()) {
            st.push(redoSt.top());
            redoSt.pop();
        }
    }

    string read() {
        stack<char> temp = st;
        string ans;
        while (!temp.empty()) {
            ans += temp.top();
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};