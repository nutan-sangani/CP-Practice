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

bool canMake(ll sum,ll twoCount,ll sixCount){
    ll sixMultiple = min<ll>(sum/6,sixCount);
    ll rem = sum-sixMultiple*6LL;
    ll twoMultipleNeeded = rem/2;
    if(twoMultipleNeeded<=twoCount) return true;
    return false;
}

void solve(){
    string s;
    cin>>s;
    ll sum=0;
    ll twoCount=0;
    ll sixCount=0;
    int n = s.size();
    forn(0,n){
        ll val = s[i]-'0';
        sum+=val;
        if(val==2){
            twoCount+=1;
        }
        if(val==3){
            sixCount+=1;
        }
    }
    ll rem = 9-sum%9;
    if(rem==9) rem=0;
    ll maxPossible = sixCount*6LL+2LL*twoCount;
    ll multiple = (maxPossible-rem)/9+2;
    int i=1;
    if(rem%2==0){
        i=0;
    }
    while(i<=multiple){
        if(canMake(rem+i*9LL,twoCount,sixCount)){
            cout<<"YES\n";
            return;
        }
        i+=2;
    }
    cout<<"NO\n";
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