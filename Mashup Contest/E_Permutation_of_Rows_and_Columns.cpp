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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vecll> a(n,vecll(m,0));
    vector<vecll> b(n,vecll(m,0));

    um<ll,pll> coordinateOf;
    forn(0,n){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    forn(0,n){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            pll nn(i,j);
            coordinateOf[b[i][j]]=nn;
        }
    }
    bool isValid = true;
    forn(0,n){
        ll selectedRow;
        if(isValid){
            selectedRow = coordinateOf[a[i][0]].first;
        }
        else break;
        for(int j=0;j<m;j++){
            ll row = coordinateOf[a[i][j]].first;
            if(row!=selectedRow) isValid=false;
        }
    }
    forn(0,m){
        ll selectedCol = -1;
        if(isValid){
            selectedCol = coordinateOf[a[0][i]].second;
        }
        else break;
        for(int j=0;j<n;j++){
            ll col = coordinateOf[a[j][i]].second;
            if(col!=selectedCol) isValid=false;
        }   
    }
    if(isValid) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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