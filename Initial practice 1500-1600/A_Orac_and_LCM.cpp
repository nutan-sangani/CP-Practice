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

void helper(int n,vecll& nums)
{
    ll ans=1;
    ll maxi=-1;
    forLoop
        maxi = max<ll>(maxi,nums[i]);
    ll root = sqrt(maxi)+1;
    ll i=2;
    while(i<=root)
    {
        int smallest=INT_MAX;
        int secondSmallest=INT_MAX;
        for(int j=0;j<n;j++){
            int temp=0;
            while(nums[j]!=1 && nums[j]%i==0){
                temp++;
                nums[j]/=i;
            }
            if(temp<=smallest){
                secondSmallest=smallest;
                smallest=temp;
            }
            else if(temp<secondSmallest && temp>smallest){
                secondSmallest = temp;
            }
        }
        if(secondSmallest!=INT_MAX)
            ans*=pow(i,secondSmallest);
        i++;
    }
    sort(nums.begin(),nums.end());
    if(ans==1 && n==2 && nums[0]!=nums[1]){
        ans*=nums[0];
        ans*=nums[1];
        cout<<ans<<endl;
        return;
    }
    if(i>=1 && (nums[0]==nums[n-1] || nums[1]==nums[n-1])){
        ans*=nums[1]; //for single prime factor with val greater than root(maxi)
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    FASTIO
    
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        if(n==1)
            cout<<nums[0];
        else 
            helper(n,nums);
    }
    return 0;
}
//2,3,5
//lcm = 6,15,10
//2*3 , 3*5, 2*5
//ans = 3

//3,3
//lcm = 

//edge cases in such sums are combination of all primes, or all same primes or all no primes. and all such arrays of size 2