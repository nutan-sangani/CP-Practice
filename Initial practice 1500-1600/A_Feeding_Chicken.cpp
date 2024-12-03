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

void helper(vector<vector<char>>& grid,int r,int c,int k)
{
    vector<vector<char>> ans(r,vector<char> (c,'.'));
    int rCount=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(grid[i][j]=='R') rCount++;
    queue<char> q;
    int count=1;
    int inMore = ceil(rCount*1.f/k*1.f);
    int inLess = rCount/k;
    int moreCount = rCount - k*inLess;
    queue<char> charQ;
    forn(0,26) charQ.push('A'+i);
    forn(0,26) charQ.push('a'+i);
    forn(0,10) charQ.push('0'+i);
    for(int i=0;i<k;i++){
        if(moreCount>0){
            int temp = inMore;
            char character = charQ.front();
            charQ.pop();
            for(int j=0;j<temp;j++){
                q.push(character);
            }
            --moreCount;
        }
        else{
            int temp = inLess;
            char character = charQ.front();
            charQ.pop();
            for(int j=0;j<temp;j++){
                q.push(character);
            }
        }
    }
    for(int i=0;i<r;i++){
        if(i%2!=0) reverse(itr(grid[i]));
        for(int j=0;j<c;j++){
            if(grid[i][j]=='R'){
                ans[i][j]=q.front();
                q.pop();
            }
        }
    }
    char prev = 'A';
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        {
            if(ans[i][j]=='.'){
                ans[i][j]=prev;
            }
            else{
                prev=ans[i][j];
            }
        }
        if(i%2!=0)
            reverse(itr(ans[i]));
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    // cout<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int r,c,k;
        cin>>r>>c>>k;
        vector<vector<char>> grid(r,vector<char> (c,'.'));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>grid[i][j];
        helper(grid,r,c,k);
    }
    return 0;
}