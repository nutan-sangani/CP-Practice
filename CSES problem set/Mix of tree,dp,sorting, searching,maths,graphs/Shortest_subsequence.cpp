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
    string s;
    cin>>s;
    vecll a;
    um<char,set<ll>> indexes;
    ll n = s.size();
    forn(0,n){
        indexes[s[i]].insert(i);
    }
    vector<char> ans;
    ll currIndex = 0;
    while(currIndex<=n){
        char options[4]={'A','C','G','T'};
        ll maxi = 0;
        char maxChoice='1';
        for(auto choice : options){
            if(indexes[choice].lower_bound(currIndex)==indexes[choice].end()){
                ans.pb(choice);
                forn(0,ans.size()){
                    cout<<ans[i];
                }
                return;
            }
            else{
                int index = *(indexes[choice].lower_bound(currIndex));
                if(maxi<index){
                    maxi=index;
                    maxChoice=choice;
                }
            }
        }
        currIndex=maxi+1;
        ans.pb(maxChoice);
    }
    forn(0,ans.size()){
        cout<<ans[i];
    }
    return;
}

int main()
{
    FASTIO
    solve();
    return 0;
}