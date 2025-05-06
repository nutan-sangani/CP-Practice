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


void countSegmentWithOnes(omll& countMap,vecll& a,int n){
    int i=0;
    while(i<n){
        if(a[i]==0){
            i+=1;
            continue;
        }
        ll temp = 0;
        while(i<n && a[i]==1){
            temp+=1;
            i+=1;
        }
        countMap[temp]+=1;
    }
}

void addSmallerSegmentsCreatedFromLargerOnes(omll& countMap){
    for(auto entry : countMap){
        forn(1,entry.first){
            ll count = entry.first - i + 1;
            countMap[i]+=(count*entry.second);
        }
    }
}

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vecll a(n);
    vecll b(m);
    forn(0,n){
        cin>>a[i];
    }
    forn(0,m){
        cin>>b[i];
    }
    omll continousSegmentWith1CountInA;
    omll continousSegmentWith1CountInB;
    countSegmentWithOnes(continousSegmentWith1CountInA,a,n);
    countSegmentWithOnes(continousSegmentWith1CountInB,b,m);
    addSmallerSegmentsCreatedFromLargerOnes(continousSegmentWith1CountInA);
    addSmallerSegmentsCreatedFromLargerOnes(continousSegmentWith1CountInB);
    ll count=0;
    for(auto entry : continousSegmentWith1CountInA){
        ll val = entry.first;
        if(k%val!=0) continue;
        ll complimentaryVal = k/val;
        count += (entry.second*continousSegmentWith1CountInB[complimentaryVal]);
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}
//wiki
//debug function