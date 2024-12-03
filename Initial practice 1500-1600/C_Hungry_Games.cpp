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

ll getTotal(ll n){
    if(n%2==0) return (n/2)*(n+1);
    return ((n+1)/2)*n;
}

void helper(vecll& nums,ll n,ll x)
{
    vecll prefixSum(n);
    ll sum=0;
    forLoop
    {
        sum+=nums[i];
        prefixSum[i]=sum;
    }
    vecll dp(n,0);
    forLoop
    {
        ll prev = i>0 ? dp[i-1] : 0;
        if(nums[i]>x){
            dp[i]+=(prev+1);
            continue;
        } 
        ll prevSum = i>0 ? prefixSum[i-1] : 0;
        ll target = x+prevSum+1;
        if(lower_bound(prefixSum.begin(),prefixSum.end(),target)==prefixSum.end()) break;
        int index = (lower_bound(prefixSum.begin(),prefixSum.end(),target) - prefixSum.begin());
        dp[index] += (1+prev);
    }
    sum=0;
    forLoop
        sum+=dp[i];
        // cout<<dp[i]<<endl;
    ll total = getTotal(n);
    ll required = total - sum;
    cout<<required<<endl;
}
//0 0 3 4 0
//6 2 3
//

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,x);
    }
    return 0;
}
