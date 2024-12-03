#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define vecll vector<ll>
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vecll &a,ll n)
{
    ll count=(n*(n+1))/2LL;
    map<ll,ll> prevIndex;
    map<ll,ll> freq;
    vecll deletedFromFront(n);
    for(int i=0;i<n;i++){
        if(prevIndex[a[i]]!=0 || (a[0]==a[i] && i!=0)){
            int prevCount,nextCount;
            prevCount = prevIndex[a[i]]-deletedFromFront[prevIndex[a[i]]];
            nextCount = (n-1)-i;
            count-=prevCount;
            count-=nextCount;
            if(i<n-1)
                deletedFromFront[i+1] = (i>0 ? deletedFromFront[i]+1 : 1); 
        }
        else {
            if(i<n-1)
                deletedFromFront[i+1] = (i>0 ? deletedFromFront[i] : 0);
        }
        prevIndex[a[i]]=i;
        freq[a[i]]++;
    }
    // for(int i=0;i<n;i++){
    //     cout<<deletedFromFront[i]<<" ";
    // }
    // cout<<endl;
    for(auto &it : freq){
        if(it.second>1)
            count-=it.second;
    }
    cout<<count<<endl;
}
//55 - 8 - 7 - 5 - 1 - 2*4 = 26

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vecll a(n);
        forLoop
            cin>>a[i];
        helper(a,n);
    }
    return 0;
}
//for obvious reasons, this code wont work, since there's overlap, so in this kind of problems
//take care of overlapping, otherwise long time in debugging.

