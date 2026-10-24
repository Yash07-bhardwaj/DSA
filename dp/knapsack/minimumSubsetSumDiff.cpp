class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int n=arr.size();
        int range=0;
        for(int i=0;i<n;i++){
            range+=arr[i];
        }
        vector<bool>dp(range+1,false);
        dp[0]=true;
        
        for(int i:arr){
            for(int j=range;j>=i;j--){
                dp[j]=dp[j] || dp[j-i];
            }
        }
        vector<int>vec;
        for(int i=0;i<=range/2;i++){
            if(dp[i]){
                vec.push_back(i);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<vec.size();i++){
            mini=min(mini,range-(2*vec[i]));
        }
        return mini;
    }
};
