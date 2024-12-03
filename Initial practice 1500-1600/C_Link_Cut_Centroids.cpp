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

int minValue=INT_MAX;
int minNode=-1;
int minCount=0;

umll nodeCount;

ll helper(um<ll,vecll>& tree,int root,int parent,int n)
{
    if(tree[root].size()==1 && tree[root][0]==parent) return 1;
    vecll childs = tree[root];
    ll maxi = -1;
    ll total = 0;
    for(ll child : childs){
        if(child!=parent){
            ll temp = helper(tree,child,root,n);
            total+=temp;
            maxi = max<ll>(maxi,temp);
        }
    }
    ll parentSide = n - (total+1);
    maxi = max<ll>(maxi,parentSide);
    if(maxi<minValue){
        minValue = maxi;
        minNode = root;
        minCount = 1;
    }
    else if(maxi==minValue){
        ++minCount;
    }
    nodeCount[root]=total+1;
    return total+1;
}

ll getLeaf(int root,int parent,um<ll,vecll>& tree){
    if(tree[root].size()==1 && tree[root][0]==parent){
        return root;
    }
    if(tree[root][0]!=parent)
        return getLeaf(tree[root][0],root,tree);
    else return getLeaf(tree[root][1],root,tree);
}

void printLeafFromMax(int root,um<ll,vecll>& tree){
    int maxi = -1;
    vecll childs = tree[root];
    int maxChild=-1;
    for(ll child : childs){
        maxi = max<ll>(maxi,nodeCount[child]);
        if(maxi==nodeCount[child]){
            maxChild = child;
        }
    }
    ll leaf = getLeaf(maxChild,root,tree);
    ll leafParent = tree[leaf][0];
    cout<<leafParent<<" "<<leaf<<endl;
    cout<<leaf<<" "<<root<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        nodeCount.clear();
        um<ll,vecll> tree;
        minValue=INT_MAX;
        minNode=-1;
        minCount=0;
        forn(0,n-1){
            int a,b;
            cin>>a>>b;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        helper(tree,1,-1,n);
        // cout<<minNode<<" "<<minValue<<" "<<minCount<<endl;
        if(minCount==2){
            printLeafFromMax(minNode,tree);
        }
        else{
            cout<<1<<" "<<tree[1][0]<<endl;
            cout<<1<<" "<<tree[1][0]<<endl;
        }
    }
    return 0;
}