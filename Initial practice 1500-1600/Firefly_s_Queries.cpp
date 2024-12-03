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

ll getRotationalPrefixSum(vecll& a,vecll& ps,ll rotation,ll index){
    ll prev = ps[rotation-1];
    ll last = rotation+index-1;
    ll ans = ps[last] - prev;
    return ans;
}

ll findSum(vecll& ps,vecll& a,ll x,ll n,ll totalSum)
{
    ll multiple = x/n;
    ll sum = (1LL*multiple*totalSum);
    ll index = x%n;
    ll extra = getRotationalPrefixSum(a,ps,multiple+1,index);
    sum+=extra;
    return sum;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vecll a(n+n+1,0);
        vecll ps(2*n+1,0);
        ll sum=0;
        forn(1,n+1){
            ll axis;
            cin>>axis;
            a[i]=a[i+n]=axis;
            sum+=axis;
        }
        ll totalSum = sum;
        sum=0;
        forn(1,2*n+1){
            sum+=a[i];
            ps[i]=sum;
        }
        forn(0,q){
            ll l,r;
            cin>>l>>r;
            ll ans = 0;
            ll prevSum,rSum;
            prevSum = findSum(ps,a,l-1,n,totalSum);
            rSum = findSum(ps,a,r,n,totalSum);
            cout<<rSum - prevSum<<endl;
        }
    }
    return 0;
}