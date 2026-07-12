class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        int r = 1;
        for(int num : s) {
            rank[num] = r++;
        }
            vector<int> ans;
            for(int num : arr) {
                ans.push_back(rank[num]);
            }
            return ans;
    }
};