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

void helper(vecll& ans,vecll& p,string& s,int idx,umll& isVisited)
{
    int count=0;
    vecll temp;
    while(isVisited[idx]==0){
        temp.pb(idx);
        isVisited[idx]=1;
        if(s[idx-1]=='0') count++;
        idx=p[idx];
    }
    for(auto it : temp){
        ans[it]=count;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        umll isVisited;
        int n;
        cin>>n;
        vecll a(n+1,0);
        forn(1,n+1) cin>>a[i];
        string s;
        cin>>s;
        vecll ans(n+1,0);
        forn(1,n+1){
            if(isVisited[i]==0){
                helper(ans,a,s,i,isVisited);
            }
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}