#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

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

class MyComp{
    public:
    bool operator()(const pair<pll,ll>& a,const pair<pll,ll>& b){ //for max heap and ascending sort in vector
        if(a.first.first!=b.first.first)
            return a.first.first<b.first.first;
        else return a.first.second>b.first.second;
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<pll> data;
    vector<pair<pll,ll>> coordinates;
    priority_queue<pair<pll,ll>,vector<pair<pll,ll>>,MyComp> pq;
    vecll hasSome(n,0);
    vecll inSome(n,0);
    forn(0,n){
        ll a,b;
        cin>>a>>b;
        data.pb(mp(a,b));
        coordinates.pb(mp(mp(a,b),i));
    }
    sort(itr(coordinates),MyComp());
    ll maxRange = -1;
    forn(0,n){
        ll start,end;
        pair<pll,ll> curr = coordinates[i];
        start = curr.first.first;
        end = curr.first.second;
        ll index = curr.second;
        if(maxRange>=end){
            inSome[index]=1;
        }
        maxRange = max<ll>(maxRange,end);
        while(!pq.empty() && pq.top().first.second>=end){
            hasSome[pq.top().second]=1;
            pq.pop();
        }
        pq.push(curr);
    }
    forn(0,n){
        cout<<hasSome[i]<<" ";
    }
    cout<<endl;
    forn(0,n){
        cout<<inSome[i]<<" ";
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}