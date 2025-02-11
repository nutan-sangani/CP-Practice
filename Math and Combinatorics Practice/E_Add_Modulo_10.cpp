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

ll findNumberAfterGetting2AsLastDigit(ll n){
    n += (n%10);
    if(n%10==0) return -1;
    while(n%10!=2 || n<10){
        n += (n%10);
    }
    return n;
}

ll getSecondLastDigit(ll n){
    n/=10;
    return n%10;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    bool allZero=true;
    forn(0,n){
        ll num;
        cin>>num;
        num+=(num%10);
        allZero &= (num%10==0) ? true : false;
        a[i]=num;
    }
    if(allZero){
        ll val = a[0];
        forn(0,n){
            if(val!=a[i]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }
    ll firstOdd=-1,firstEven=-1;
    forn(0,n){
        ll num = findNumberAfterGetting2AsLastDigit(a[i]);
        if(num==-1){
            cout<<"NO\n";
            return;
        }
        ll secondLastDigit = getSecondLastDigit(num);
        if(secondLastDigit%2==0) firstEven = i;
        else firstOdd=i;
    }
    if((firstEven==-1 && firstOdd!=-1) || (firstEven!=-1 && firstOdd==-1)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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