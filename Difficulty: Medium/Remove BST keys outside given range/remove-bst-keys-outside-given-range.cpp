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
  Node* fun(Node *root, int l, int r){
        if(!root)
          return NULL;
          
        Node *ans = NULL;
        if(((root->data) >= l) && ((root->data) <= r)){
          ans = root;
          ans->left = fun(root->left, l, r);
          ans->right = fun(root->right, l, r);
          return ans;
        }
        else if((root->data) < l){
            ans = fun(root->right, l, r);
            return ans;
        }
        else if((root->data) > r){
            ans = fun(root->left, l, r);
            return ans;
        }
        
        return ans;
    }
    Node* removekeys(Node* root, int l, int r) {
        // code here
         return fun(root, l, r);
    }
};