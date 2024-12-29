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
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

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
    bool operator()(const pll& a,const pll& b) const { //here constant is necessary
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

auto findSuitableParititonToBreak(set<pll,MyComp>& partitions,ll location){
    auto lb = partitions.lower_bound(mp(location,0)); //since there wont be a duplicate, 0 doesnt matter
    //but will have to find some other way.

    //if iske equal hua toh kya, or greater hua toh kya? ya end hua toh kya?
    if(lb==partitions.end()){
        lb--;
        return lb;
    }
    else if((*lb).first==location){
        return lb;
    }
    else{
        --lb;
        return lb;
    }
}

void solve(){
    ll n;
    cin>>n;
    multiset<ll> gaps;
    set<pll,MyComp> partitions;
    partitions.insert(mp(0,n));
    gaps.insert(n);
    ll m;
    cin>>m;
    forn(0,m){
        ll location;
        cin>>location;
        auto foundPartition = findSuitableParititonToBreak(partitions,location);
        partitions.erase(foundPartition);
        pll foundPartitionRange = *foundPartition;
        ll gap = (foundPartitionRange.second - foundPartitionRange.first);
        auto it = gaps.find(gap);
        gaps.erase(it);
        pll left,right;
        left.first=foundPartitionRange.first;
        left.second=location;
        right.first = location;
        right.second = foundPartitionRange.second;
        if(right.first<right.second){
            gap = right.second - right.first;
            gaps.insert(gap);
            partitions.insert(right);
        }
        if(left.first<left.second){
            gap = left.second - left.first;
            gaps.insert(gap);
            partitions.insert(left);
        }
        ll max = *(gaps.rbegin());
        cout<<max<<" ";
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}