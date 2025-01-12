#include<iostream>
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

class MyComp{
    public:
    bool operator()(const pair<pll,ll>& a,const pair<pll,ll>& b){ //for max heap and ascending sort in vector
        return a.first.first<b.first.first;
    }
};

class MyComp1{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

ll findNextValidIndex(vector<pll>& sortedStartOfRanges,ll val){
    auto itri = lower_bound(sortedStartOfRanges.begin(),sortedStartOfRanges.end(),make_pair(val,-1),MyComp1());
    if(itri==sortedStartOfRanges.end()) return -1;
    return (*itri).second;
}

ll findMaxReward(vector<pair<pll,ll>>& data,vecll& dp,int index,vector<pll>& sortedStartOfRanges,ll n){
    if(index>=n) return 0;
    else if(dp[index]!=-1) return dp[index];
    //dp[index] gives max reward starting from index, since its independent of everything
    ll reward = findMaxReward(data,dp,index+1,sortedStartOfRanges,n);
    ll nextIndex = findNextValidIndex(sortedStartOfRanges,data[index].first.second+1);
    if(nextIndex!=-1){
        reward = max<ll>(reward,findMaxReward(data,dp,nextIndex,sortedStartOfRanges,n)+data[index].second);
    }
    reward = max<ll>(reward,data[index].second);
    return dp[index]=reward;
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<pll,ll>> data; //start,end,reward
    forn(0,n){
        ll a,b,c;
        cin>>a>>b>>c;
        data.pb(mp(mp(a,b),c));
    }
    sort(itr(data),MyComp());
    vector<pll> sortedStartOfRanges;
    forn(0,n){
        sortedStartOfRanges.pb(mp(data[i].first.first,i));
    }
    vecll dp(n+1,0);
    // cout<<findMaxReward(data,dp,0,sortedStartOfRanges,n)<<endl;
    //works and acc, lets try to tabulate

    // forn(0,n+1){ //iss direction me jayenge toh findnextValid wala fn wapis alg likhna padega 
    // }

    for(int i=n-1;i>=0;i--){
        ll ending = data[i].first.second;
        ll nextIndex = findNextValidIndex(sortedStartOfRanges,ending+1);
        ll reward = dp[i+1];
        if(nextIndex!=-1)
            reward = max<ll>(reward,dp[nextIndex]+data[i].second);
        reward = max<ll>(reward,data[i].second);
        dp[i]=reward;
    }
    cout<<dp[0]<<endl;
}
int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}