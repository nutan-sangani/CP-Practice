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
    vecll ans(n,0);
    umll count;
    ll maxi=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        count[nums[i]]++;
        if(count[nums[i]]>1 && nums[i]>maxi){
            maxi=nums[i];
        }
        ans[i]=maxi;
        sum+=nums[i];
    }
    count.clear();
    maxi=0;
    for(int i=0;i<n;i++){
        count[ans[i]]++;
        if(count[ans[i]]>1 && ans[i]>maxi){
            maxi=ans[i];
        }
        sum+=ans[i];
        ans[i]=maxi;
    }
    int i=0;
    while(i<n)
    {
        sum += (ans[i]*(n-i));
        i++;
    }
    cout<<sum<<endl;
    return;
}
//2 2 3
//0 2 2
//0 0 2

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}