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

ll getNextMultiple(ll next,ll limit){
    ll divisible = limit/next;
    ll temp=next*(divisible+1LL);
    return temp;
}

void helper(vector<ll>& nums,int n)
{
    ll count=0;
    count=nums[0];
    for(int i=1;i<n;i++){
        ll next = nums[i];
        count = getNextMultiple(next,count);
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