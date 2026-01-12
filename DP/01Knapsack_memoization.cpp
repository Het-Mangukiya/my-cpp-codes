#include<iostream>
using namespace std;
int maxProfit(vector<int> wt,vector<int> val,int W,int n,vector<vector<int>>& dp){
    if(n == 0 || W == 0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    int itemwt = wt[n-1];
    int itemval = val[n-1];
    if(itemwt <= W){
    //include
    int ans1 = maxProfit(wt,val,W - itemwt,n-1,dp) + itemval;
    //exclude
        int ans2 =maxProfit(wt,val,W ,n-1,dp);
        dp[n][W] =  max(ans1,ans2);
    }
    else{
          dp[n][W] =  maxProfit(wt,val,W ,n-1,dp);
    }
    
    return   dp[n][W];
}
int main(){
    vector<vector<int>> dp(5,vector<int>(41,-1));
vector<int> wt ={10,20,30,10};
vector<int> val ={10,20,30,420};
cout << maxProfit(wt,val,40,4,dp);
cout<<dp[4][40];
return 0;


}