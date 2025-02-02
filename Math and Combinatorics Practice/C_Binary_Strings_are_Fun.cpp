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
    ll n;
    string s;
    cin>>n;
    cin>>s;
    ll totalCount=1;
    ll count=1,bc=1;
    forn(1,n){
        if(s[i-1]==s[i]){
            ll temp=count*2;
            temp%=mod;
            count=temp;
            totalCount+=temp;
            totalCount %= mod;
            continue;
        }
        count=bc;
        totalCount+=count;
        totalCount %= mod;
    }
    cout<<totalCount<<endl;
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