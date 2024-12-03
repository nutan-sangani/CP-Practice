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

ll binarySearch(ll low,ll high,ll limit,ll fixed){
    while(low<=high){
        ll mid = (low+high)/2;
        ll val = sqrtl(pow(mid,2)+pow(fixed,2));
        if(val>=limit){
            high = mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return high;
}

ll bs2(ll low,ll high,ll lowerLimit,ll fixed){
    while(low<high){
        ll mid = (low+high)/2;
        ll val = sqrtl(pow(mid,2)+pow(fixed,2));
        if(val<lowerLimit){
            low=mid+1;
        }
        else{
            high = mid;
        }
    }
    return high;
}

void helper(ll n)
{
    ll ans=0;
    if(n==1){
        cout<<8<<endl;
        return;
    }
    else if(n==2){
        cout<<16<<endl;
        return;
    }
    ll temp = 0;
    for(int i=1;i<=n;i++){
        
    }
    // temp = binarySearch(1,n,n+1,n);
    // temp*=2;
    // // cout<<temp<<endl;
    // temp*=4;
    // ans+=temp;
    // ans+=4;
    // cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        helper(n);
    }
    return 0;
}