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

void helper(vector<ll>nums,int n)
{
    // unordered_map<ll,vector<ll>> multiples;
    // vector<ll> diff(n-1);
    // // for(int i=0;i<n;i++){
    // //     cout<<nums[i]<<endl;
    // // }
    // for(int i=n-2;i>=0;i--){
    //     diff[i] = (nums[i+1]-nums[i]);
    // }
    // sort(diff.begin(),diff.end());
    // for(ll i=1;i<(sqrt(diff[n-2])+2);i++){ //will take ((n^0.5)*logn) time
    //     ll j=1;
    //     while(i*j<=(diff[n-2]+2)){
    //         multiples[i*j*1LL].push_back(i);
    //         j++;
    //     }
    // }
    // map<ll,vector<ll>> largest;
    // for(int i=0;i<diff.size();i++){
    //     vector<ll> temp = multiples[diff[i]];
    //     for(int j=0;j<temp.size();j++){
    //         largest[temp[j]].pb(diff[i]);
    //     }
    //     // cout<<diff[i]<<endl;
    // }
    // ll maxi=-1;
    // for(auto &it:largest){
    //     if(it.second.size()==n-1){
    //         maxi=it.first;
    //     }
    // }
    // // cout<<maxi<<endl;
    // unordered_map<ll,int> isPresent;
    // for(int i=0;i<n;i++){
    //     isPresent[nums[i]]=1;
    // }
    if(n==1) {
        cout<<1<<endl;
        return;
    }
    sort(nums.begin(),nums.end());
    ll max=nums[n-1];
    ll maxi=max-nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]!=max)
            maxi=gcd(maxi,(max-nums[i]));
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll diffi = max-nums[i];
        ans+=(diffi/maxi);
    }
    ll z=0;
    int i=0;
    int k=0;
    for(i=n-1;i>0;i--){
        if(nums[i]-maxi != nums[i-1]){
            z=nums[i]-maxi;
            k++;
            break;
        }
    }
    if(k==0){
        z=nums[0]-maxi;
    }
    ans+=(max-z)/maxi;
    cout<<ans<<endl;
}
//1 1

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
