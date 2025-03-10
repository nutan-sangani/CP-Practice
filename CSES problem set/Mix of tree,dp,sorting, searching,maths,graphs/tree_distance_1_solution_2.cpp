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

ll maxDistance=0;
ll maxDistanceNode=0;

void findMaxDistanceFrom(ll root,um<ll,vecll>& tree,ll parent,ll level){
    if(tree[root].size()==1 && tree[root][0]==parent){
        if(maxDistance<level){
            maxDistance=level;
            maxDistanceNode = root;
        }
        return;
    }
    vecll childs = tree[root];
    for(auto child : childs){
        if(parent!=child){
            findMaxDistanceFrom(child,tree,root,level+1);
        }
    }
}

void findDistanceFromRoot(ll root,um<ll,vecll>& tree,ll parent,ll level,umll& maxHeight){
    if(tree[root].size()==1 && tree[root][0]==parent){
        maxHeight[root]=max<ll>(maxHeight[root],level);
        return;
    }
    vecll childs = tree[root];
    maxHeight[root]=max<ll>(maxHeight[root],level);
    for(auto child : childs){
        if(parent!=child){
            findDistanceFromRoot(child,tree,root,level+1,maxHeight);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    um<ll,vecll> tree;
    forn(1,n){
        ll a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    ll diameterNode1,diameterNode2;
    findMaxDistanceFrom(1,tree,-1,0);
    diameterNode1 = maxDistanceNode;
    maxDistance=0;
    maxDistanceNode=0;
    findMaxDistanceFrom(diameterNode1,tree,-1,0);
    diameterNode2 = maxDistanceNode;
    umll maxHeight;
    findDistanceFromRoot(diameterNode1,tree,-1,0,maxHeight);
    findDistanceFromRoot(diameterNode2,tree,-1,0,maxHeight);
    forn(1,n+1){
        cout<<maxHeight[i]<<" ";
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