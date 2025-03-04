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

pll dpMemo(um<ll,pll>& dp,ll k,ll start,ll end){
    ll length = end - start + 1;
    if(length<k){
        pll temp(0,0);
        return temp;
    }
    else if(dp.find(length)!=dp.end()){
        pll temp = dp[length];
        ll diff = start - 1;
        ll newSum = temp.first + diff*temp.second;
        pll ans(newSum,temp.second);
        return ans;
    }
    ll mid = (start+end)/2;
    ll sum=0;
    ll start1,end1,start2,end2;
    ll count=0;
    if(length%2==0){
        start1=start;
        end1=mid;
        start2=mid+1;
        end2=end;
    }
    else{
        sum=mid;
        count=1;
        start1=start;
        start2=mid+1;
        end1=mid-1;
        end2=end;
    }
    pll t1,t2;
    t1 = dpMemo(dp,k,start1,end1);
    t2 = dpMemo(dp,k,start2,end2);
    sum+=t1.first;
    sum+=t2.first;
    count+=t1.second;
    count+=t2.second;
    pll ans(sum,count);
    if(start==1){
        dp[length]=ans;
    }
    return ans;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    um<ll,pll> dp; //length : {sum,elementCount}
    dpMemo(dp,k,1,n);
    ans = dp[n].first;
    cout<<ans<<endl;
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