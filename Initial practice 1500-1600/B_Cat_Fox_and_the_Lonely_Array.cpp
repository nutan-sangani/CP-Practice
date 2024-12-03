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
    int maxDiff = 1;
    for(int i=0;i<=25;i++){
        int prev=-1;
        int tempDiff = 1;
        for(int j=0;j<n;j++){
            if(nums[j] & 1LL<<i){
                int diff = j-prev;
                prev=j;
                tempDiff = max(tempDiff,diff);
            }
        }
        if(prev!=-1){
            int diff = n - prev;
            tempDiff = max(tempDiff,diff);
        }
        maxDiff = max(tempDiff,maxDiff);
    }
    cout<<maxDiff<<endl;
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