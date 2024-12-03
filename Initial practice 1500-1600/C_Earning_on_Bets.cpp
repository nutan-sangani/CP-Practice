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

ll diameter = 0;

ll dfs(um<ll,vecll>& tree,int root,int parent,umll& map){
    vecll childs = tree[root];
    vecll cost;
    if(map[root]!=0)
        cost.pb(0);
    for(ll child : childs){
        if(child!=parent){
            ll costTemp = dfs(tree,child,root,map);
            if(costTemp>0){
                cost.pb(costTemp);
            }
        }
    }
    sort(itr(cost),greater<ll>());
    if(cost.size()>1){
        ll sum = cost[0]+cost[1];
        diameter=max<ll>(diameter,sum);
    }
    // if(parent==-1){
    //     ll sum = cost[0];
    //     if(cost.size()>1) sum+=cost[1];
    //     ll divisor = ((sum+1LL)/2LL);
    //     cout<<divisor<<endl;
    //     return -1;
    // }
    // else{
        if(cost.size()>0){
            return (cost[0]+1LL);
        }
        return -1;
    // }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    umll map;
    um<ll,vecll> tree;
    vecll marked(k,0);
    forn(0,k){
        int a;
        cin>>a;
        map[a]=1;
        marked[i]=a;
    }
    forn(0,n-1){
        int a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    if(k==1){
        cout<<0<<endl;
        return;
    }
    dfs(tree,marked[0],-1,map);
    cout<<(diameter+1)/2<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        diameter=0;
        solve();
    }
    return 0;
}