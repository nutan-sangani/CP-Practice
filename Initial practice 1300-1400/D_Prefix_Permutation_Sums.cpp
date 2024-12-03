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
    vecll notPresent;
    vecll extraPresent;
    vecll diff;
    for(int i=0;i<n-1;i++){
        ll curr,prev;
        prev=i>0 ? nums[i-1] : 0;
        curr = nums[i];
        diff.push_back(curr-prev);
        // cout<<diff[i]<<" ";
    } //6,2,4,3
    map<ll,int> isPresent;
    for(int i=0;i<n-1;i++){
        if(diff[i]>n || isPresent[diff[i]]>0){
            extraPresent.pb(diff[i]);
        }
        else{
            isPresent[diff[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(isPresent[i]==0){
            notPresent.pb(i);
        }
    }
    if(notPresent.size()==1 && extraPresent.size()==0){
        cout<<"YES"<<endl;
    }
    else if(notPresent.size()==2 && (extraPresent.size()==1 && notPresent[0]+notPresent[1]==extraPresent[0])){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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
        int m;
        cin>>m;
        n=m-1;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,m);
    }
    return 0;
}