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

void helper(vecll & nums,int n)
{
    ll maxi=INT_MIN;
    int maxIndex=-1;
    vector<pair<int,int>> operations;
    forLoop
        if(maxi<abs(nums[i])){
            maxIndex=i;
            maxi=abs(nums[i]);
        }
    forLoop
        if(i!=maxIndex){
            operations.pb(mp(i+1,maxIndex+1));
        }
    if(nums[maxIndex]<0){
        for(int i=n-2;i>=0;i--)
            operations.pb(mp((i+1),i+2));
    }
    else{
        for(int i=1;i<n;i++)
            operations.pb(mp((i+1),i));
    }
    cout<<operations.size()<<endl;
    for(int i=0;i<operations.size();i++){
        cout<<operations[i].first<<" "<<operations[i].second<<endl;
    }
    // cout<<endl;
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