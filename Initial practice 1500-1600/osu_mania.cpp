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
        vecll ans;
        int n;
        cin>>n;
        string s;
        forn(0,n){
            cin>>s;
            for(int j=0;j<4;j++){
                if(s[j]=='#') ans.pb(j+1);
            }
        }
        reverse(itr(ans));
        forn(0,n){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}