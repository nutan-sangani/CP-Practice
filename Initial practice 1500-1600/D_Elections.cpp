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
    vecll ans(n,-1);
    vecll prefixSum(n,0);
    ll sum=0;
    ll maxValue=-1;
    int maxIndex=-1;
    forLoop
    {
        if(nums[i]>maxValue){
            maxValue = nums[i];
            maxIndex=i;
        }
        sum+=nums[i];
        prefixSum[i]=sum;
    }
    ans[maxIndex]=0;
    forLoop
    {
        if(ans[i]==-1){
            ll prevSum = i-1>=0 ? prefixSum[i-1] : 0;
            if(prevSum+nums[i]>=maxValue){
                ans[i]=i;
            }
            else ans[i]=i+1;
        }
    }
    forLoop
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll c;
        cin>>n>>c;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        nums[0]+=c;
        helper(nums,n);
    }
    return 0;
}