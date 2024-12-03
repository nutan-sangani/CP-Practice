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

void helper(vecll& nums,int n)
{
    omll map;
    forLoop
    {
        ll val = (i-nums[i]+0LL);
        map[val]+=nums[i];
    }
    ll max=-1;
    for(auto it : map){
        if(it.second>max){
            max=it.second;
        }
    }
    cout<<max<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    vecll nums(t);
    int n=t;
    forLoop
        cin>>nums[i];
    helper(nums,n);
    return 0;
}