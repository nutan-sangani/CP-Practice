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
#define mod 100000007

using namespace std;

int remaining=0;

int isValid(unordered_map<ll,vecll>& tree,int root,int parent,int count){
    if(tree[root].size()==1 && tree[root][0]==parent) return 1;
    ll total=0;
    int childCount = tree[root].size();
    forn(0,childCount){
        if(tree[root][i]!=parent){
            int temp = isValid(tree,tree[root][i],root,count);
            if(temp>=count && remaining>0){
                --remaining;
            }
            else total+=temp;
        }
    }
    total+=1; //for the root node
    if(total>=count && remaining>0){
        --remaining;
        return 0;
    }
    return total;
}

void helper(unordered_map<ll,vecll>& tree,int n,int k)
{
    int low=1;
    int high = ceil((1.f*n)/(1.f*(k+1)));
    while(low<=high){
        int mid = (low+high)/2;
        remaining = k;
        int count = isValid(tree,1,-1,mid);
        // cout<<count<<" "<<mid<<endl;
        if(count>=mid){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
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
        int n,k;
        cin>>n>>k;
        unordered_map<ll,vecll> tree;
        forn(0,n-1){
            int a,b;
            cin>>a>>b;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        helper(tree,n,k);
    }
    return 0;
}