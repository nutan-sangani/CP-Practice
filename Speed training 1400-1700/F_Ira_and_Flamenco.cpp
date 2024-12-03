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

ll binaryExponent(ll a,int b,ll m){ //(a^b)%m
    ll ans = 1;
    ll base = a;
    while(b>0){
        if(b & 1){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b/=2;
    }
    return ans%m;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    ll count=0;
    ll currProd=1,prevProd=1;
    sort(itr(a));
    vector<pll> b;
    forn(0,n){
        if(b.empty() || b.back().first!=a[i]){
            pll nn;
            nn.first = a[i];
            nn.second = 1;
            b.pb(nn);
        }
        else
        {   
            b.back().second+=1;
        }
    }
    ll size = b.size();
    ll left=0,right=m-1;
    if(size<m){
        cout<<0<<endl;
        return;
    }
    ll totalProd=1;
    forn(0,m){
        totalProd*=b[i].second;
        totalProd%=mod;
    }
    while(right<size){
        ll diff = b[right].first - b[left].first;
        ll currProd = totalProd;
        currProd%=mod;
        ll temp = binaryExponent(prevProd,mod-2,mod);
        currProd*=temp;
        currProd%=mod;
        if(diff<m){
            count+=currProd;
            count%=mod;
        }
        prevProd*=b[left++].second;
        prevProd%=mod;
        right++;
        if(right<size)
            totalProd*=b[right].second;
        totalProd%=mod;
    }
    count%=mod;
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