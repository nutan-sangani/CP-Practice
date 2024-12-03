#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
// #define mp make_pair
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

string mp(ll a,ll b){
    return to_string(a)+","+to_string(b);
}

ll findHeight(um<ll,vecll>& tree,ll root,ll parent,ll parentMax,umll& maxHeight,um<string,ll>& edgeDistance){
    if(tree[root].size()==1 && tree[root][0]==parent){
        maxHeight[root]=max<ll>(0,parentMax);
        return 1;
    }
    ll maxi = 0;
    vecll childs = tree[root];
    ll largest,secondLargest;
    largest=secondLargest=0;
    largest=parentMax;
    if(parentMax!=0)
    {
        for(auto child : childs){
            ll height=edgeDistance[mp(root,child)];
            if(height>largest){
                secondLargest=largest;
                largest=height;
            }
            else if(height>secondLargest){
                secondLargest=height;
            }
        }
    }
    for(auto child : childs){
        if(child==parent) continue;
        ll height=0;
        if(edgeDistance[mp(root,child)]!=largest)
            height = findHeight(tree,child,root,largest+1,maxHeight,edgeDistance);
        else height = findHeight(tree,child,root,secondLargest+1,maxHeight,edgeDistance);
        edgeDistance[mp(root,child)]=height;
        maxi = max<ll>(maxi,height);
    }
    maxHeight[root] = max<ll>(parentMax,maxi);
    return maxi+1;
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
    ll largest,secondLargest;
    largest=secondLargest=0;
    // map<pll,ll> edgeDistance;
    um<string,ll> edgeDistance;
    umll maxDistance;
    for(auto child : tree[1]){
        ll height = findHeight(tree,child,1,0,maxDistance,edgeDistance);
        edgeDistance[mp(1,child)]=height;
        if(height>largest){
            secondLargest=largest;
            largest=height;
        }
        else if(height>secondLargest){
            secondLargest=height;
        }
    }
    maxDistance[1]=largest;
    for(auto child : tree[1]){
        ll height=edgeDistance[mp(1,child)];
        if(height==largest){
            height=secondLargest;
        }
        else height=largest;
        findHeight(tree,child,1,1+height,maxDistance,edgeDistance);
    }
    forn(1,n+1){
        cout<<maxDistance[i]<<" ";
    }
    return;
}

int main()
{
    FASTIO
    solve();
    return 0;
}