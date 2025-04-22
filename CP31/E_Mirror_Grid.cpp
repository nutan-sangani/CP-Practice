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

ll getCostForLayer(int row,int col,int n,vector<vector<int>>& grid){
    if(n<=1) return 0;
    vecll a,b,c,d;
    int lastRow = row+(n-1);
    int lastCol = col+(n-1);
    forn(col,lastCol){
        a.pb(grid[row][i]);
    }
    for(int i=lastCol;i>col;i--){
        b.pb(grid[lastRow][i]);
    }
    forn(row,lastRow){
        d.pb(grid[i][lastCol]);
    }
    for(int i=lastRow;i>row;i--){
        c.pb(grid[i][col]);
    }
    ll cost=0;
    forn(0,a.size()){
        ll oneCount=0,zeroCount=0;
        if(a[i]==1) oneCount+=1;
        else zeroCount+=1;
        if(b[i]==1) oneCount+=1;
        else zeroCount+=1;
        if(c[i]==1) oneCount+=1;
        else zeroCount+=1;
        if(d[i]==1) oneCount+=1;
        else zeroCount+=1;
        if(oneCount>zeroCount){
            cost+=zeroCount;
        }
        else cost+=oneCount;
    }
    return cost+getCostForLayer(row+1,col+1,n-2,grid);
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int> (n,-1));
    forn(0,n){
        for(int j=0;j<n;j++){
            char a;
            cin>>a;
            grid[i][j]=(a-'0');
        }
    }
    cout<<getCostForLayer(0,0,n,grid)<<endl;
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