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

ll query(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<"\n";
    cout.flush();
    ll k;
    cin>>k;
    return k;
}

// ll op(vecll& a){
//     cout<<"! ";
//     for(auto it : a){
//         cout<<it<<" ";
//     }
//     cout<<"\n";
//     cout.flush();
// }

pll getNum(vecll& a,ll val){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i!=j){
                ll have = a[i]*a[j];
                if(have==val){
                    return pll(a[i],a[j]);
                }
            }
        }
    }
    return pll(-1,-1);
}

void helper(ll offset,vecll& ans,vecll& nums){
    ll a,b,c,d;
    umll count;
    ll val = query(offset+1,offset+2);
    ll val2 = query(offset+2,offset+3);
    pll nn = getNum(nums,val);
    a=nn.first;
    count[nn.first]+=1;
    b=nn.second;
    count[nn.second]+=1;
    nn = getNum(nums,val2);
    c=nn.first;
    count[nn.first]+=1;
    d=nn.second;
    count[nn.second]+=1;
    if(count[a]==2){
        ans[offset+1]=a;
        ans[offset+0]=b;
        if(d==a){
            ans[offset+2]=c;
        }
        else ans[offset+2]=d;
    }
    else{ //count[b]=2
        ans[offset+0]=a;
        ans[offset+1]=b;
        if(b==d){
            ans[offset+2]=c;
        }
        else ans[offset+2]=d;
    }
}

void solve(){
    vecll nums = {4,8,15,16,23,42};
    vecll ans(6,-1);
    helper(0,ans,nums);
    helper(3,ans,nums);
    cout<<"! ";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";
    cout.flush();
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}