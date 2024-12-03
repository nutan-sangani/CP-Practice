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
#define itr(a) a.begin(),a.end()

using namespace std;

void helper(vecll& nums,int n)
{
    ll ans=0;
    int i=0;
    int j=n-1;
    ll startSum=0;
    sort(itr(nums));
    while(i<=j){
        
        if(i==j){
            int movesReq=1;
            if(nums[j]>1)
                movesReq = ((startSum+nums[j]+1)/2)+1;
            int diff = movesReq - startSum;
            // cout<<diff<<" "<<movesReq<<endl;
            ans+=diff;
            cout<<ans<<endl;
            return;
        }
        startSum+=nums[i];
        ans+=nums[i];
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        if(startSum>nums[j]){
            startSum-=nums[i];
            ll diff = nums[j] - startSum;
            ans-=nums[i];
            nums[i]-=diff;
            startSum+=diff;
            ans+=diff;
        }
        else i++;
        if(startSum==nums[j]){
            ans+=1LL;
            startSum=0;
            j--;
        }
    }
    cout<<ans<<endl;
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
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}
//3,4,4,4,6
//1,4,4 ans=7
//1 ans=7+4+1
//1