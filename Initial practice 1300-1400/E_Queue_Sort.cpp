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

bool isSorted(vector<ll>& nums){
    for(int i=0;i<nums.size()-1;i++)
        if(nums[i]>nums[i+1])
            return false;
    return true;
}

void helper(vector<ll>& nums,int n)
{
    if(isSorted(nums)){
        cout<<0<<endl;
        return;
    }
    int smallestIndex=0;
    for(int i=0;i<n;i++){
        if(nums[i]<nums[smallestIndex]){
            smallestIndex=i;
        }
    }
    vector<ll> nn;
    for(int i=smallestIndex;i<n;i++){
        nn.pb(nums[i]);
    }
    if(isSorted(nn)){
        cout<<smallestIndex<<endl;
        return;
    }
    else{
        cout<<-1<<endl;
        return;
    }
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
        vector<ll> nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}