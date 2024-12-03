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

vecll findAllPrimes(ll upperRange){
    vector<ll> smallestPrime(upperRange+3);
    int n = upperRange+2;
    for(int i=0;i<n;i++){
        smallestPrime[i]=i;
    }
    int i=2;
    while(i<=(sqrt(n)+2)){
        if(smallestPrime[i]==i){
            int j=2*i;
            while(j<=(upperRange+2)){
                if(smallestPrime[j]==j)
                    smallestPrime[j]=i;
                j+=i;
            }
        }
        i++;
    }
    return smallestPrime;
}

void findAllFactor(vecll& smallestPrime,vecll& ans,ll n){
    ll copy=n;
    while(copy>1){
        if(ans.empty() || ans.back()!=smallestPrime[copy])
            ans.pb(smallestPrime[copy]);
        copy/=smallestPrime[copy];
    }
    // int j=0;
    // int i=allPrimes[j];
    // // vecll ans;
    // while(i<=(sqrt(n)+2)){
    //     if(n%i==0){
    //         while(n%i==0)
    //             n/=i;
    //         ans.pb(i);
    //     }
    //     j++;
    //     i=allPrimes[j];
    // }
    // if(n!=1){
    //     ans.pb(n);
    // }
    return;
}

void helper(vector<pll>& nums,vecll& smallestPrime,int tCopy)
{
    for(int i=0;i<tCopy;i++){
        ll a,b;
        a=nums[i].first;
        b=nums[i].second;
        if(abs(a-b)==1){
            cout<<-1<<endl;
            continue;
        }
        else if(a%2==0 && b%2==0){
            cout<<0<<endl;
            continue;
        }
        else if(a%2!=0 && b%2!=0){
            if(gcd(a,b)!=1){
                cout<<0<<endl;
                continue;
            }
            cout<<1<<endl;
            continue;
        }
        else if(gcd(a,b)!=1){
            cout<<0<<endl;
            continue;
        }
        if(a>b){
            ll temp = a;
            a=b;
            b=temp;
        }
        ll diff = abs(a-b);
        vecll allFactors;
        findAllFactor(smallestPrime,allFactors,diff);
        ll ans=INT_MAX;
        for(auto x : allFactors){
            ll multiple = (a/x)+1;
            ll target = multiple*x;
            ans = min<ll>(ans,target-a);
        }
        cout<<ans<<endl;
    }
    return;
}
int main()
{
    FASTIO

    vecll smallestPrime = findAllPrimes(1e7);

    int t;
    cin>>t;
    int tCopy=t;
    int i=1;
    vector<pll> nums;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        nums.pb(mp(a,b));
    }
    helper(nums,smallestPrime,tCopy);
    return 0;
}