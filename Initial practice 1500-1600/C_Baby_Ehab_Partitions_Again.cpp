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

ll cols = 200000;

bool knapsackDp(vector<vecll>& dp,ll target,int i,vecll& a,int n){
    if(i>=n) return target==0;
    if(target<0) return false;
    else if(target==0) return true;
    else if(dp[i][target]!=-1) return dp[i][target];
    else{
        bool without = knapsackDp(dp,target,i+1,a,n);
        bool with = knapsackDp(dp,target-a[i],i+1,a,n);
        return dp[i][target] = with | without;
    }
}

int findFirstBitSet(ll a){
    int count=0;
    while(a%2!=1){
        a/=2;
        ++count;
    }
    return count;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll a(n,0);
    ll sum=0;
    int mini = INT_MAX;
    int index=-1;
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
        int fsb = findFirstBitSet(a[i]);
        if(fsb<mini){
            mini = fsb;
            index = i;
        }
    } 
    if(sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    ll target = sum/2;
    vector<vecll> dp(n,vecll (target+1,-1));
    bool partitionPossible = knapsackDp(dp,target,0,a,n);
    if(!partitionPossible){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    cout<<index+1<<endl;
    return 0;
}