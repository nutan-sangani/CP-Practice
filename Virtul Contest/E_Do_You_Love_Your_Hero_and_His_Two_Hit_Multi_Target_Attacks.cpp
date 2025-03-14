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

vecll dp(100001,-1); //this stores min rem needed
vecll movei(100001,-1);

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

ll memoize(ll k,umll& moves){
    if(k<0) return -1;
    else if(k==0) return 0;
    else if(dp[k]!=-1) return dp[k];
    ll minRem = LLONG_MAX;
    ll minMove = -1;
    for(auto it : moves){
        ll temp = memoize(k-it.first,moves);
        if(temp==-1){
            continue;
        }
        ll needed = temp+it.second;
        if(minRem>needed){
            minRem = needed;
            minMove = it.first;
        }
    }
    if(minMove==-1){
        return dp[k] = -1;
    }
    movei[k] = minMove;
    return dp[k] = minRem;
}

void solve(umll& moves){
    ll k;
    cin>>k;
    if(k==0){
        cout<<0<<endl;
        return;
    }
    memoize(k,moves);
    if(dp[k]>500){
        cout<<-1<<endl;
        return;
    }
    vecll cnt;
    while(k>0){
        cnt.pb(moves[movei[k]]);
        k-=movei[k];
    }
    ll count=0;
    vector<ll> ans;
    for(auto it : cnt){
        forn(0,it){
            ans.pb(count);
        }
        count+=1;
    }
    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it<<" "<<count<<endl;
        count+=1;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    umll moves;
    forn(0,499){
        ll temp = sumOfnNaturalNumbers(i+1);
        moves[temp]=i+2;
    }
    while(t--)
    {
        solve(moves);
    }
    return 0;
}