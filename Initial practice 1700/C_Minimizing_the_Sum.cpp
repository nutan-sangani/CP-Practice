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

ll helper(int i,int rem,int n,vector<vecll>& dp,vecll& a){ //we want to maximise returned value which will be the deducted amount from sum
    if(i>=n) return 0;
    if(rem==0) return 0;
    if(dp[i][rem]!=-1) return dp[i][rem];
    ll mini = a[i];
    ll sum=a[i];
    ll maxi = helper(i+1,rem,n,dp,a);
    for(int j=1;j<=rem && (i+j)<=n;j++){
        sum+=a[i+j];
        mini = min<ll>(mini,a[i+j]);
        ll count = j+1;
        ll temp = count*mini;
        ll temp1 = sum - temp;
        maxi = max<ll>(maxi,temp1+helper(i+j+1,rem-j,n,dp,a));
    }
    return dp[i][rem]=maxi;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
    }
    vector<vecll> dp(n,vecll (k+1,-1));
    cout<<(sum - helper(0,k,n-1,dp,a))<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}