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

ll findMinDiff(vecll& a,int n,int i,ll rem,ll currSum){
    if(i==n) return abs(currSum-rem);
    ll notIncluding,including;
    notIncluding = findMinDiff(a,n,i+1,rem,currSum); //not taking ith elem in naya partition.
    including = findMinDiff(a,n,i+1,rem-a[i],currSum+a[i]);
    return min<ll>(notIncluding,including);
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<findMinDiff(a,n,0,sum,0)<<endl;
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}