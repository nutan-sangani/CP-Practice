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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vecll> grid(2,vecll (n+4,-1));

        forn(0,n){
            int a,b;
            cin>>a>>b;
            grid[b][a]=1;
        }
        ll count=0;
        forn(0,n+1){
            if(grid[0][i]==1 && grid[1][i]==1){
                count+=(n-2);
            }
        }
        forn(0,n+1){
            if(grid[0][i]==1 && grid[0][i+2]==1 && grid[1][i+1]==1) count++;
            if(grid[1][i]==1 && grid[1][i+2]==1 && grid[0][i+1]==1) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}