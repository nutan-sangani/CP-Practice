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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a;
    vecll b(m,0);
    ll count=0;
    forn(0,n){
        ll z;
        cin>>z;
        a.pb(z);
    }
    forn(0,m){
        cin>>b[i];
    }
    sort(itr(a));
    sort(itr(b));
    ll aIter,bIter;
    aIter=bIter=0;
    while(aIter<n && bIter<m){
        ll low = a[aIter]-k;
        ll high = a[aIter]+k;
        while(bIter<m && !(b[bIter]>=low && b[bIter]<=high) && b[bIter]<=high){
            ++bIter;
        }
        if(b[bIter]>=low && b[bIter]<=high){
            count+=1;
            bIter+=1;
        }
        aIter+=1;
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