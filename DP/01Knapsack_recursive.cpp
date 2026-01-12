#include<iostream>
using namespace std;
int maxProfit(vector<int> wt,vector<int> val,int W,int n){
    if(n == 0 || W == 0){
        return 0;
    }
    int itemwt = wt[n-1];
    int itemval = val[n-1];
    if(itemwt <= W){
        //include
        int ans1 = maxProfit(wt,val,W - itemwt,n-1) + itemval;
        //exclude
        int ans2 =maxProfit(wt,val,W ,n-1);
        return max(ans1,ans2);
    }
    else{
        return maxProfit(wt,val,W ,n-1);
    }
    return 0;

}
int main(){
vector<int> wt ={10,20,30,10};
vector<int> val ={10,20,30,420};
cout << maxProfit(wt,val,40,4);
return 0;

}
