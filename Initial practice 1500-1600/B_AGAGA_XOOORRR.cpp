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
    ll arrXor = 0; 
    forLoop
    {
        arrXor^=nums[i];
    }
    if(arrXor==0){
        cout<<"YES"<<endl;
        return;
    }
    ll tempXor=0;
    int zeroCount,tempCount;
    zeroCount=tempCount=0;
    for(int i=0;i<n;i++){
        tempXor^=nums[i];
        if(tempXor==0){
            zeroCount++;
        }
        if(tempXor==arrXor){
            tempCount++;
            tempXor=0;
        }
    }
    if(tempXor==0 && tempCount-zeroCount>=2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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
//2,3,1,10
//0^10=10
//