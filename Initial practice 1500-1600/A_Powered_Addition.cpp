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

int findTime(ll diff){
    int maxPosition=0;
    for(int i=0;i<64;i++){
        if((diff>>i)&1!=0){
            maxPosition = i;
        }
    }
    return maxPosition;
}

void helper(vecll& nums,int n)
{
    int maxTime=0;
    for(int i=1;i<n;i++)
    {
        ll diff = nums[i]-nums[i-1];
        if(diff>=0){
            continue;
        }
        else{
            int ans = findTime(abs(diff));
            nums[i]+=abs(diff);
            maxTime = max(ans+1,maxTime);
        }
    }
    cout<<maxTime<<endl;
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
//2 -1 = -3 -> 3 = 2
//-1+3=2 -3 = -5 -> 3 ie 4
//4 -4 = 8 -> 4
//2 -1 0 3 

//1 7 6 5
//1
//2