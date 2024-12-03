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

class MyC{
    public:
    bool operator()(pll& a,pll& b){
        return a.first<b.first;
    }
};


void helper(vector<pll>& p,ll n,ll s,ll m)
{
    sort(itr(p),MyC());
    int reach=0;
    forn(0,n){
        ll diff = p[i].first - reach;
        if(diff>=s){
            cout<<"YES"<<endl;
            return;
        }
        reach = p[i].second;
    }
    ll diff = m - reach;
    if(diff>=s){
            cout<<"YES"<<endl;
            return;
        }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s,m;
        cin>>n>>s>>m;
        vector<pll> nums;
        forn(0,n)
        {
            ll a,b;
            cin>>a>>b;
            nums.pb(mp(a,b));
        }
        helper(nums,n,s,m);
    }
    return 0;
}