
class Solution {
  public:
    void backtrack(vector<int>& arr, vector<bool>& visited,
                    vector<int>& curr,  vector<vector<int>>& result) {

    // If current permutation is complete, add it to the result
    if (curr.size() == arr.size()) {
        result.push_back(curr);
        return;
    }

    // Iterate through the array to build permutations
    for (int i = 0; i < arr.size(); i++) {

        // Skip already visited elements
        if (visited[i]) continue;

        // Skip duplicates: if arr[i] == arr[i-1] and i-1 wasn't used
        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) continue;

        // Choose arr[i]
        visited[i] = true;
        curr.push_back(arr[i]);

        // Recurse to build the next part of the permutation
        backtrack(arr, visited, curr, result);

        // remove last element and unmark it as visited
        curr.pop_back();
        visited[i] = false;
    }
}

// Function to return all unique permutations
vector<vector<int>> uniquePerms(vector<int>& arr) {

    // Sort the array
    sort(arr.begin(), arr.end());

    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> visited(arr.size(), false);

    // Start backtracking to generate permutations
    backtrack(arr, visited, curr, result);
    
    return result;
}
};