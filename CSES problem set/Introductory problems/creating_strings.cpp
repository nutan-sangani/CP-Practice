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

void recurse(string& curr,vector<string>& ans,vecll& count,int index,int n){
    if(index==n){
        ans.pb(curr);
    }
    forn(0,26){
        if(count[i]!=0){
            curr[index]=char('a'+i);
            count[i]-=1;
            recurse(curr,ans,count,index+1,n);
            count[i]+=1;
        }
    }
}

void solve(){
    string s;
    cin>>s;
    vector<string> ans;
    vecll count(26,0);
    forn(0,s.size()){
        count[s[i]-'a']+=1;
    }
    recurse(s,ans,count,0,s.size());
    sort(itr(ans));
    cout<<ans.size()<<endl;
    forn(0,ans.size()){
        cout<<ans[i]<<endl;
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