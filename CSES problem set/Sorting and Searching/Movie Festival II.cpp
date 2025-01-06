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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.second!=b.second)
            return a.second<b.second;
        else return a.first>b.first;
    }
};

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<pll> data;
    forn(0,n){
        ll a,b;
        cin>>a>>b;
        data.pb(mp(a,b));
    }
    sort(itr(data),MyComp());
    multiset<ll> set;
    ll count=0;
    forn(0,n){
        if(set.empty()){
            count+=1;
            set.insert(data[i].second);
        }
        else if(*set.begin() <= data[i].first){
            auto it = set.lower_bound(data[i].first);
            it--;
            set.erase(it);
            count+=1;
            set.insert(data[i].second);
        }
        else if(set.size()<k){
            set.insert(data[i].second);
            count+=1;
        }
    }
    cout<<count<<endl;
}
//pq = 69,72,78
int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}