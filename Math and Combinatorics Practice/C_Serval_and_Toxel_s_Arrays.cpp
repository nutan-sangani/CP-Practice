#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    vector<pll> changes(m);
    forn(0,m){
        ll pos,val;
        cin>>pos>>val;
        changes[i]=(mp(pos-1,val));
    }
    vecll temp(a);
    umll freq;
    forn(0,n){
        freq[a[i]]=m+1;
    }
    forn(0,m){
        ll pos,val;
        pos = changes[i].first;
        val = changes[i].second;
        ll removed = temp[pos];
        ll added = val;
        temp[pos]=added;
        freq[removed]-=(m-i);
        freq[added]+=(m-i);
    }
    ll ans=0;
    for(auto pair : freq){
        ll num = pair.first;
        ll count = pair.second;
        ll total = sumOfnNaturalNumbers(m);
        if(count>=m){
            ans+=total;
            continue;
        }
        ll toBeRemoved = sumOfnNaturalNumbers(m-count);
        total-=toBeRemoved;
        ans+=total;
    }
    cout<<ans<<endl;
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