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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){
        if(a.second!=b.second)
            return a.second>b.second;
        else return a.first>b.first;
    }
};

bool isValid(int root,int rootTopic,um<ll,vecll>& graph,umll& blogToTopic){
    vecll temp = graph[root];
    int uniqueCount = rootTopic-1;
    umll count;
    for(ll x : temp){
        int topic = blogToTopic[x];
        if(topic==rootTopic) return false;
        if(topic<rootTopic){
            if(count[topic]==0){
                --uniqueCount;
                count[topic]=1;
            }
        }
    }
    if(uniqueCount==0) return true;
    return false;
}

int main()
{
    FASTIO
    
    {
        int n,m;
        cin>>n>>m;
        um<ll,vecll> blogGraph;
        forn(0,m){
            int a,b;
            cin>>a>>b;
            blogGraph[a].pb(b);
            blogGraph[b].pb(a);
        }
        umll blogToTopic; //blog : topic
        priority_queue<pll,vector<pll>,MyComp> pq;
        forn(0,n){
            int a;
            cin>>a;
            blogToTopic[i+1]=a; //ith blog ka topic is a
            pq.push(mp(i+1,a));
        }
        vecll ans;
        while(!pq.empty()){
            pll top = pq.top();
            pq.pop();
            if(isValid(top.first,top.second,blogGraph,blogToTopic)){
                ans.pb(top.first);
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }
        forn(0,n){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}