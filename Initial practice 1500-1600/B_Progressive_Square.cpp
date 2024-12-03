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

void helper(ll c,ll d,ll n,vector<vector<ll>>& nums,map<ll,ll>& map,ll min)
{
    vector<vector<ll>> temp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                temp[i][j]=min;
                map[min]--;
            }
            else if(j==0){
                temp[i][j]=temp[i-1][j]+c;
                if(map[temp[i][j]]==0){
                    cout<<"NO"<<endl;
                    return;
                }
                map[temp[i][j]]--;
            }
            else{
                temp[i][j]=temp[i][j-1]+d;
                if(map[temp[i][j]]==0){
                    cout<<"NO"<<endl;
                    return;
                }
                map[temp[i][j]]--;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c,d;
        cin>>n>>c>>d;
        vector<vector<ll>> nums(n,vector<ll>(n,0));
        map<ll,ll> map;
        ll min=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>nums[i][j];
                map[nums[i][j]]++;
                if(nums[i][j]<min){
                    min=nums[i][j];
                }
            }
        }
        helper(c,d,n,nums,map,min);
    }
    return 0;
}