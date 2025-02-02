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
#define mod 998244353

using namespace std;


void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vecll a(n);
    map<pll,ll> mapi;
    forn(0,n)
    {
        cin>>a[i];
    }
    ll count=0;
    forn(0,n){
        ll f,s;
        f=a[i]%x;
        s=a[i]%y;
        ll sNeeded = s;
        ll fNeeded = x - f;
        fNeeded%=x;
        count+=mapi[mp(fNeeded,sNeeded)];
        ll temp=mapi[mp(f,s)]+1;
       // mapi.insert(mp(a[i]%x,a[i]%y),temp);
       mapi[mp(a[i]%x,a[i]%y)]+=1;
    }
    cout<<count<<endl;
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