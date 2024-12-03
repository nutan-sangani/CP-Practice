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

class Triple{
    public:
    int root;
    int parent;
    ll Xor;
    Triple(int a,int b,ll c){
        this->root=a;
        this->parent=b;
        this->Xor=c;
    }
};


int main()
{
    FASTIO
    
    int t;
    cin>>t;
    vector<vector<pll>> tree(0,vector<pll> (0));
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        queue<Triple> q;
        queue<Triple> q1;
        tree.clear();
        tree.resize(n+1);
        forn(0,n-1){
            ll u,v,w;
            cin>>u>>v>>w;
            tree[u].pb(mp(v,w));
            tree[v].pb(mp(u,w));
        }
        Triple t(b,-1,0);
        q.push(t);
        umll xorFromB;
        while(!q.empty()){
            Triple top = q.front();
            q.pop();
            for(pll u : tree[top.root]){
                if(u.first!=top.parent){
                    ll weight = u.second;
                    ll Xor = (top.Xor^weight);
                    int parent = top.root;
                    Triple k(u.first,parent,Xor);
                    xorFromB[Xor]++;
                    q.push(k);
                }
            }
        }
        Triple t1(a,-1,0);
        q1.push(t1);
        int flag=0;
        if(xorFromB[0]!=0){
            flag=1;
        }
        while(!q1.empty()){
            Triple top = q1.front(); 
            q1.pop();
            for(pll u : tree[top.root]){
                if(u.first!=top.parent && u.first!=b){
                    ll weight = u.second;
                    ll Xor = (top.Xor^weight);
                    int parent = top.root;
                    Triple k(u.first,parent,Xor);
                    q1.push(k);
                    if(xorFromB[Xor]!=0){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1) break;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}