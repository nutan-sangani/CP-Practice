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

ll findMinMoves(int row,int col,vector<vecll>& grid,vector<vecll>& dp,int n,int m,pll& end,vector<vecll>& visited){
    if(end.first==row && end.second==col){
        return 0;
    }
    else if(dp[row][col]!=-1) return dp[row][col];
    int rowOption[4] = {0,0,1,-1};
    int colOption[4] = {1,-1,0,0};
    visited[row][col]=1;
    ll minMoves=mod;
    forn(0,4){
        int nextRow = row+rowOption[i];
        int nextCol = col+colOption[i];
        if(inBound(nextRow,nextCol,n,m) && visited[nextRow][nextCol]==0 && grid[nextRow][nextCol]==1){
            ll moves = findMinMoves(nextRow,nextCol,grid,dp,n,m,end,visited);
            if(moves!=mod){
                minMoves=min<ll>(minMoves,moves+1);
            }
        }
    }
    visited[row][col]=0;
    return dp[row][col]=minMoves;
}

void findPathOfMinMove(vector<vecll>& grid,vector<vecll>& dp,int row,int col,pll& end,vector<char>& ans,int n,int m){
    if(end.first==row && end.second==col) return;
    int rowOption[4] = {0,0,1,-1};
    int colOption[4] = {1,-1,0,0};
    char moveOption[4] = {'R','L','D','U'};
    ll minMoves=mod;
    ll moveIndex = -1;
    forn(0,4){
        int nextRow = row+rowOption[i];
        int nextCol = col+colOption[i];
        if(inBound(nextRow,nextCol,n,m) && grid[nextRow][nextCol]!=0){
            ll moves = dp[nextRow][nextCol];
            if(moves!=mod){
                if(minMoves>moves){
                    minMoves=moves;
                    moveIndex=i;
                }
            }
        }
    }
    int nextRow = row+rowOption[moveIndex];
    int nextCol = col+colOption[moveIndex];
    ans.pb(moveOption[moveIndex]);
    findPathOfMinMove(grid,dp,nextRow,nextCol,end,ans,n,m);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vecll> grid(n,vecll(m,-1));
    vector<vecll> dp(n,vecll(m,-1));
    vector<vecll> visited(n,vecll(m,0));
    pll start;
    pll end;
    forn(0,n){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            if(a=='A'){
                start.first=i;
                start.second=j;
            }
            else if(a=='B'){
                end.first=i;
                end.second=j;
            }
            grid[i][j] = a=='#' ? 0 : 1;
        }
    }
    ll moves = findMinMoves(start.first,start.second,grid,dp,n,m,end,visited);
    if(moves==mod){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<moves<<endl;
    vector<char> ans;
    findPathOfMinMove(grid,dp,start.first,start.second,end,ans,n,m);
    forn(0,moves){
        cout<<ans[i];
    }
    return;
}
int main()
{
    FASTIO
    solve();
    return 0;
}
//this doesnt work, since the dp state also needs info on visited. ie 2 states in our case, can have diff ans, since their
//visited maybe different.