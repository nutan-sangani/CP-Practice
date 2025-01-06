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

ll Ceil(ll a,ll b){
    if(b==0) return 0;
    if(a>=0)
        return a%b==0 ? a/b : ((a/b)+1);
    else return a/b;
}

void balanceBothSets(multiset<ll>& smaller,multiset<ll>& larger,ll smallerSize,ll largerSize,ll *smallerSum,ll *largerSum){
    while(larger.size()<largerSize){
        ll val = *(smaller.rbegin());
        auto it = smaller.find(val);
        smaller.erase(it);
        (*largerSum)+=val;
        (*smallerSum)-=val;
        larger.insert(val);
        // cout<<val<<endl;
    }
    while(smaller.size()<smallerSize){
        ll val = *(larger.begin());
        larger.erase(larger.begin());
        (*largerSum)-=val;
        (*smallerSum)+=val;
        smaller.insert(val);
        // cout<<val<<endl;
    }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    ll smallerSize,largerSize;
    smallerSize = Ceil(k,2); //this ensures that median is always the last element of smaller
    largerSize = k - smallerSize;
    // cout<<smallerSize<<" "<<largerSize<<endl;
    multiset<ll> smaller;
    multiset<ll> larger;
    ll largerSum=0, smallerSum=0;
    forn(0,k){
        smaller.insert(a[i]);
        smallerSum+=a[i];
    }
    balanceBothSets(smaller,larger,smallerSize,largerSize,&smallerSum,&largerSum);
    // cout<<
    ll start=0,end=k-1;
    vecll ans;
    while(end<n){
        ll median = *(smaller.rbegin());
        ll smallerDiff = abs(smallerSum - median*smallerSize);
        ll largerDiff = abs(largerSize*median - largerSum);
        ans.pb(smallerDiff+largerDiff);
        ll toBeRemoved,toBeAdded;
        toBeRemoved = a[start];
        start++,end++;
        if(end<n)
            toBeAdded = a[end];
        else break;
        if((*(smaller.rbegin()))>=toBeAdded){
            smaller.insert(toBeAdded);
            smallerSum+=toBeAdded;
        }
        else{
            larger.insert(toBeAdded);
            largerSum+=toBeAdded;
        }
        if(smaller.find(toBeRemoved)!=smaller.end()){
            auto it = smaller.find(toBeRemoved);
            smaller.erase(it);
            smallerSum-=toBeRemoved;
        }
        else{
            auto it = larger.find(toBeRemoved);
            larger.erase(it);
            largerSum-=toBeRemoved;
        }
        balanceBothSets(smaller,larger,smallerSize,largerSize,&smallerSum,&largerSum);
    }
    for(auto val : ans){
        cout<<val<<" ";
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