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
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}

void solve(){
    ll n;
    cin>>n;
    vector<pll> data;
    forn(0,n){
        ll a,b;
        cin>>a>>b;
        data.pb(mp(a,b));
    }
    sort(itr(data),compare);
    ll startAllowedFrom = -1;
    ll count=0;
    forn(0,n){
        if(data[i].first>=startAllowedFrom){
            startAllowedFrom = data[i].second;
            count+=1;
        }
    }
    cout<<count<<endl;
}
int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}