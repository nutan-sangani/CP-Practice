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

void solve(){
    int n;
    cin>>n;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    vecll toRightOfStart(n,0),toLeftOfStart(n,0);
    vecll maxLeftOfStart(n,0),maxRightOfStart(n,0);
    ll maxi = -1;
    forn(0,n){
        ll leftStartCost = a[i]+i;
        ll rightStartCost = a[i]+(n-(i+1));
        toRightOfStart[i]=leftStartCost;
        toLeftOfStart[i]=rightStartCost;
        maxi = max<ll>(maxi,toLeftOfStart[i]);
        maxLeftOfStart[i]=maxi;
    }
    maxi=-1;
    for(int i=n-1;i>=0;--i){
        maxi = max<ll>(maxi,toRightOfStart[i]);
        maxRightOfStart[i]=maxi;
    }
    ll minCost=LLONG_MAX;
    forn(0,n){
        ll leftLast = i-1;
        ll rightFirst = i+1;
        ll leftMax=-1;
        ll rightMax=-1;
        if(leftLast!=-1){
            leftMax = maxLeftOfStart[leftLast];
        }
        if(rightFirst!=n){
            rightMax = maxRightOfStart[rightFirst];
        }
        maxi = max<ll>(rightMax,leftMax);
        maxi = max<ll>(maxi,a[i]); //since a[i] can also be max
        minCost = min<ll>(minCost,maxi);
    }
    cout<<minCost<<endl;
}

int main()
{
    FASTIO
    
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}