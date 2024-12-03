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
    forn(0,n){
        cin>>a[i];
    }
    sort(itr(a));
    int i=0;
    int distinctCount=0;
    while(i<n){
        int j=i+1;
        while(j<n && a[i]==a[j]){
            ++j;
        }
        distinctCount+=1;
        i=j;
    }
    cout<<distinctCount<<endl;
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}