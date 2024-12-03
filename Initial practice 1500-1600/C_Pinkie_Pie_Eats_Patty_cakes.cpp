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
    int count=0;
    umll numToCount;
    forn(0,n){
        numToCount[nums[i]]++;
    }
    umll freqToCount;
    int maxFreq = -1;
    for(pll x : numToCount){
        freqToCount[x.second]++;
        if(x.second>maxFreq) maxFreq = x.second;
    }
    int maxFreqCount = freqToCount[maxFreq];
    int rem = n - maxFreq*maxFreqCount;
    int denominator = maxFreq - 1;
    int gapSize = rem/denominator;
    count=gapSize+maxFreqCount-1;
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n,0);
        forn(0,n) cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}