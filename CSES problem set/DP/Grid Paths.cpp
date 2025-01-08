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

int rowOptions[2] = {0,1};
int colOptions[2] = {1,0};

bool inBound(int row,int col,int n,int m){
    if(row<n && row>=0 && col<m && col>=0) return true;
    return false;
}

ll findNoOfPathsFrom(ll row,ll col,vector<vector<char>>& grid,ll n,vector<vector<ll>>& dp){
    if(row==n-1 && col==n-1) return 1;
    else if(dp[row][col]!=-1) return dp[row][col];
    ll ways=0;
    forn(0,2){
        ll nextRow = row+rowOptions[i];
        ll nextCol = col+colOptions[i];
        if(inBound(nextRow,nextCol,n,n) && grid[row][col]!='*'){
            ways+=findNoOfPathsFrom(nextRow,nextCol,grid,n,dp);
            ways%=mod;
        }
    }
    return dp[row][col]=ways;
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    forn(0,n){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return;
    }
    vector<vector<ll>> dp(n,vecll (n,-1));
    cout<<findNoOfPathsFrom(0,0,grid,n,dp);
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}