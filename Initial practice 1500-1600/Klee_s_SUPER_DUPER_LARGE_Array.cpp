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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

ll helper(ll n)
{
    if(n%2==0) return (n/2LL)*(n+1LL);
    else return ((n+1LL)/2LL)*n;
}

ll h2(ll number,ll firstNumber,ll lastNumber){
    ll pos = helper(number) - helper(firstNumber - 1);
    ll neg = helper(lastNumber) - helper(number);
    ll val = abs(pos - neg);
    return val;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll firstNumber = k;
        ll lastNumber = n+k-1;
        ll minX = LLONG_MAX;
        ll low,high;
        low = firstNumber;
        high = lastNumber;
        while(low<=high){
            ll mid = (low+high+0LL)/2LL;
            ll prev = mid - 1;
            ll midVal = h2(mid,firstNumber,lastNumber);
            ll prevVal = h2(prev,firstNumber,lastNumber);
            minX = min<ll>(midVal,minX);
            minX = min<ll>(minX,prevVal);
            if(prevVal==0 || midVal==0){
                minX = 0;
                break;
            }
            else if(prevVal>midVal){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ll temp = h2(high,firstNumber,lastNumber);
        ll temp2 = h2(low,firstNumber,lastNumber);
        minX= min<ll>(min<ll>(temp,temp2),minX);
        cout<<minX<<endl;
    }
    return 0;
}