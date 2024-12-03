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

vector<ll> dp(100009,-1);

ll helper(ll i,ll k)
{
    if(i<0) return 0;
    else if(i==0) return 1;
    else if(dp[i]!=-1) return dp[i];
    else{
        ll a = helper(i-1,k);
        a%=mod;
        ll b = helper(i-k,k);
        b%=mod;
        ll ans = a+b;
        ans%=mod;
        return dp[i]=ans;
    } 
}


int main()
{
    FASTIO
    
    int t;
    int k;
    cin>>t>>k;
    helper(100000,k);
    ll sum=0;
    vecll prefixSum(1e5+9,0);
    forn(1,1e5+6){
        sum+=dp[i];
        sum%=mod;
        prefixSum[i]=sum;
    }
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        ll prev = prefixSum[a-1];
        ll ans = prefixSum[b] - prev;
        ans += mod;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}