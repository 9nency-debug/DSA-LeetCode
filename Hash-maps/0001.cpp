#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Utility function to print unordered_map
void printMap(const unordered_map<int, int> &mp) {
    cout << "{ ";
    for (auto &it : mp) {
        cout << it.first << ":" << it.second << " ";
    }
    cout << "}\n";
}

/*
    1) BASIC HASHMAP OPERATIONS
*/
void basicHashMapOperations() {
    unordered_map<int, int> mp;

    // Insert / Update
    mp[1] = 10;
    mp[2] = 20;
    mp[3] = 30;

    // Update value
    mp[2] = 99;

    cout << "After insert/update: ";
    printMap(mp);

    // Search
    int key = 3;
    if (mp.find(key) != mp.end()) {
        cout << "Key " << key << " found with value: " << mp[key] << "\n";
    } else {
        cout << "Key " << key << " not found\n";
    }

    // Delete
    mp.erase(1);
    cout << "After deleting key 1: ";
    printMap(mp);

    // Check size
    cout << "Size: " << mp.size() << "\n";

    // Clear all
    mp.clear();
    cout << "After clearing, size: " << mp.size() << "\n";
}

/*
    2) PROBLEM 1: TWO SUM (LeetCode style)
    Return indices of two numbers such that they add up to target.
    Time: O(n)
*/
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];

        if (mp.find(need) != mp.end()) {
            return {mp[need], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

/*
    3) PROBLEM 2: COUNT FREQUENCY OF ELEMENTS
    Time: O(n)
*/
unordered_map<int, int> frequencyCount(vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    return freq;
}

/*
    4) PROBLEM 3: LONGEST SUBARRAY WITH SUM = K
    Works for negative + positive numbers
    Time: O(n)
*/
int longestSubarraySumK(vector<int> &arr, int k) {
    unordered_map<long long, int> firstIndex; // prefixSum -> first index
    long long sum = 0;
    int best = 0;

    for (int i = 0; i < (int)arr.size(); i++) {
        sum += arr[i];

        // Case 1: sum itself equals k
        if (sum == k) {
            best = max(best, i + 1);
        }

        // Case 2: if (sum - k) exists
        if (firstIndex.find(sum - k) != firstIndex.end()) {
            best = max(best, i - firstIndex[sum - k]);
        }

        // Store first occurrence only
        if (firstIndex.find(sum) == firstIndex.end()) {
            firstIndex[sum] = i;
        }
    }

    return best;
}

/*
    MAIN DRIVER
*/
int main() {
    cout << "==== BASIC HASHMAP OPERATIONS ====\n";
    basicHashMapOperations();

    cout << "\n==== TWO SUM ====\n";
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    cout << "Two Sum indices: " << ans[0] << " " << ans[1] << "\n";

    cout << "\n==== FREQUENCY COUNT ====\n";
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4};
    auto freq = frequencyCount(arr);
    cout << "Frequencies:\n";
    for (auto &it : freq) {
        cout << it.first << " -> " << it.second << "\n";
    }

    cout << "\n==== LONGEST SUBARRAY SUM = K ====\n";
    vector<int> arr2 = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << "Longest length: " << longestSubarraySumK(arr2, k) << "\n";

    return 0;
}