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

void helper(vecll &nums,int n)
{
    vecll ans(n,-1);
    forLoop
    {
        int reach = i+(nums[i]-1);
        if(reach<n){
            ans[reach]=max<ll>(ans[reach],nums[i]);
        }
        else{
            ans[n-1]=max<ll>(ans[n-1],n-i);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==-1){
            if(i+1>=n){
                ans[i]=1;
                continue;
            }
            else ans[i] = max<ll>(ans[i+1]-1,1);
        }
    }
    forLoop
        cout<<ans[i]<<" ";
    cout<<endl;
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
//1 2 3 3 3 3 3 3 
//first update
//0 1 2 3 4 5 6
//1 1 2 2 4 4 6
//1 1 1 2 2 

//0 1 2 3 4 5 6 7
//3 3 3 3 3 6 6 7
//1 2 3 3 3 3 3 3
//1 2 3 3 3 3 3 2 