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

ll dfs(vecll& visited,ll index,vecll& a){
    if(visited[index]==1){
        return 1;
    }
    visited[index]=1;
    return dfs(visited,a[index],a)+1;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n+1,0);
    forn(1,n+1)
        cin>>a[i];
    ll count=0;
    vecll visited(n+1,0);
    forn(1,n+1){
        if(visited[i]==0){
            ll edges = dfs(visited,i,a)-1;
            count+=((edges-1)/2);
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