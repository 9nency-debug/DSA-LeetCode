class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i=0;i<s.length();i++){
            if(s[i]==')'){
                string temp="";
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int j=0;j<temp.length();j++){
                    st.push(temp[j]);
                }
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int start=0;
        int end=ans.length()-1;
        while(start < end){
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
        return ans;        
    }
};