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

bool checkCondition(ll k,ll a,ll b,ll c){
    ll lhs = (b-k)*(b-k);
    ll rhs = 4LL*a*c;
    return lhs<rhs;
}

void findK(vecll& k,ll a,ll b,ll c){
    // ll lowerLimitPlus1 = (b - sqrt(4*a*c)) + 1; //by default floor lega and isme +1 krna hume
    // ll upperLimit = ceil(b*1.f + sqrt(4*a*c));
    // auto it = lower_bound(itr(k),lowerLimitPlus1);
    // if(it==k.end()){
    //     return -1;
    // }
    // if(*it<upperLimit) return *it;
    // return -1;
    //precision error ka problem hoga, usse acha h ki b ke dono aaju baju walo ka condition check kre
    
    // vecll::iterator it = lower_bound(itr(k),b);
    //so it is greater then b or equal to b
    //so it ko and it-1 ko check kr condition me
    // if(it==k.end()){
    //     --it;
    // }
    // if(checkCondition(*it,a,b,c)){
    //     return *it;
    // }
    // if(it!=k.begin()){
    //     --it;
    //     if(checkCondition(*it,a,b,c)){
    //         return *it;
    //     }
    // }
    // return -1;
    ll index = lower_bound(k.begin(),k.end(),b)-k.begin();
    ll n = k.size();
    if(index<n && (k[index] - b) * (k[index] - b) < 4 * a * c){
        cout<<"YES\n";
        cout<<k[index]<<"\n";
        return;
    }
    if(index>0 && (k[index-1] - b) * (k[index-1] - b) < 4 * a * c){
        cout<<"YES\n";
        cout<<k[index-1]<<"\n";
        return;
    }
    cout<<"NO\n";
    //this is giving me wrong answer, since k=-1 can be a valid answer
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vecll k(n,0);
    forn(0,n) cin>>k[i];
    sort(itr(k));
    forn(0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        findK(k,a,b,c);
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