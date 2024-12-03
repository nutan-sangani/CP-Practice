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

void helper(ll n,ll x,ll y)
{
    ll score = x+y;
    ll minimum,maximum;
    ll minTarget = score+1;
    ll maxTarget = score;
    pll minRange,maxRange;
    minRange.first = max<ll>(1,minTarget - n);
    minRange.second = n;
    maxRange.first = 1;
    maxRange.second = min(maxTarget - 1,n);
    minimum = minRange.second - minRange.first + 1;
    maximum = maxRange.second - maxRange.first + 1;
    if((minRange.first<=x && minRange.second>=x) || (minRange.first<=y && minRange.second>=y)) minimum--;
    if((maxRange.first<=x && maxRange.second>=x) || (maxRange.first<=y && maxRange.second>=y)) maximum--;
    cout<<n-minimum<<" "<<(maximum+1)<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        helper(n,x,y);
    }
    return 0;
}