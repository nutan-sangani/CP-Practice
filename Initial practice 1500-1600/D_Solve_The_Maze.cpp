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

int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};

bool isBounded(int i,int j,int n,int m){
    if(i<n && i>=0 && j<m && j>=0) return true;
    return false;
}

void helper(vector<vector<char>>& grid,int n,int m,vector<pll>& allGood,vector<pll>& allBad)
{
    // if(allGood.size()==0){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    forn(0,allBad.size()){
        int a,b;
        a=allBad[i].first;
        b=allBad[i].second;
        for(int j=0;j<4;j++){
            int rows = a+row[j];
            int cols = b+col[j];
            if(isBounded(rows,cols,n,m)){
                grid[rows][cols]='#';
            }
            if(isBounded(rows,cols,n,m) && grid[rows][cols]=='G'){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    queue<pll> q;
    if(grid[n-1][m-1]!='#')
        q.push(mp(n-1,m-1));
    vector<vecll> visited(n,vecll (m,0));
    visited[n-1][m-1]=1;
    int count=0;
    while(!q.empty()){
        pll u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int rows = u.first + row[i];
            int cols = u.second + col[i];
            if(isBounded(rows,cols,n,m) && visited[rows][cols]==0 && grid[rows][cols]!='#'){
                if(grid[rows][cols]=='G') ++count;
                visited[rows][cols]=1;
                q.push(mp(rows,cols));
            }
        }
    }
    if(count==allGood.size()){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n,vector<char> (m,'.'));
        vector<pll> allGood;
        vector<pll> allBad;
        forn(0,n)
        {
            for(int j=0;j<m;j++){
                char a;
                cin>>a;
                grid[i][j]=a;
                if(a=='B') allBad.pb(mp(i,j));
                if(a=='G') allGood.pb(mp(i,j));
            }
        }
        helper(grid,n,m,allGood,allBad);
    }
    return 0;
}