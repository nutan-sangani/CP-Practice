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

using namespace std;

void helper(int n,int k)
{
    vector<vector<ll>> kList(k,vector<ll>(0));
    for(int i=0;i<k;i++){
        int j=i;
        while(j<n){
            kList[i].pb(j);
            j+=k;
        }
    }
    int val=1;
    vecll ans(n);
    for(int i=0;i<k;i++){
        if(i%2!=0){
            reverse(kList[i].begin(),kList[i].end());
        }
        for(int j=0;j<kList[i].size();j++){
            ans[kList[i][j]]=val;
            val++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return;
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
        helper(n,k);
    }
    return 0;
}