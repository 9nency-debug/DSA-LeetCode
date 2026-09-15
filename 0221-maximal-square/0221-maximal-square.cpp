class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    //     int r=matrix.size();
    //     if(!r) return 0;
    //     int c=matrix[0].size(), n=min(r,c);
    //     for(int s=n;s>0;s--)
    //         for(int i=0;i<=r-s;i++)  
    //             for(int j=0;j<=c-s;j++) {
    //                 bool has0=false;
    //                 for(int p=i;p<i+s;p++) {
    //                     for(int q=j;q<j+s;q++)
    //                         if(matrix[p][q]=='0') {
    //                             has0=true;
    //                             break;
    //                         }
    //                     if(has0) break;
    //                 }
    //                 if (!has0) return s*s;
    //             }

/*
        int r=matrix.size();
        if(!r) return 0;
        int c=matrix[0].size(), n=min(r,c);
        vector<vector<int>> ones(r+1,vector<int>(c+1));
        for(int i=1;i<=r;i++) 
            for(int j=1;j<=c;j++) ones[i][j] = matrix[i-1][j-1]-'0' + ones[i-1][j]+ones[i][j-1]-ones[i-1][j-1];
        for(int s=n;s>0;s--)
            for(int i=0;i<=r-s;i++)
                for(int j=0;j<=c-s;j++) if(ones[i+s][j+s]-ones[i+s][j]-ones[i][j+s]+ones[i][j] == s*s) return s*s;
        return 0;
*/
        int r = matrix.size();
        if(!r) return 0;
        int c = matrix[0].size(), s = 0;
        vector<vector<int>> dp(r+1, vector<int>(c+1));
        for(int i=1;i<=r;i++) 
            for(int j=1;j<=c;j++) {
                if(matrix[i-1][j-1]=='0') continue;
                s = max(s, dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))); 
	    }
        return s * s;
    }
};

// O(m * n)