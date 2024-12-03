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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct node{
    int left;
    int right;
    char data;
};

int minCost=INT_MAX;

void helper(unordered_map<int,node*>& tree,int v,int cost)
{
    if(tree[v]->left==-1 && tree[v]->right==-1){
        minCost = min(minCost,cost);
    }
    else{
        if(tree[v]->left!=-1){
            if(tree[v]->data=='L'){
                helper(tree,tree[v]->left,cost);
            }
            else{
                helper(tree,tree[v]->left,cost+1);
            }
        }
        if(tree[v]->right!=-1){
            if(tree[v]->data=='R')
                helper(tree,tree[v]->right,cost);
            else
                helper(tree,tree[v]->right,cost+1);
        }
        return;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        minCost=INT_MAX;
        int n;
        cin>>n;
        unordered_map<int,node*> tree;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            struct node* nn = new node;
            nn->data=s[i];
            int l,r;
            cin>>l>>r;
            nn->left=l-1;
            nn->right=r-1;
            tree[i]=nn;
        }
        helper(tree,0,0);
        cout<<minCost<<endl;
    }
    return 0;
}