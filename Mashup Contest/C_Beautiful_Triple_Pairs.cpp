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

string getHashString(ll a,ll b){
    string first = to_string(a);
    string second = to_string(b);
    return first+","+second;
}

string getHashString(ll a,ll b,ll c){
    string first = to_string(a);
    string second = to_string(b);
    string third = to_string(c);
    return first+","+second+","+third;
}

void helper(vecll& nums,int n)
{
    unordered_map<string,ll> exceptFirst;
    unordered_map<string,ll> exceptMid;
    unordered_map<string,ll> exceptLast;
    unordered_map<string,ll> allSame;
    for(int i=0;i<=n-3;i++){
        ll a,b,c;
        a=nums[i];
        b=nums[i+1];
        c=nums[i+2];
        string exceptFirstStr,exceptMidStr,exceptLastStr;
        exceptFirstStr = getHashString(b,c);
        exceptLastStr = getHashString(a,b);
        exceptMidStr = getHashString(a,c);
        exceptFirst[exceptFirstStr]++;
        exceptLast[exceptLastStr]++;
        exceptMid[exceptMidStr]++;
        string allSameStr = getHashString(a,b,c);
        allSame[allSameStr]++;
    }
    ll count=0;
    for(int i=0;i<=n-3;i++){
        ll a,b,c;
        a=nums[i];
        b=nums[i+1];
        c=nums[i+2];
        string exceptFirstStr,exceptMidStr,exceptLastStr;
        exceptFirstStr = getHashString(b,c);
        exceptLastStr = getHashString(a,b);
        exceptMidStr = getHashString(a,c);
        string allSameStr = getHashString(a,b,c);
        count+=(exceptFirst[exceptFirstStr]-allSame[allSameStr]);
        count+=(exceptLast[exceptLastStr]-allSame[allSameStr]);
        count+=(exceptMid[exceptMidStr]-allSame[allSameStr]);
    }
    cout<<count/2<<endl;
}
//1 2 1 2 1
//1 2 1, 2 1 2, 1 2 1
//first = 2 1, 1 2, 2 1
//mid = 1 1, 2 2, 1 1
//last = 1 2, 2 1, 1 2
//allSame = 2,1
//
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