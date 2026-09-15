class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<vector<int>>arr;
        for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
        vector<int>a;
        for(int k=i;k<=j;k++){
        a.push_back(nums[k]);}
        arr.push_back(a);} }
        for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
        sort(arr[i].begin(),arr[i].end());
        arr[i].erase(unique(arr[i].begin(),arr[i].end()),arr[i].end());}}
        int temp=0;
      for(auto i:arr){
          temp+=i.size()*i.size();}  
    return temp;}
};