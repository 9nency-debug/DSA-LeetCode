class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> Groups = nums;
        sort(Groups.begin(), Groups.end());
        unordered_map<int, vector<int>> Group;
        unordered_map<int, int> Belong;
        unordered_map<int, int> Minindex;
        int id = 1;
        Group[id].push_back(Groups[0]);
        for (int i = 1; i < n; i++) {
            if (Groups[i] - Groups[i - 1] > limit) {
                id++;
            }
            Group[id].push_back(Groups[i]);
        }
        id = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && Groups[i] - Groups[i - 1] > limit) {
                id++;
            }
            Belong[Groups[i]] = id;
        }
        for (int i = 1; i <= id; i++) {
            Minindex[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int groupId = Belong[nums[i]];
            nums[i] = Group[groupId][Minindex[groupId]];
            Minindex[groupId]++;
        }
        return nums;
    }
};