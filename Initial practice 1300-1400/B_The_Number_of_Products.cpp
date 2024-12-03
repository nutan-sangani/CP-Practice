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
    vecll posCount;
    int count=0;
    forLoop
    {
        if(nums[i]<0){
            posCount.pb(count+1);
            count=0;
        }
        else count++;
    }
    posCount.pb(count+1);
    count=0;
    vecll prefixSum(posCount.size());
    int size=posCount.size();
    for(int i=size-1;i>=0;i--){
        prefixSum[i] = posCount[i] + ((i+2 < size ? prefixSum[i+2] : 0)*1LL);
    }
    ll negCount=0;
    for(int i=0;i<size-1;i++){
        negCount += (posCount[i]*prefixSum[i+1]*1LL);
    }
    ll total = ((n*1LL)*(n+1+0LL)*1LL)/2LL;
    cout<<negCount<<" "<<total-negCount<<endl;
    return;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll nums(n);
    forLoop
        cin>>nums[i];
    helper(nums,n);
    return 0;
}