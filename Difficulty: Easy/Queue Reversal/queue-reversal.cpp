
class Solution {
  public:
    void reverseQueue(queue<int> &que) {
        // code here
        if(que.empty()) {
            return;
        }
        int curr = que.front();
        que.pop();
        reverseQueue(que);
        que.push(curr);
    }
};