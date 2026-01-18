
class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        const auto n{int(arr.size())};
        vector<int> ret(n,-1);
        unordered_map<int,int> h{};
        for(int i: arr)++h[i];
        unordered_set<int> seen{};
        stack<int> st{};
        int i{n-1};
        while(i>=0){
            while(!st.empty() and h[arr[i]]>=h[arr[st.top()]]){
                st.pop();
            }
            if(!st.empty()){
                ret[i]=arr[st.top()];
            }
            st.push(i);
            --i;
        }
        return ret;
    }
};

//GFG POTD solution for 18 January
