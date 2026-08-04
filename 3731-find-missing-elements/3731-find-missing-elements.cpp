class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        for(int num : nums) {
            st.insert(num);
        }

        // for finding min & max
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        // check_inRange
        for(int i = min; i< max; i++) {
            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// TC: O(n)