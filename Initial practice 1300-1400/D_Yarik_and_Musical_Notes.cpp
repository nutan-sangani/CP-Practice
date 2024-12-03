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
    map<ll,ll> map;
    ll count=0;
    forLoop
    {
        count+=map[nums[i]];
        if(nums[i]==1){
            count+=map[2];
        }
        else if(nums[i]==2){
            count+=map[1];
        }
        map[nums[i]]++;
    }
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
        vector<ll> nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}