class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int x=0,y=0;
        double rat=(double)a/b;
        int count=0;
        for(int i=0;i<nums.size();i++){
            x=0,y=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0)x++;
                else y++;
                if(y==0)continue;
                else if((double)x/y<=rat)count++;
            }
        }
        return count;
    }
};