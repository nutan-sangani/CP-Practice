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
    string s,t;
    cin>>s;
    cin>>t;
    umll lastIndexFromTOf;
    forn(0,t.size()-1){
        lastIndexFromTOf[t[i]-'a']=i;
    }
    ll minSize=LLONG_MAX;
    string ans;
    ll n = t.size();
    forn(1,s.size()){
        if(lastIndexFromTOf.count(s[i]-'a')>0){
            ll tempSize = i+1;
            ll lastIndex = lastIndexFromTOf[s[i]-'a'];
            tempSize+=(n-1-lastIndex);
            if(minSize>tempSize){
                minSize=tempSize;
                ans=s.substr(0,i+1);
                ans+=t.substr(lastIndex+1,n-1-lastIndex);
            }
        }
    }
    if(minSize==LLONG_MAX){
        cout<<-1<<endl;
        return;
    }
    forn(0,ans.size()){
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