
class Solution {
  public:
  void p(vector<int>&arr, vector<int>&pge){
      stack<int>st;
      int n = arr.size();
      for(int i=0;i<n;i++){
          while(!st.empty()&& arr[st.top()]<arr[i]) {
              st.pop();
          }
          int t = st.empty()?-1:st.top();
          pge.push_back(t);
          st.push({i});
      }
      return;
  }
  void n(vector<int>&arr, vector<int>&nge){
      stack<int>st;
      int n = arr.size();
      for(int i=n-1;i>=0;i--){
          while(!st.empty()&& arr[st.top()]<arr[i]) {
              st.pop();
          }
          int t = st.empty()?n:st.top();
          nge.push_back(t);
          st.push({i});
      }
      reverse(nge.begin(),nge.end());
      return;
  }
    int maxPeople(vector<int> &arr) {
        // code here
        int ans = INT_MIN;
        vector<int>pge;
        vector<int>nge;
        p(arr,pge);
        n(arr,nge);
        int n = arr.size();
        for(int i=0;i<n;i++) {
            int left = i-pge[i];
            int right = nge[i]-i;
            int totalVisible = nge[i] - pge[i] - 1;
            ans= max(ans,totalVisible);
        }
        return ans;
        //nge
        //pge
        
    }
};