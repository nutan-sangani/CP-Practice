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

void markChild(vector<vector<pll>>& dp,int i,int j,int n)
{
    if(i+1<n && j+2<n) dp[i+1][j+2].second-=1;
    if(i+1<n && j>0) dp[i+1][j-1].first+=1;
    if(i+1<n && j==0) dp[i+1][0].first+=1;
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
        vector<vecll> grid(n,vecll (n,0));
        vector<vector<pll>> dp(n,vector<pll> (n,mp(0,0))); //first for positive, second for negative
        forn(0,n){
            string a;
            cin>>a;
            for(int j=0;j<n;j++){
                grid[i][j]=(a[j]-'0');
            }
        }
        int count=0;
        forn(0,n){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+=dp[i][j].first+dp[i][j].second;
                if(dp[i][j].first>0){
                    if(i+1<n && j>0) dp[i+1][j-1].first+=dp[i][j].first;
                    if(i+1<n && j==0) dp[i+1][0].first+=dp[i][j].first;
                }
                if(dp[i][j].second<0){
                    if(i+1<n && j+1<n) dp[i+1][j+1].second+=dp[i][j].second;
                }
                bool willShift = sum%2==0 ? false : true;
                int val = grid[i][j];
                if(willShift){
                    val = val==0 ? 1 : 0;
                }
                if(val==1){
                    ++count;
                    markChild(dp,i,j,n);
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}