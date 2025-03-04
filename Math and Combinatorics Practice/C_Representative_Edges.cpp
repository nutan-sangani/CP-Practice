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

void solve(){
    ll n;
    cin>>n;
    vecll a(n);
    forn(0,n) cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll minCount = LLONG_MAX;
    for(int gap=1;gap<n;gap++){
        for(int start=0;start<n;start++){
            um<string,ll> elementsWithDiff;
            ll maxi = -1;
            for(int i=start;i<n;i+=gap){
                int diff = a[i] - a[start];
                //count of elem = i - start + 1
                //count of elem in between = count of elem - 2
                int countOfJumpsInBetween = i - start + 1 - 2 + 1;
                int gcd = __gcd(diff,countOfJumpsInBetween);
                if(gcd!=0)
                {
                    diff/=gcd;
                    countOfJumpsInBetween/=gcd;
                }
                string diffS = to_string(diff);
                string jumps = to_string(countOfJumpsInBetween);
                diffS += ",";
                diffS += jumps;
                elementsWithDiff[diffS]+=1;
                maxi = max(maxi,elementsWithDiff[diffS]+1);
            }
            ll ops = n - maxi;
            minCount = min<ll>(ops,minCount);
            if(minCount==0){
                cout<<0<<endl;
                return;
            }
        }
    }
    cout<<minCount<<endl;
}
//tc ~= 100*100*log(100) ~ (n^2)*(logn)

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