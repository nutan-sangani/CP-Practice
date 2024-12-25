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

//can also be used for trees, since tree is a type of graph
void inputGraph(um<ll,vecll>& graph,ll edgeCount){
    forn(0,edgeCount){
        ll a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
}

void dfs(ll root,ll parent,um<ll,vecll>& graph,vecll& visited){
    visited[root]=1;
    vecll neighbours = graph[root];
    for(auto neighbour : neighbours){
        if(neighbour!=parent && visited[neighbour]==0){
            dfs(neighbour,root,graph,visited);
        }
    }
}

void solve(){
    ll nodeCount,edgeCount;
    cin>>nodeCount>>edgeCount;
    um<ll,vecll> graph;
    vecll visited(nodeCount,0);
    inputGraph(graph,edgeCount);
    vector<pll> extraEdgesToConnectUnconnectedComponents;
    ll prevComponentNode=-1;
    forn(1,nodeCount+1){
        if(visited[i]==0){
            dfs(i,-1,graph,visited);
            if(prevComponentNode!=-1){
                extraEdgesToConnectUnconnectedComponents.pb(mp(prevComponentNode,i));
            }
            prevComponentNode=i;
        }
    }
    ll size = extraEdgesToConnectUnconnectedComponents.size();
    cout<<size<<endl;
    forn(0,size){
        cout<<extraEdgesToConnectUnconnectedComponents[i].first<<" "<<extraEdgesToConnectUnconnectedComponents[i].second<<endl;
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