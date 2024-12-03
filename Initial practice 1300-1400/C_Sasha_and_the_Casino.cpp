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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int binarySearch(ll low,ll high,ll prevSum,ll multiple)
{
    while(low<high){
        ll mid = (low+high)/2;
        ll gains = multiple*mid;
        ll losses = prevSum+mid;
        if(gains>losses){
            high = mid;
        }
        else{
            low=mid+1;
        }
    }
    ll gains = multiple*high;
    ll losses = prevSum+high;
    if(gains>losses)
        return high;
    return -1;
}

void helper(ll k,ll x,ll a)
{
    ll sum=0;
    ll prevSum=0;
    for(int i=0;i<=x;i++){
        ll bet = binarySearch(1,a,prevSum,k);
        if(bet==-1){
            cout<<"NO"<<endl;
            return;
        }
        prevSum+=bet;
    }
    if(prevSum<=a){
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
        ll k,x,a;
        cin>>k>>x>>a;
        helper(k,x,a);
    }
    return 0;
}