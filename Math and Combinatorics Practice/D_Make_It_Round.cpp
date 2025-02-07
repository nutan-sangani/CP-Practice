#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

pll getFactorAndCount(ll n){
    while(n%10==0) n/=10;
    pll ans;
    ll count=0;
    ans.first=-1;
    ans.second=-1;
    if(n%2==0){
        ans.first=2;
        while(n && n%2==0){
            n/=2;
            count+=1;
        }
        ans.second=count;
        return ans;
    }
    else if(n%5==0){
        ans.first=5;
        while(n%5==0){
            n/=5;
            count+=1;
        }
        ans.second=count;
        return ans;
    }
    return ans;
}

ll countOfDigits(ll n){
    ll count=0;
    while(n){
        n/=10;
        count+=1;
    }
    return count;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    pll multipleAndCount = getFactorAndCount(n);
    ll maxAns = 0;
    if(multipleAndCount.first==2){
        ll multiple = pow(5,multipleAndCount.second);
        while(multiple){
            ll divisor = k/multiple;
            ll countOfRemDigits = countOfDigits(divisor)-1;
            if(countOfRemDigits<0){
                multiple/=5;
                continue;
            }
            ll tens = pow(10,countOfRemDigits);
            ll leftMostDigit = (divisor/tens)*multiple;
            leftMostDigit*=tens;
            ll ans = n*leftMostDigit;
            maxAns=ans;
            break;
        }
    }
    else if(multipleAndCount.first==5){
        ll multiple = pow(2,multipleAndCount.second);
        while(multiple){
            ll divisor = k/multiple;
            ll countOfRemDigits = countOfDigits(divisor)-1;
            if(countOfRemDigits<0){
                multiple/=2;
                continue;
            }
            ll tens = pow(10,countOfRemDigits);
            ll leftMostDigit = (divisor/tens)*multiple;
            leftMostDigit*=tens;
            ll ans = n*leftMostDigit;
            maxAns=ans;
            break;
        }
    }
    else{
        ll digitCount = countOfDigits(k);
        ll tens = pow(10,digitCount-1);
        ll leftMostDigit = k/tens;
        leftMostDigit*=tens;
        maxAns = n*leftMostDigit;
    }
    cout<<maxAns<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}