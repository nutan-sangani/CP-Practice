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

ll counti=0;

bool inBound(int row,int col,int n,int m){
    if(row<n && row>=0 && col<m && col>=0) return true;
    return false;
}

int dfs(vector<vector<char>>& grid,ll n,ll m,ll row,ll col,vector<vector<int>>& doesItEnd,vector<vector<bool>>& visited){
    if(!inBound(row,col,n,m)) return 0;
    if(doesItEnd[row][col]!=-1) return doesItEnd[row][col];
    if(visited[row][col]==true) return 1; //1 means yaha pe end ho rha.
    visited[row][col]=true;
    um<char,pll> map;
    pll nn(-1,0);
    map['U']=nn;
    nn.first=1,nn.second=0;
    map['D']=nn;
    nn.first=0,nn.second=1;
    map['R']=nn;
    nn.first=0,nn.second=-1;
    map['L']=nn;
    doesItEnd[row][col]=dfs(grid,n,m,row+map[grid[row][col]].first,col+map[grid[row][col]].second,doesItEnd,visited);
    if(doesItEnd[row][col]==1) counti+=1;
    return doesItEnd[row][col];
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'.'));
    vector<vector<int>> doesItEnd(n,vector<int>(m,-1));
    forn(0,n){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='?') doesItEnd[i][j]=1;
        }
    }
    counti=0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    forn(0,n){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='?'){
                continue;
            }
            if(visited[i][j]==false){
                dfs(grid,n,m,i,j,doesItEnd,visited);
            }
        }
    }
    um<char,pll> map;
    pll nn(-1,0);
    map['U']=nn;
    nn.first=1,nn.second=0;
    map['D']=nn;
    nn.first=0,nn.second=1;
    map['R']=nn;
    nn.first=0,nn.second=-1;
    map['L']=nn;
    forn(0,n){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='?'){
                for(auto it : map){
                    int r = i + it.second.first;
                    int c = j + it.second.second;
                    if(!inBound(r,c,n,m)){
                        continue;
                    }
                    if(doesItEnd[r][c]==1){
                        counti+=1;
                        break;
                    }
                }
            }
        }
    }
    cout<<counti<<endl;
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