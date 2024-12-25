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
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    vecll b(n,0);
    forn(0,n){
        cin>>a[i];
    }
    forn(0,n){
        cin>>b[i];
    }
    ll maxCount=0;
    forn(0,n){
        ll contributed = a[i]/b[i];
        maxCount+=contributed;
    }
    vecll c(n,0);
    if(maxCount<k){
        forn(0,n)
            cout<<c[i]<<" ";
        return;
    }
    forn(0,n){
        ll maxContributed = a[i]/b[i];
        ll diff = maxCount-k;
        if(diff>0){
            ll contributed = max<ll>(0,maxContributed-diff);
            maxCount-=maxContributed;
            maxCount+=contributed;
            c[i]=contributed;
        }
        else c[i]=maxContributed;
    }
    forn(0,n)
        cout<<c[i]<<" ";
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}