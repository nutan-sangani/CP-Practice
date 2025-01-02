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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b) const { //for max heap and ascending sort in vector
        if(a.second!=b.second) return a.second<b.second;
        return a.first>b.first;
    }
};

class MyComp2{
    public:
    bool operator()(const pll& a,const pll& b) const { //for max heap and desc sort in vector
        if(a.second!=b.second) return a.second>b.second;
        return a.first<b.first;
    }
};

class MyComp1{
    public:
    bool operator()(const pll& a,const pll& b) const{
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second > b.second;
    }
};

class MyComp4{
    public:
    bool operator()(const pll& a,const pll& b) const{
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second < b.second;
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<pll> data;
    map<pll,ll> map;
    forn(0,n){
        ll l,r;
        cin>>l>>r;
        data.pb(mp(l,r));
        map[mp(l,r)]=i;
    }
    sort(itr(data),MyComp());


    tree<pll,null_type,MyComp1,rb_tree_tag,tree_order_statistics_node_update> sortedSet;
    vecll rangeCountInThis(n,0);
    vecll rangeCountThisIn(n,0);
    forn(0,n){
        ll index = map[mp(data[i].first,data[i].second)];
        ll countOfPairsWithSmallerRightBound = i;
        ll countOfPairsWithSmallerLeftBound = sortedSet.order_of_key(data[i]);
        rangeCountInThis[index]= countOfPairsWithSmallerRightBound - countOfPairsWithSmallerLeftBound;
        sortedSet.insert(data[i]);
    }
    sort(itr(data),MyComp2());
    tree<pll,null_type,MyComp4,rb_tree_tag,tree_order_statistics_node_update> sortedSetReverse;
    forn(0,n){
        ll index = map[mp(data[i].first,data[i].second)];
        ll countOfPairsWithLargerRightBound = i;
        ll countOfPairsWithSmallerLeftBound = sortedSetReverse.order_of_key(data[i]);
        rangeCountThisIn[index]=countOfPairsWithLargerRightBound - countOfPairsWithSmallerLeftBound;
        sortedSetReverse.insert(data[i]);
    }


    forn(0,n){
        cout<<rangeCountInThis[i]<<" ";
    }
    cout<<endl;
    forn(0,n){
        cout<<rangeCountThisIn[i]<<" ";
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