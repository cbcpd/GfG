/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int>v;
    void fn(Node* root){
        if(root==NULL)return;
        v.push_back(root->data);
        fn(root->left);
        fn(root->right);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        if(root==NULL)return {};
        fn(root);
        sort(v.begin(),v.end());
        vector<int>ans;
        int idx=lower_bound(v.begin(),v.end(),target)-v.begin();
        int n=v.size();
        int i=idx-1;
        int j=idx;
        while((int)ans.size()<k){
             if(i<0){
                ans.push_back(v[j]);
                j++;
            }
            else if(j>=n){
                ans.push_back(v[i]);
                i--;
            } 
            else{
                if(abs(v[i]-target)<=abs(v[j]-target)){
                    ans.push_back(v[i]);
                    i--;
                } 
                else{
                    ans.push_back(v[j]);
                    j++;
                }
            }
        }
        return ans;
    }
};