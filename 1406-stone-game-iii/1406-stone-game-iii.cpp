class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> max_diff(n+1,-1e9);
        max_diff[n]=0;
        for(int i=n-1;i>=0;i--){
            int sum=0;
            for(int j=1;j<=3 && i+j<=n;j++){
                sum+=stoneValue[i+j-1];
                max_diff[i]=max(max_diff[i],sum-max_diff[i+j]);
            }
        }
        if(max_diff[0]>0){
            return "Alice";
        }else if(max_diff[0]<0){
            return "Bob";
        }
        return "Tie";
    }
};