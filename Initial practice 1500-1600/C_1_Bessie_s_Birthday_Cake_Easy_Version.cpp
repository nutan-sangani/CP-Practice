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

void helper(vecll& nums,ll n,ll x,ll y)
{
    ll count=0;
    sort(itr(nums));
    forn(0,x){
        ll nextSelected = i<x-1 ? nums[i+1] : nums[0];
        ll nextToI = (nums[i]+1)%(n+1);
        if(nextToI==0) ++nextToI;
        nextToI = (nextToI+1)%(n+1);
        if(nextToI==0) ++nextToI;
        if(nextToI==nextSelected){
            ++count;
        }
    }
    count+=(x-2);
    cout<<count<<endl;
    return;
}


int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vecll nums(x,0);
        forn(0,x) cin>>nums[i];
        helper(nums,n,x,y);
    }
    return 0;
}