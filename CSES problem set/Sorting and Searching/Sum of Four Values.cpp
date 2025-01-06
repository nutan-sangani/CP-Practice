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

pll twoSum(int start,int end,vector<pll>& nums,ll target){
    while(start<end){
        ll sum = nums[start].first+nums[end].first;
        if(sum==target){
            pll ans(nums[start].second,nums[end].second);
            return ans;
        }
        else if(sum<target) start++;
        else end--;
    }
    pll nulli(-1,-1);
    return nulli;
}


class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

void threeSum(vector<pll>& nums,int start,int end,ll target,vecll& ans){
    forn(start,end+1){
        pll twoSumOutput = twoSum(i+1,end,nums,target-nums[i].first);
        if(twoSumOutput.first!=-1){
            ans.pb(nums[i].second+1);
            ans.pb(twoSumOutput.first+1);
            ans.pb(twoSumOutput.second+1);
            return;
        }
    }
    return;
}

void solve(){
    ll n,target;
    cin>>n>>target;
    vector<pll> nums(n);
    forn(0,n){
        ll a;
        cin>>a;
        nums[i]=mp(a,i);
    }
    sort(itr(nums),MyComp());
    forn(0,n){
        vecll ans;
        threeSum(nums,i+1,n-1,target-nums[i].first,ans);
        if(ans.size()!=3) continue;
        else{
            ans.pb(nums[i].second+1);
            for(auto num : ans){
                cout<<num<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}