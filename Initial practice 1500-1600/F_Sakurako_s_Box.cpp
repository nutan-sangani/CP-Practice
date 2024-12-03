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

ll binaryExponent(ll a,int b,ll m){ //(a^b)%m
    ll ans = 1;
    ll base = a;
    while(b>0){
        if(b & 1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        b/=2;
    }
    return ans%mod;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll a(n,0);
        ll sum=0;
        vecll ps(n,0);
        forn(0,n){
            cin>>a[i];
            sum+=a[i];
            ps[i]=sum;
        }
        ll sumT=sum;
        sum=0;
        forn(0,n){
            ll diff = (sumT - ps[i])%mod;
            sum+=(a[i]*(diff));
            sum%=mod;
        }
        ll total = (n*(n-1+0LL)*1LL)/2LL;
        ll inverse = binaryExponent(total,mod-2,mod);
        sum*=inverse;
        sum%=mod;
        cout<<sum<<endl;
    }
    return 0;
}