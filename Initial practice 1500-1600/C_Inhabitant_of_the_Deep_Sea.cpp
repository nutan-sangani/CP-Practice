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
    ll l,r;
    l=(k+1)/2;
    r=k/2;
    int count=0;
    for(int i=0;i<n;i++){
        if(l>=nums[i]){
            l-=nums[i];
            nums[i]=0;
            count++;
        }
        else{
            nums[i]-=l;
            l=0;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(r>=nums[i]){
            count++;
            r-=nums[i];
            nums[i]=0;
        }
        else{
            nums[i]-=r;
            r=0;
            break;
        }
    }
    cout<<min<ll>(count,n)<<endl;
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
//7
//4 3
