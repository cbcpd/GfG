
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> ans;
        if (arr1.empty() || arr2.empty() || k == 0) return ans;

        using T = pair<int, pair<int,int>>; // {sum, {i, j}}
        priority_queue<T, vector<T>, greater<T>> q;
        set<pair<int,int>> seen;

        q.push({arr1[0] + arr2[0], {0, 0}});
        seen.insert({0, 0});

        while (!q.empty() && (int)ans.size() < k) {
            auto [sum, idx] = q.top();
            q.pop();
            int i = idx.first, j = idx.second;

            ans.push_back({arr1[i], arr2[j]});

            if (i + 1 < arr1.size() && !seen.count({i + 1, j})) {
                q.push({arr1[i + 1] + arr2[j], {i + 1, j}});
                seen.insert({i + 1, j});
            }

            if (j + 1 < arr2.size() && !seen.count({i, j + 1})) {
                q.push({arr1[i] + arr2[j + 1], {i, j + 1}});
                seen.insert({i, j + 1});
            }
        }

        return ans;
    }
};
