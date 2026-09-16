vector<int> f(vector<int> &a){
    int n = a.size();
    vector<int> r(n, 0);
    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=0;j<i;j++){
            if(a[j]>a[i])temp++;
        }
        r[i]=temp;
    }
    return r;
}

int g(vector<int>&r, vector<int>&a){
    int temp = 0;
    int n = r.size();
    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                temp+=r[j];
            }
        }
    }
    return temp;
}
class Solution {
public:
    int numTeams(vector<int>& a) {
        int n = a.size();
        vector<int>ra = f(a);
        int ans = g(ra,a);
        vector<int>b(a.rbegin(),a.rend());
        vector<int> rb =f(b);
        ans+=g(rb,b);
        return ans;      
    }
};