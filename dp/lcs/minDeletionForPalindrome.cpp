class Solution {
  public:
  int lps(string s,string t,vector<vector<int>>&dp,int n){
      for(int i=0;i<n+1;i++){
          for(int j=0;j<n+1;j++){
              if(i==0 || j==0){
                  dp[i][j]=0;
              }
          }
      }
      for(int i=1;i<n+1;i++){
          for(int j=1;j<n+1;j++){
              if(s[i-1]==t[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
              }
              else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }
      return dp[n][n];
  }
    int minDeletions(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        string t=s;
        reverse(t.begin(),t.end());
        return n-lps(s,t,dp,n);
    }
};