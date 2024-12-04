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

bool inBound(int row,int col,int n,int m){
    if(row<n && row>=0 && col<m && col>=0) return true;
    return false;
}

void dfs(vector<vector<int>>& grid,int row,int col,int n,int m){
    int availableRowMove[4] = {0,0,-1,1};
    int availableColMove[4] = {-1,1,0,0};
    grid[row][col]=-1; //visiting the current square
    forn(0,4){
        int nextRow = row+availableRowMove[i];
        int nextCol = col+availableColMove[i];
        if(inBound(nextRow,nextCol,n,m) && grid[nextRow][nextCol]==1){
            dfs(grid,nextRow,nextCol,n,m);
        }
    }
    return;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,-1));
    forn(0,n){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            grid[i][j]= a=='.' ? 1 : 0;
        }
    }
    //same as number of islands.
    //jisko visit kiya h, usko -1 krte jaa.
    ll count=0;
    forn(0,n){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                dfs(grid,i,j,n,m);
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}