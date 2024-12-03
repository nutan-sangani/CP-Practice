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

void helper(vecll& nums,int n)
{
    um<ll,ll> numberToLength;
    umll numberToIndices;
    int maxValue,maxNumber;
    maxValue = maxNumber = -1;
    vecll backwardIndices(n,-1);
    forn(0,n){
        int longestChainLength = numberToLength[nums[i]-1]+1;
        if(maxValue<longestChainLength){
            maxValue = longestChainLength;
            maxNumber = nums[i];
        }
        if(longestChainLength>=numberToLength[nums[i]]){
            numberToLength[nums[i]]=longestChainLength;
            numberToIndices[nums[i]]=i+1;
            backwardIndices[i] = numberToIndices[nums[i]-1];
        }
    }
    vecll ans;
    int index = numberToIndices[maxNumber]-1;
    ans.pb(index+1);
    forn(1,maxValue){
        index = backwardIndices[index]-1;
        ans.pb(index+1);
    }
    cout<<ans.size()<<endl;
    reverse(itr(ans));
    forn(0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    FASTIO
    {
        int n;
        cin>>n;
        vecll nums(n,0);
        forn(0,n) cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}