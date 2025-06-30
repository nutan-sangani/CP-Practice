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

void debug(){
    cout<<endl;
}

template<typename T,typename... Args>
void debug(T firstArg,Args... args){
    cout<<firstArg<<" ";
    debug(args...);
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

template<typename T>
void printMatrix(vector<vector<T>>& a){
    int rows = a.size();
    forn(0,rows){
        printArray(a[i]);
    }
}

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
    public : 
    bool operator()(const pll& a,const pll& b) const{
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;
    }
};

class MyComp2{
    public : 
    bool operator()(const pll& a,const pll& b) const{
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first<b.first;
    }
};

void solve(){
    int n;
    cin>>n;
    multiset<pll,MyComp> sortedByFirst;
    multiset<pll,MyComp2> sortedBySecond;
    vector<pll> pairs;
    forn(0,n){
        int a,b;
        cin>>a>>b;
        pairs.pb(mp(a,b));
        sortedByFirst.insert(mp(a,b));
        sortedBySecond.insert(mp(a,b));
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    ll minArea = LLONG_MAX;
    forn(0,n){
        sortedByFirst.erase(sortedByFirst.find(pairs[i]));
        sortedBySecond.erase(sortedBySecond.find(pairs[i]));
        ll l = (*sortedByFirst.rbegin()).first - (*sortedByFirst.begin()).first+1;
        ll b = (*sortedBySecond.rbegin()).second - (*sortedBySecond.begin()).second+1;
        if(l*b == n-1){
            //means either l or b ko ek extra aage badhana padega
            minArea = min<ll>(minArea,min<ll>(l*(b+1LL),b*(1LL+l)));
        }
        else minArea = min<ll>(minArea,l*b);
        sortedByFirst.insert(pairs[i]);
        sortedBySecond.insert(pairs[i]);
    }
    cout<<minArea<<endl;
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