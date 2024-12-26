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
    forn(0,n) cin>>a[i];
    sort(itr(a));
    ll sum=0;
    int i=0;
    while(i<n && a[i]<=1){
        sum+=a[i];
        ++i;
    }
    while(i<n && a[i]<=(sum+1)){
        sum+=a[i];
        ++i;
    }
    cout<<sum+1<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}