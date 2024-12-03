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

ll Floor(ll a,ll b){
    return a%b==0 ? a/b : a/b;
}

ll Ceil(ll a,ll b){
    return a%b==0 ? a/b : ((a/b)+1);
}

void solve(){
    int n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    ll count=0;
    ll prev = a[n-1];
    for(int i=n-2;i>=0;--i){
        if(a[i]<=prev){
            prev=a[i];
            continue;
        }
        else{
            ll parts = Ceil(a[i],prev);
            count+=(parts-1);
            prev = Floor(a[i],parts);
        }
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