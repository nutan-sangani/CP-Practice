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

ll findMaximumCount(ll root,ll parent,um<ll,vecll>& tree,vector<vecll>& dp,ll canSelect){
    if(tree[root].size()==1 && tree[root][0]==parent){
        return 0;
    }
    else if(dp[root][canSelect]!=-1) return dp[root][canSelect];
    vecll childs = tree[root];
    umll notSelectedScore;
    ll scoreSum=0;
    for(ll child : childs){
        if(child==parent) continue;
        notSelectedScore[child] = findMaximumCount(child,root,tree,dp,1);
        scoreSum+=notSelectedScore[child];
        //since current ko select nhi kiya, toh next ko humesha can select.
    }
    ll maxi = scoreSum;
    if(canSelect==1){
        //ek ek karke sabko select kr and dekh the change in score.
        for(ll child : childs){
            if(child==parent) continue;
            ll temp = findMaximumCount(child,root,tree,dp,0)+1;
            ll score = scoreSum - notSelectedScore[child] + temp;
            maxi = max<ll>(maxi,score);
        }
    }
    return dp[root][canSelect]=maxi;
}

void solve(){
    ll n;
    cin>>n;
    vector<vecll> dp(n+1,vecll(2,-1));
    um<ll,vecll> tree;
    forn(1,n){
        ll a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    cout<<findMaximumCount(1,-1,tree,dp,1);
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}