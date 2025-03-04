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

vecll powerOf9(16,1);
vecll powerOf10(16,1);

ll remove4(ll n){
    ll ans=0;
    ll i=0;
    while(n>0){
        ll digit = n%10;
        n/=10LL;
        if(digit==4) digit=3;
        ll power = powerOf10[i];
        power*=digit;
        ans+=power;
        i++;
    }
    return ans;
}

ll findNumberWithOut4(ll n){
    ll ans=0;
    ll i=0;
    while(n>0){
        ll digit = n%10;
        n/=10LL;
        ll power = powerOf9[i];
        ll multiple = digit>=4 ? digit-1 : digit;
        ans+=(multiple*power);
        i++;
    }
    return ans;
}

void solve(){
    ll k;
    cin>>k;
    ll low = 1;
    ll high = 1000000000000000LL;
    while(low<=high){
        ll mid = (low+high)/2;
        ll number = findNumberWithOut4(mid);
        if(number==k){
            mid = remove4(mid);
            cout<<mid<<endl;
            return;
        }
        else if(number<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    ll val1 = 9;
    ll val2 = 10;
    forn(1,16){
        powerOf9[i]=val1;
        val1*=9LL;
        powerOf10[i]=val2;
        val2*=10LL;
    }
    while(t--)
    {
        solve();
    }
    return 0;
}