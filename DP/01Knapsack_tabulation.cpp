#include<iostream>
using namespace std;

int main(){
    vector<vector<int>> dp(5,vector<int>(41,0));
vector<int> wt ={10,20,30,10};
vector<int> val ={10,20,30,420};
int capacity = 40;

 for(int n = 1;n <= 4;n++){
for(int i = 1; i <= capacity; i ++)
{
   if(wt[n-1] <=i){
    //include
    dp[n][i] = max(dp[n-1][i],dp[n-1][i - wt[n-1]]+ val[n-1]);

   }else{
    //exclude
    dp[n][i] = dp[n-1][i];
   }

}}
cout<<dp[4][40];
return 0;


}