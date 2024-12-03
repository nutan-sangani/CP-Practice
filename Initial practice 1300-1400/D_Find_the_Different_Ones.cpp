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

void helper(vector<ll>& nums,vector<pll>& query,int n,int q)
{
    map<ll,ll>
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<ll>nums(n,0);
        forLoop
            cin>>nums[i];
        int q;
        cin>>q;
        vector<pll> query;
        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            query.push_back(mp(a,b));
        }
        helper(query,nums,n,q);
    }
    return 0;
}