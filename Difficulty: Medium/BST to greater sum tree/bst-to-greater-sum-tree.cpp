/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/


class Solution {
    private:
    void solve(Node* root, int &sum)
    {
        
        if(root==nullptr) return;
        solve(root->right,sum);
        
        int ori_val=root->data;
        root->data=sum;
        sum+=ori_val;
        
        solve(root->left,sum);
        
    }
  public:
    void transformTree(Node *root) {
        // code here
        int sum=0;
        solve(root, sum);
    }
};