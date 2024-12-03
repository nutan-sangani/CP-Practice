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

void helper(vecll& nums,ll n)
{
    vecll ans;
    ans.pb(1000);
    // if(nums[0]%2==0){
    //     ans.pb(nums[0]+1+1000);
    // }
    // else ans.pb(nums[0]+2+1000);
    for(int i=1;i<n;i++){
        int multiple=1;
        // if(ans[i-1]>10000){
        //     if(nums[i-1]%2!=0){
        //         multiple=2;
        //     }

        // }
        // if(nums[i-1]%2==1){
        //     multiple=2;
        // }
        ll nn = multiple*ans[i-1]*1LL+nums[i-1];
        ans.pb(nn);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vecll nums(n-1);
        for(int i=0;i<n-1;i++){
            cin>>nums[i];
        }
        helper(nums,n);
    }
    return 0;
}