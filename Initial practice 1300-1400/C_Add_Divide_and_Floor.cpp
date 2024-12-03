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

void helper(vector<ll>& nums,int n)
{
    sort(nums.begin(),nums.end());
    ll diff = nums[n-1] - nums[0];
    if(diff==0){
        cout<<0<<endl;
        return;
    }
    int operations = (floor(log2(diff)))+1;
    if(operations>n){
        cout<<operations<<endl;
        return;
    }
    cout<<operations<<endl;
    pll p;
    p.first=nums[0];
    p.second=nums[n-1];
    while(p.first!=p.second){
        if(p.first%2!=0 && p.second%2==0){
            p.first=floor((p.first+1)/2);
            p.second=floor((p.second+1)/2);
            cout<<1<<" ";
            continue;
        }
        cout<<0<<" ";
        p.first = floor(p.first/2);
        p.second = floor(p.second/2);
    }
    cout<<endl;
    return;
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