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
    int i=0;
    ll ans=0;
    bool flag=0;
    while(i<n){
        if(nums[i]==0){
            i++;
        }
        else break;
    }
    ll temp=0;
    while(i<n){
        if(nums[i]==1){
            ans+=temp;
            i++;
            temp=0;
        }
        else{
            temp++;
            i++;
        }
    }
    cout<<ans<<endl;
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
        {
            cin>>nums[i];
        }
        helper(nums,n);
    }
    return 0;
}