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
#define mod 4000000007

using namespace std;

bool validate(um<ll,vecll>& tree,umll& score,ll root,ll toMake){
    if(toMake>mod) return false;
    if(tree[root].size()==0){
        if(score[root]>=toMake) return true;
        else return false;
    }
    ll diff = 0;
    ll toMakeNext=toMake;
    if(root!=0){
        diff = score[root] - toMake;
        diff = diff>=0 ? 0 : abs(diff);
        toMakeNext = toMake + diff;
    }
    if(root==0){
        toMakeNext = toMake - score[0];
    }
    ll val = true;
    for(auto child : tree[root]){
        val &= validate(tree,score,child,toMakeNext);
    }
    return val;
}

void solve(){
    ll n;
    cin>>n;
    um<ll,vecll> tree;
    um<ll,ll> score;
    forn(0,n){
        cin>>score[i];
    }
    forn(1,n){
        ll parent;
        cin>>parent;
        tree[parent-1].pb(i);
    }
    ll low = score[0]+1;
    ll high = mod;
    while(low<=high){
        ll mid = (low+high+0LL)/2LL;
        if(validate(tree,score,0,mid)){
            low=mid+1;
        }
        else high = mid-1;
    }
    cout<<high<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}