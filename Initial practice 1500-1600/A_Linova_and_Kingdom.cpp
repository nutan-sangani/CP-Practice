#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forl(j,n) for(int i=j;i<n;i++)
#define iter(a) a.begin(),a.end()
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

using namespace std;

ll dfs(int root,int parent,unordered_map<ll,vecll>& edges,vecll& count,int level)
{
    if(parent!=-1 && edges[root].size()==1){
        count.pb(0-level);
        // cout<<(0-level)<<" "<<root<<endl;
        return 1;
    } 
    else{
        vecll temp = edges[root];
        ll total = 0;
        forl(0,temp.size())
        {
            if(temp[i]!=parent){
                total += dfs(temp[i],root,edges,count,level+1);
            }
        }
        {
            count.pb(total-level);
            // cout<<(total-level)<<" "<<root<<endl;
        }
        return total+1;
    }
}
void helper(unordered_map<ll,vecll>& edges,int n,int k,int tourism)
{
    vecll count;
    ll a = dfs(1,-1,edges,count,0);
    sort(iter(count),greater<ll>());
    ll ans=0;
    for(int i=0;i<tourism;i++){
        ans+=count[i];
        // cout<<count[i]<<endl;
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        unordered_map<ll,vecll> edges;
        forl(0,n-1)
        {
            int a,b;
            cin>>a>>b;
            edges[a].pb(b);
            edges[b].pb(a);
        }
        helper(edges,n,k,n-k);
    }
    return 0;
}