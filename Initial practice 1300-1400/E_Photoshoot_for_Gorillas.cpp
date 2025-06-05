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

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll w;
    cin>>w;
    vecll a(w);
    forn(0,w) cin>>a[i];
    sort(itr(a));
    vector<vecll> grid(n,vecll (m,0));
    forn(0,n){
        for(int j=0;j<m;j++){
            ll indexOnSquare = min<ll>(j,k-1);
            //thus index jitna max score hoga, based on right me kitna aage ja sakta h
            ll leftMostTip = j+(k-indexOnSquare)-1;
            ll moves = min<ll>(indexOnSquare+1,m-leftMostTip);
            grid[i][j] = moves;
        }
    }
    priority_queue<ll,vecll> pq;
    forn(0,m){
        for(int j=0;j<n;j++){
            ll indexOnSquare = min<ll>(j,k-1);
            ll bottomMOstTip = j+(k-indexOnSquare)-1;
            ll moves = min<ll>(indexOnSquare+1,n-bottomMOstTip);
            grid[j][i] = grid[j][i]*moves;
            pq.push(grid[j][i]);
        }
    }
    // printMatrix(grid);
    ll score = 0;
    for(int i=w-1;i>=0;i--){
        score += (a[i]*pq.top());
        pq.pop();
    }
    cout<<score<<endl;
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