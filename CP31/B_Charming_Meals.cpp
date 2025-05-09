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

void debug(){
    cout<<endl;
}

template<typename T,typename... Args>
void debug(T firstArg,Args... args){
    cout<<firstArg<<" ";
    debug(args...);
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

template<typename T>
void printMatrix(vector<vector<T>>& a){
    int rows = a.size();
    forn(0,rows){
        printArray(a[i]);
    }
}

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

bool isValid(multiset<ll> a,multiset<ll> b,ll mid){
    for(ll val : a){
        ll greater = val + mid; //isse bada ya equal
        ll lesser = val - mid;  //isse chota ya equal
        if(b.lower_bound(greater)!=b.end()){
            auto it = b.lower_bound(greater);
            b.erase(it);
            continue;
        }
        if(lesser<0) return false;
        auto it = b.lower_bound(lesser);
        if(it!=b.end() && *it==lesser){
            b.erase(it);
            continue;
        }
        else if(it!=b.begin()){
            it--;
            b.erase(it);
            continue;
        }
        else return false;
    }
    return true;
}

ll findLargestKPossible(vecll& a,vecll& b,int t){
    int rem = a.size()-t;
    ll diff = LLONG_MAX;
    forn(0,t){
        ll indexInB = rem+i;
        diff = min(diff,abs(a[i]-b[indexInB]));
    }
    forn(0,rem)
    {
        ll indexInA = t+i;
        diff = min(diff,abs(a[indexInA]-b[i]));
    }
    return diff;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n),b(n);
    forn(0,n) cin>>a[i];
    forn(0,n) cin>>b[i];
    sort(itr(a));
    sort(itr(b));
    ll maxK = -1;
    forn(1,n+1){
        int t = i;
        ll k = findLargestKPossible(a,b,t);
        maxK= max(maxK,k);
    }
    cout<<maxK<<endl;
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