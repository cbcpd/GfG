/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int>mp;
        queue<pair<int,Node*>>q;
        
        q.push({0,root});
        
        while(!q.empty()){
            int level=q.front().first;
            Node* curr=q.front().second;
            mp[level]=curr->data;
            q.pop();
            
            if(curr->left)q.push({level-1,curr->left});
            
            if(curr->right)q.push({level+1,curr->right});
        }
        
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
