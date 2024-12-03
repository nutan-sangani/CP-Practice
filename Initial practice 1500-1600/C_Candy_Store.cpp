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

void solve()
{
    int n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    ll ans = 0;
    ll mini = a[0];
    forn(1,n){
        ll diff = a[i] - a[i-1];
        if(diff>0){
            ans+=abs(diff);
        }
        else{
            ans+=abs(diff);
            mini = a[i];
        }
    } //8+8+ (-4)
    ans+=abs(mini);
    cout<<ans<<endl;
}
//12+16+8=24+12=36
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