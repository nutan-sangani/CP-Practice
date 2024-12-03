#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vecll& nums,int n)
{
    vecll dp(n,0);
    map<ll,vecll> canJumpTo;
    forLoop
    {
        int jumpTo = i+nums[i];
        if(jumpTo==n-1 && (((i-1)>=-1) && ((i-1)==-1 || dp[i-1]==1))){
            cout<<"YES"<<endl;
            return;
        }
        if(jumpTo<n){
            canJumpTo[jumpTo].pb(i);
        }
    }
    //dp -> 0 1 0
    forLoop
    {
        int backJumpTo = i-nums[i]-1;
        if(backJumpTo>=-1){
            if(backJumpTo==-1){
                dp[i]=1;
            }
            else dp[i]=dp[backJumpTo];
        }
        if(dp[i]!=1){
            vecll temp = canJumpTo[i];
            for(auto x : temp){
                if((x-1)>=0 && dp[x-1]==1){
                    dp[i]=1;
                }
                else if(x==0){
                    dp[i]=1;
                }
                // cout<<x<<" to "<<i<<endl;
            }
        }
        // cout<<dp[i];
    }
    cout<<(dp[n-1]==1 ? "YES" : "NO")<<endl;
}
//5 7 8 9 10 3
//0 1 2 3 4  5

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}