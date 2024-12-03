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



void helper(vecll& nums,ll n,ll k)
{
    ll maxi=-1;
    // vecll pf(n);
    ll sum=0;
    // pf[0]=nums[0];
    // for(int i=1;i<n;i++)
    //     pf[i]=(pf[i-1]+nums[i]);
    for(int i=0;i<=n;i++){
        int j=0;
        ll temp=0;
        while((i+j)<n && j<=31){
            temp+=(nums[i+j]>>(j+1));
            j++;
        }
        maxi = max<ll>(sum+temp-i*k,maxi);
        if(i<n)
            sum+=nums[i];
    }
    // maxi=max<ll>(maxi,sum-k*n);
    cout<<maxi<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,k);
    }
    return 0;
}