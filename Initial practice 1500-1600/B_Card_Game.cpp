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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        vecll nums(4);
        forn(0,4) cin>>nums[i];
        int sum=0;
        if((nums[0]>nums[2] && nums[1]>nums[3]) || (nums[0]==nums[2] && nums[1]>nums[3]) || (nums[0]>nums[2] && nums[1]==nums[3])) sum+=2;
        if((nums[0]>nums[3] && nums[1]>nums[2]) || (nums[0]==nums[3] && nums[1]>nums[2]) || (nums[0]>nums[3] && nums[1]==nums[2])) sum+=2;
        // if((nums[1]>nums[2] && nums[0]>nums[3]) || (nums[1]==nums[2] && nums[0]>nums[3]) || (nums[1]>nums[2] && nums[0]==nums[3])) sum++;
        cout<<sum<<endl;
    }
    return 0;
}