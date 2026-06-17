class Solution {
public:
    bool isMatch(string s, string p) {
        int sn=s.size();
        int pn=p.size();
        int si=0, pi=0, star=-1, match=0;
        while(si<sn){
            if(pi<pn && p[pi]=='?' || p[pi]==s[si]){
                pi++;
                si++;
            }else if(pi<pn && p[pi]=='*'){
                star=pi;
                match=si;
                pi++;
            }else if(star!=-1){
                pi=star+1;
                match++;
                si=match;
            }else{
                return false;
            }
        }
        for(int i=pi; i<pn; i++){
            if(p[i]!='*') 
            return false;
        }
        return true;
    }
};