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

void helper(vecll& nums,vector<pair<ll,ll>>& interv,int n,int q)
{
    vecll prefix(n,0);
    for(int i=0;i<q;i++)
    {
        prefix[interv[i].first-1]+=1;
        if(interv[i].second<n)
            prefix[interv[i].second]-=1;
    }
    ll sum=0;
    vecll multiple(n);
    forLoop
    {
        sum+=prefix[i];
        multiple[i]=sum;
    }
    sum=0;
    sort(multiple.begin(),multiple.end());
    sort(nums.begin(),nums.end());
    forLoop
    {
        sum+=(nums[i]*multiple[i]*1LL);
    }
    cout<<sum<<endl;
    return;
}
//1,2 2,3 1,3
//2 1 -1
//2 1 -1 -2
//2 3 2

int main()
{
    FASTIO
    
    int n,q;
    cin>>n>>q;
    vecll nums(n);
    forLoop
        cin>>nums[i];
    vector<pair<ll,ll>> interv(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        interv[i] = mp(a,b);
    }
    helper(nums,interv,n,q);
    return 0;
}