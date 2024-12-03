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

ll countImp=0;
vecll visited;

void dfs(um<ll,vector<pll>>& graph,um<ll,vector<pll>>& rGraph,umll& visitedToColor,int root,int isImposter)
{
    if(countImp==-1) return;
    if(visitedToColor[root]!=0){
        if(visitedToColor[root]!=isImposter){
            countImp=-1;
        }
        return;
    }
    visitedToColor[root]=isImposter;
    if(isImposter==1) ++countImp;
    visited[root]=1;
    vector<pll> childs = graph[root];
    vector<pll> parents = rGraph[root];
    for(pll child : childs){
        int isEdgeImp = child.second;
        int isChildImp = isEdgeImp==1 ? (isImposter==1 ? -1 : 1) : (isImposter==1 ? 1 : -1);
        dfs(graph,rGraph,visitedToColor,child.first,isChildImp);
    }
    for(pll parent : parents){
        int isEdgeImp = parent.second;
        int isParentImp = isEdgeImp==-1 ? (isImposter==-1 ? -1 : 1) : (isImposter==1 ? -1 : 1);
        dfs(graph,rGraph,visitedToColor,parent.first,isParentImp);
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        countImp=0;
        um<ll,vector<pll>> graph;
        um<ll,vector<pll>> rGraph;
        ll sum=0;
        forn(0,m){
            int a,b;
            string s;
            cin>>a>>b;
            cin>>s;
            ll a1;
            a1 = s=="imposter" ? 1 : -1;
            graph[a].pb(mp(b,a1));
            rGraph[b].pb(mp(a,a1));
        }
        visited.resize(n+1);
        umll visitedToColor;
        forn(1,n+1){
            if(visited[i]==0 && sum!=-1){
                countImp=0;
                ll impCount, cmCount;
                impCount = cmCount = 0;
                visitedToColor.clear();
                dfs(graph,rGraph,visitedToColor,i,1);//isko imposter banake.
                impCount=countImp;
                countImp=0;
                visitedToColor.clear();
                dfs(graph,rGraph,visitedToColor,i,-1);//isko crewmate banake.
                cmCount=countImp;
                sum+=max<ll>(impCount,cmCount);
                if(impCount==-1 || cmCount==-1){
                    sum=-1;
                }
            }
            else continue;
        }
        cout<<sum<<endl;
        visited.clear();
    }
    return 0;
}