class Solution {
public:
    string reverseWords(string s) {
        stack<string> t;
        string x="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                t.push(x);
                x="";
            }
            else x+=s[i];
        }
        while(!t.empty()&&t.top()=="") t.pop();
        if(x==""){
            x=t.top();
            t.pop();
        }
        while(!t.empty()){
            if(t.top()!="") x+=" "+t.top();
            t.pop();
        }
        return x;
    }
};