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

umll inCycle;
bool foundCycle=false;
int closestCyclicNode=-1;

void findCycleDFS(umll& visited,int root,um<ll,vecll>& graph,vecll& path,int parent){
    if(visited[root]==1){
        int i=path.size()-1;
        for(i;path[i]!=root;--i){
            inCycle[path[i]]=1;
        }
        inCycle[root]=1;
        foundCycle=true;
    }
    else if(foundCycle) return;
    else{
        path.pb(root);
        visited[root]=1;
        vecll temp = graph[root];
        for(auto it : temp){
            if(parent!=it){
                findCycleDFS(visited,it,graph,path,root);
                if(foundCycle){
                    return;
                }
            }
        }
        visited[root]=0;
        path.pop_back();
    }
}

int findClosestCyclicNode(um<ll,vecll>& graph,umll& visited,int root){
    queue<int> q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        int length = q.size();
        ++count;
        while(length--){
            int top = q.front();
            q.pop();
            if(visited[top]==0){
                visited[top]=1;
                vecll temp = graph[top];
                for(auto child : temp){
                    if(inCycle[child]!=0){
                        closestCyclicNode = child;
                        return count;
                    }
                    if(visited[child]==0)
                        q.push(child);
                }
            }
        }
    }
    return count;
}

int findDistanceTo(int root,int target,umll& visited,um<ll,vecll>& graph){
    queue<int> q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        int length = q.size();
        ++count;
        while(length--){
            int top = q.front();
            q.pop();
            if(visited[top]==0){
                if(target==top){
                    return count;
                }
                visited[top]=1;
                vecll temp = graph[top];
                for(auto child : temp){
                    if(child==target){
                        return count;
                    }
                    if(visited[child]==0)
                        q.push(child);
                }
            }
        }
    }
    return count;
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    um<ll,vecll> graph;
    forn(0,n){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vecll path;
    umll visited;
    findCycleDFS(visited,1,graph,path,-1);

    if(inCycle[b]!=0 && a!=b){
        cout<<"YES"<<endl;
        return;
    }
    visited.clear();
    int distanceB = findClosestCyclicNode(graph,visited,b);
    visited.clear();
    int distanceA = findDistanceTo(a,closestCyclicNode,visited,graph);

    // cout<<inCycle[b]<<endl;
    // cout<<closestCyclicNode<<" "<<distanceB<<" "<<distanceA<<endl;

    if(distanceA<=distanceB){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        closestCyclicNode=-1;
        foundCycle=false;
        inCycle.clear();
        solve();
    }
    return 0;
}