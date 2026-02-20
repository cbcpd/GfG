
class Solution {
  public:
    static bool comp(string a,string b){
        return a+b>b+a;
    }
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> fem;
        for(int i=0;i<arr.size();i++){
            fem.push_back(to_string(arr[i]));
        }
        sort(fem.begin(),fem.end(),comp);
        if(fem[0]=="0"){
            return "0";
        }
        string result="";
        for(auto it:fem){
            result+=it;
        }
        return result;
    }
};