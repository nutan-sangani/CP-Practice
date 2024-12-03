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

bool isValid(vector<pll>& intervals,vecll& change,ll n,ll m,ll q,ll mid){
    vecll nums(n,0);
    for(int i=0;i<mid;i++){
        nums[change[i]-1]=1;
    }
    for(int i=1;i<n;i++){
        nums[i]+=nums[i-1];
    }
    for(int i=0;i<m;i++){
        int a,b;
        a=intervals[i].first-1;
        b=intervals[i].second-1;
        int intervalSize = b-a+1;
        int prev = a>0 ? nums[a-1] : 0;
        int countOnes = nums[b] - prev;
        int countZeros = intervalSize - countOnes;
        if(countOnes > countZeros){
            return true;
        }
    }
    return false;
}

void helper(vector<pll>& intervals,vecll& change,ll n,ll m,ll q)
{
    ll low,high;
    low=1;
    high=q;
    int flag=0;
    while(low<=high){
        ll mid = (low+high)/2;
        if(isValid(intervals,change,n,m,q,mid)){
            flag=1;
            high = mid-1;
        }
        else {
            low=mid+1;
        }
    }
    if(flag)
        cout<<low<<endl;
    else cout<<-1<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m,q;
        cin>>n>>m;
        vector<pll> intv(m);
        for(int i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            intv[i]=mp(a,b);
        }
        cin>>q;
        vecll change(q);
        for(int i=0;i<q;i++){
            cin>>change[i];
        }
        helper(intv,change,n,m,q);
    }
    return 0;
}