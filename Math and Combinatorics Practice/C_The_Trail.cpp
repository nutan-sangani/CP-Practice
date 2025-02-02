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

ll getSumOf(vector<vecll>& grid,ll n,ll m,ll row,ll col){
    ll sum=0;
    if(col==-1){
        forn(0,m){
            sum+=grid[row][i];
        }
    }
    else{
        forn(0,n) sum+=grid[i][col];
    }
    return sum;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    string moves;
    cin>>moves;
    vector<vecll> grid (n,vecll (m,0));
    forn(0,n){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    ll size = moves.size();
    ll row=0,col=0;
    forn(0,size+1){
        if(moves[i]=='D'){ //D gya means ye row ko krsakte
            ll sumOfRow = getSumOf(grid,n,m,row,-1);
            grid[row][col]= -1LL*sumOfRow;
            row+=1;
        }
        else{
            ll sumOfCol = getSumOf(grid,n,m,-1,col);
            grid[row][col]=-1LL*sumOfCol;
            col+=1;
        }
    }
    forn(0,n){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
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