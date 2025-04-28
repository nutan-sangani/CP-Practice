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

ll findNumberAt(ll a,ll b,ll n){
    if(n==1) return 1;
    ll rowHalf = n/2;
    ll colHalf = n/2;
    ll numbersInOneQuad = (n/2LL)*(n/2LL);
    if(a<=rowHalf){ //1st or 4th me
        if(b<=colHalf){ //1st me
            return findNumberAt(a,b,n/2);
        }
        else{
            return 3LL*numbersInOneQuad + findNumberAt(a,b-colHalf,n/2);
        }
    }
    else{   //3rd or 2nd me
        if(b<=colHalf){
            return numbersInOneQuad*2LL+findNumberAt(a-rowHalf,b,n/2);
        }
        else{
            return numbersInOneQuad+findNumberAt(a-rowHalf,b-colHalf,n/2);
        }
    }
}

pll findIndexOf(ll a,ll n){
    if(n==1) return pll(1,1);
    ll rowHalf = n/2;
    ll colHalf = n/2;
    ll numbersInOneQuad = (n/2LL)*(n/2LL);
    pll nn;
    if(a<=numbersInOneQuad){
        nn = findIndexOf(a,n/2);
    }
    else if(a<=2*numbersInOneQuad){
        nn = findIndexOf(a-numbersInOneQuad,n/2);
        nn.first+=rowHalf;
        nn.second+=colHalf;
    }
    else if(a<=3*numbersInOneQuad){
        nn = findIndexOf(a-2LL*numbersInOneQuad,n/2);
        nn.first+=rowHalf;
    }
    else{
        nn = findIndexOf(a-3LL*numbersInOneQuad,n/2);
        nn.second+=colHalf;
    }
    return nn;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vecll power(31,1);
    forn(1,31){
        power[i] = power[i-1]*2LL;
    }
    n = power[n];
    forn(0,q){
        string s;
        cin>>s;
        if(s=="->"){
            ll a,b;
            cin>>a>>b;
            cout<<findNumberAt(a,b,n)<<endl;
        }
        else{
            ll a;
            cin>>a;
            pll nn = findIndexOf(a,n);
            cout<<nn.first<<" "<<nn.second<<endl;
        }
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