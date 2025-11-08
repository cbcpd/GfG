
using VI = vector<int>;

class Solution {
  public:
    int dfs(int i, int j, int k, vector<VI> &mat, vector<vector<VI>> &memo,
            vector<pair<int,int>> &dirs) {

        int r = mat.size(), c = mat[0].size();

        if (i == r - 1 && j == c - 1)
            return int(mat[i][j] == k);

        if (i == r || j == c || k < 0)
            return 0;

        if (memo[i][j][k] != -1)
            return memo[i][j][k];

        int total = 0;
        for (auto &[x,y] : dirs)
            total += dfs(i + x, j + y, k - mat[i][j], mat, memo, dirs);

        return memo[i][j][k] = total;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {0,1}};
        vector<vector<VI>> memo(n, vector<VI> (m, VI (k + 1, -1)));
        return dfs(0, 0, k, mat, memo, dirs);
    }
};