class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int left=1;
        int right=*max_element(arr.begin(),arr.end());
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long sum=0;
            for(int i:arr){
                sum+=ceil(i/(double)mid);
            }
            if(sum<=h){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
        
    }
};