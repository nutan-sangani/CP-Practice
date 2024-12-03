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

using namespace std;

void helper(ll n,ll k)
{
    char ans[4][n];
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++)
            ans[i][j]='.';
    }
    ll m = k;
    int mid = n/2;
    for(int j=1;j<=2;j++){
        for(int i=1;i<=mid;i++){
            if(i==mid && m>=1){
                m-=1;
                ans[j][i]='#';
            }
            else if(m>1){
                int fromLast = n-i-1;
                m-=2;
                ans[j][i]='#';
                ans[j][fromLast]='#';
                continue;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return;
}

int main()
{
    FASTIO
    
    ll n,k;
    cin>>n>>k;
    helper(n,k);
    return 0;
}