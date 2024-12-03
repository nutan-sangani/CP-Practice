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

void helper(vecll &a,vecll& b,int n)
{
    omll indexes;
    forLoop
    {
        indexes[b[i]]=i;
    }
    int count=0;
    vecll maxReach(n);
    ll maxReachTillNow=0;
    maxReach[0]=0;
    for(int i=0;i<n;i++){
        maxReachTillNow = max<ll>(maxReachTillNow,indexes[a[i]]);
        if(i!=0)
            maxReach[i]=maxReachTillNow;
    }
    for(int i=0;i<n;i++){
        if(indexes[a[i]]<maxReach[i]){
            count++;
        }
    }
    cout<<count<<endl;
    return;
}
//3 5 2 1 4
//0 1 3 3 4
//0 0 1 0 

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll a(n);
    vecll b(n);
    forLoop
        cin>>a[i];
    forLoop
        cin>>b[i];
    helper(a,b,n);
    return 0;
}