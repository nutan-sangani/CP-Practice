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
    if(n==1){
        cout<<abs(nums[0]-nums[1])<<endl;
        return;
    }
    ll sum=0;
    for(int i=0;i<2*n;i++){
        sum+=(abs(nums[i]))*1LL;
    }
    if(n==2){
        ll temp=0;
        for(int i=0;i<2*n;i++){
            temp+=(abs(nums[i]-2))*1LL;
        }
        if(temp<sum)
            sum=temp;
    }
    cout<<sum<<endl;
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
        vecll nums(2*n);
        for(int i=0;i<2*n;i++){
            cin>>nums[i];
        }
        helper(nums,n);
    }
    return 0;
}