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

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vecll> grid(n,vecll(m,-1));
    vector<vector<char>> operations(n,vector<char>(m,'.'));
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
            grid[i][j] = ((a=='#') ? 0 : 1);
        }
    }
    queue<pll> q;
    q.push(start);
    while(!q.empty()){
        pll top = q.front();
        q.pop();
        if(top.first==end.first && top.second==end.second){
            break;
        }
        int rowOption[4] = {0,0,-1,1};
        int colOption[4] = {-1,1,0,0};
        char options[4] = {'L','R','U','D'};
        forn(0,4){
            int row = top.first+rowOption[i];
            int col = top.second+colOption[i];
            if(inBound(row,col,n,m) && grid[row][col]!=0 && operations[row][col]=='.'){
                operations[row][col]=options[i];
                pll nn(row,col);
                q.push(nn);
            }
        }
    }
    if(operations[end.first][end.second]=='.'){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    vector<char> ans;
    int row,col;
    row=end.first;
    col=end.second;
    while(!(row==start.first && col==start.second)){
        int rowOption[4] = {0,0,-1,1};
        int colOption[4] = {-1,1,0,0};
        char options[4] = {'R','L','D','U'};
        forn(0,4){
            int rowN = row+rowOption[i];
            int colN = col+colOption[i];
            if(inBound(rowN,colN,n,m) && operations[row][col]==options[i]){
                row=rowN;
                col=colN;
                ans.pb(options[i]);
                break;
            }
        }
    }
    int size=ans.size();
    cout<<size<<endl;
    for(int i=size-1;i>=0;i--){
        cout<<ans[i];
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