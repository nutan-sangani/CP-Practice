#include <iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void helper(vector<ll>& nums,ll n,ll k)
{
    vector<ll> diff;
    for(int i=0;i<k-1;i++){
        ll difference = nums[i+1]-nums[i]-1;
        diff.push_back(difference);
    }
    diff.push_back(n-((nums[k-1]-nums[0]-1)+2));
    sort(diff.begin(),diff.end());
    reverse(diff.begin(),diff.end());

    ll ans=0;
    int counter=0;
    ll safe=0;
    int size = diff.size();
    for(int i=0;i<size;i++){
        ll rem = diff[i] - 2*counter;
        if(rem<=0) break;
        safe+=(rem-1);
        if(rem==1) safe+=1;
        counter+=2;
    }
    cout<<(n-safe)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n;
        cin>>k;
        // ll nums[k];
        vector<ll> nums;
        for(int i=0;i<k;i++){
            ll num;
            cin>>num;
            nums.push_back(num);
        }
        sort(nums.begin(),nums.end());
        helper(nums,n,k);
    }
    return 0;
}
//1 11 21 31 41
//9,9,9,9,0
//safe = 8+4=12