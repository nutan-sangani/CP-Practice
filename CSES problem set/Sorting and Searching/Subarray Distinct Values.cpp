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
    ll n,k;
    cin>>n>>k;
    vecll nums(n,0);
    forn(0,n) cin>>nums[i];
    int left=0,right=0;
    umll freqOfElements;
    ll uniqueElem = 0;
    ll goodArrayCount=0;
    uniqueElem=1;
    freqOfElements[nums[0]]=1;
    while(right<n){
        if(uniqueElem<=k){
            ll subArrSize = right - left + 1;
            goodArrayCount+=subArrSize;
        }
        if(uniqueElem>k){
            ll leftMostElem = nums[left];
            left+=1;
            if(freqOfElements[leftMostElem]==1){
                uniqueElem-=1;
            }
            freqOfElements[leftMostElem]-=1;
        }
        else{
            right+=1;
            ll nextElem = -1;
            if(right<n)
                nextElem = nums[right];
            else break;
            freqOfElements[nextElem]+=1;
            if(freqOfElements[nextElem]==1){
                uniqueElem+=1;
            }
        }
    }
    cout<<goodArrayCount<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}