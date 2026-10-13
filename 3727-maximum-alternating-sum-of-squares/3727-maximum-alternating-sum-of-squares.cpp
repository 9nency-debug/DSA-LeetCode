
class Solution {
public:
    long long solve(vector<long long>& arr, int index) {
        // Base case: index == 6
        // solve(arr, 6) returns 0
        if (index == arr.size()) {
            return 0;
        }
        // index = 0:
        // arr[0] = 9
        // return 9 + solve(arr, 1)
        
        // index = 1:
        // arr[1] = 1
        // return -1 + solve(arr, 2)
        
        // index = 2:
        // arr[2] = 9
        // return 9 + solve(arr, 3)

        // index = 3:
        // arr[3] = 1
        // return -1 + solve(arr, 4)
        
        // index = 4:
        // arr[4] = 4
        // return 4 + solve(arr, 5)
        
        // index = 5:
        // arr[5] = 4
        // return -4 + solve(arr, 6)
        
        // Base case:
        // solve(arr, 6) = 0
        
        // Returning:
        // solve(arr, 5) = -4 + 0  = -4
        // solve(arr, 4) =  4 + (-4) = 0
        // solve(arr, 3) = -1 + 0  = -1
        // solve(arr, 2) =  9 + (-1) = 8
        // solve(arr, 1) = -1 + 8  = 7
        // solve(arr, 0) =  9 + 7  = 16

        if (index % 2 == 0) {
            return arr[index] + solve(arr, index + 1);
        }
        return -arr[index] + solve(arr, index + 1);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }
        sort(squares.begin(), squares.end());
        vector<long long> arr(n);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] = squares[right--];
            } else {
                arr[i] = squares[left++];
            }
        }

        // Calls solve(arr, 0)
        // solve(arr, 0) = 16
        return solve(arr, 0);
    }
};

// TC: O(n logn)