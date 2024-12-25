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
    ll n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    sort(itr(a));
    vecll set;
    ll minCount=LLONG_MAX;
    forn(0,n-2){
        ll sum = a[i]+a[i+1];
        set.pb(sum);
    }
    for(int i=n-1;i>0;i--){
        ll val = a[i];
        // auto index = set.upper_bound(val);
        auto index = upper_bound(itr(set),val);
        ll fromStart = 0;
        ll fromEnd = (n-1) - i;
        if(index==set.end()){
            fromStart = set.size();
        }
        else if(*(index)==val){
            ll temp = (index - set.begin())+1;
            fromStart=temp;
        }
        else{
            ll temp = index-set.begin();
            fromStart=temp;
        }
        ll cost = fromStart+fromEnd;
        minCount = min<ll>(minCount,cost);
    }
    cout<<minCount<<endl;
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