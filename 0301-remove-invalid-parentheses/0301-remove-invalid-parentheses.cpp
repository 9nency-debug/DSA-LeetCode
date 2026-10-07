class Solution {
public:
void f(int ind,int n,string& ds,int cnt,string& s,set<string>& ans,int req)
{
   if(ind>=n)
   {
    if(cnt==0 && ds.size()==req)
    {
        ans.insert(ds);
    }
    return;
   }
   if(s[ind]=='(')
   {
        ds.push_back(s[ind]); 
        f(ind+1,n,ds,cnt+1,s,ans,req);
        ds.pop_back();
        f(ind+1,n,ds,cnt,s,ans,req); 
    }
   else if(s[ind]==')')
   {
        if(cnt>0) 
        {
        ds.push_back(s[ind]);
        f(ind+1,n,ds,cnt-1,s,ans,req);
        ds.pop_back();
        }
        f(ind+1,n,ds,cnt,s,ans,req); 
   } else {
        ds.push_back(s[ind]);
        f(ind+1,n,ds,cnt,s,ans,req);
        ds.pop_back();
    }
}
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        set<string>ans;
        string ds;
        int cnt=0;
        int mini=0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='(')
           {
            st.push(i);
           }
           else if(s[i]==')')
           {
            if(!st.empty())
            {
            st.pop();
            }
            else
            {
            mini++;
            }
           }
        }
        mini+=st.size();
        int req=n-abs(mini);
        f(0,n,ds,cnt,s,ans,req);
        vector<string>v;
        for(auto& it:ans)
        {
            v.push_back(it);
        }
        return v;
    }
};