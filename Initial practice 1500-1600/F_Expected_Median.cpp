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

vecll factorial(2e5+5,1);

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


ll nCr(ll n,ll r){
    if(r>n) return 0LL;
    // else if(r==n) return 1LL;
    // ll a = getFactorial(n)%mod;
    // ll b = getFactorial(r);
    // b*=getFactorial(n-r);
    // b%=mod;
    // return (a/b)%mod; this doesnt work, as (a/b)%mod != ((a%mod)/(b%mod))%mod. uske liye modular multiplicative
    //inverse lena padega.
    //ie inverse of b.
    //b_inverse = (b^(mod-2)%mod)
    //b^(mod-2) is calculated using binary exponentiation

    ll numerator = factorial[n]%mod;
    ll denominator = (factorial[r]*factorial[n-r]*1LL)%mod;
    denominator = binaryExponent(denominator,mod-2,mod);
    return (numerator*denominator*1LL)%mod;
}

void helper(vecll& nums,ll n,ll k)
{
    ll oneCount = 0;
    ll zeroCount = 0;
    ll sum = 0;
    forn(0,n){
        if(nums[i]==1) oneCount++;
        else zeroCount++;
    }
    int zeroLimit = k/2; //8
    int i=0;
    while(i<=zeroLimit){
        int ones = k - i; //17
        int zeros = i;
        ll temp = nCr(oneCount,ones) * nCr(zeroCount,zeros);
        // cout<<oneCount<<" "<<ones<<endl;
        temp%=mod;
        sum+=temp;
        sum%=mod;
        i++;
    }
    cout<<sum<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    forn(2,2e5+5){
        factorial[i] = (factorial[i-1]*i*1LL)%mod;
    }
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vecll nums(n,0);
        forn(0,n) cin>>nums[i];
        // cout<<binaryExponent(2,5,mod)<<endl;
        helper(nums,n,k);
        // cout<<nCr(34,17)<<endl;
    }
    return 0;
}