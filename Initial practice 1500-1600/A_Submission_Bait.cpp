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

void helper()
{
    
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
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        int maxi=-1;
        unordered_map<int,int> mapi;
        vecll unique;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(mapi[nums[i]]==0){
                unique.pb(nums[i]);
            }
            mapi[nums[i]]++;
        }
        for(int i=unique.size()-1;i>=0;i--){
            if(mapi[unique[i]]%2!=0){
                cout<<"YES"<<endl;
                break;
            }
            else if(i==0){
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}