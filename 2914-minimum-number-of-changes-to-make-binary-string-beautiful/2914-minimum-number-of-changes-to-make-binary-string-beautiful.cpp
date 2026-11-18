class Solution {
public:
    int minChanges(string s){
        int n=s.size();
        vector<int>v;
        int len=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) len++;
            else{
                v.push_back(len);
                len=1;
            }
        }
        v.push_back(len);
        int m=v.size();
        int i=0;
        int ans=0;
        while(i<m){
            if(v[i]%2==0) i++;
            else{
                if(i+1<m){
                    if(v[i+1]%2!=0){
                        ans++;
                        i+=2;
                    } else{
                        v[i+1]++;
                        ans++;
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};