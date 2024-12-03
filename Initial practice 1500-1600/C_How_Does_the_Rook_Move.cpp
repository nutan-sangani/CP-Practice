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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

ll helper(ll rem,vecll& dp)
{
    if(rem<=1) return 1;
    else if(dp[rem]!=-1) return dp[rem];
    else{
        ll a = helper(rem-2,dp)*(rem-1)*2LL;
        ll b = helper(rem-1,dp)*1LL;
        ll sum = a+b;
        sum%=mod;
        return dp[rem]=sum;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        ll rem=n;
        vecll dp(n+1,-1);
        forn(0,k){
            int a,b;
            cin>>a>>b;
            if(a==b) --rem;
            else rem-=2;
        }
        cout<<helper(rem,dp)<<endl;
    }
    return 0;
}
//4,1
//