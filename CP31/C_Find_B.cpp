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
    ll n,q;
    cin>>n>>q;
    vecll a(n);
    forn(0,n) cin>>a[i];
    ll sum = 0;
    vecll oneCount(n,0);
    vecll prefixSum(n,0);
    ll ps=0;
    forn(0,n){
        if(a[i]==1) sum+=1;
        oneCount[i]=sum;
        ps+=a[i];
        prefixSum[i]=ps;
    }
    forn(0,q){
        ll l,r;
        cin>>l>>r;
        l-=1;
        r-=1;
        if(l==r){
            cout<<"NO"<<endl;
            continue;
        }
        ll size = r-l+1;
        ll half = size/2;
        ll prevCount = l>0 ? oneCount[l-1] : 0;
        ll prev = l>0 ? prefixSum[l-1] : 0;
        ps = prefixSum[r] - prev;
        ll countOfOnesInRange = oneCount[r] - prevCount;
        ll extraSum = ps - size;
        if(extraSum>=countOfOnesInRange){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        // if(countOfOnesInRange<=half){
        // }
    }
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