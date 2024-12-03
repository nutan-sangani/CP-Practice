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

vector<string> solve(int i){
    if(i==1){
        vector<string> temp;
        temp.pb("0");
        temp.pb("1");
        return temp;
    }
    vector<string> temp = solve(i-1);
    vector<string> ans;
    forn(0,temp.size()){
        ans.pb(temp[i]+"0");
    }
    int n = temp.size();
    for(int i=n-1;i>=0;--i){
        ans.pb(temp[i]+"1");
    }
    return ans;
}

int main()
{
    FASTIO
    {
        ll n;
        cin>>n;
        vector<string> ans = solve(n);
        forn(0,ans.size()){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}