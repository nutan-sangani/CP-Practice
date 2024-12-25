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

bool compare(pll& a,pll& b){
    if(a.first!=b.first)
        return a.first<b.first;
    else return a.second<b.second;
}

void solve(){
    ll n;
    cin>>n;
    omll isPresent;
    // vecll a(n,0);
    vector<pll> b;
    forn(0,n){
        ll a;
        cin>>a;
        ll val = a+(i*1LL);
        b.pb(mp(val,i));
    }
    sort(itr(b),compare);
    isPresent[n]=1;
    ll maxVal=n;
    forn(0,n){
        if(isPresent[b[i].first]!=0){
            ll val = b[i].first+b[i].second;
            isPresent[val]=1;
            maxVal = max<ll>(maxVal,val);
        }
    }
    cout<<maxVal<<endl;
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