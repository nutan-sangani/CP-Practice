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

const ll N=1001;
vecll opsFrom1(N,N);

ll doKnapSack(vector<vecll>& dp,ll rem,ll index,vecll& opsNeeded,vecll& reward,int n){
    if(index>=n) return 0;
    if(rem<0) return 0;
    if(dp[index][rem]!=-1) return dp[index][rem];
    ll maxi = LLONG_MIN;
    if(opsNeeded[index]<=rem){
        maxi = doKnapSack(dp,rem-opsNeeded[index],index+1,opsNeeded,reward,n) + reward[index];
    }
    maxi = max<ll>(maxi,doKnapSack(dp,rem,index+1,opsNeeded,reward,n));
    return dp[index][rem] = maxi;
}

void solve(bool flag){
    ll n,k;
    cin>>n>>k;
    vecll b(n),c(n);
    forn(0,n) cin>>b[i];
    forn(0,n) cin>>c[i];
    vecll opsNeeded(n);
    ll totalOpsNeeded = 0;
    forn(0,n){
        opsNeeded[i] = opsFrom1[b[i]];
        totalOpsNeeded += opsNeeded[i];
    }
    if(k>=totalOpsNeeded){
        ll sum = 0;
        forn(0,n) sum+=c[i];
        cout<<sum<<endl;
        return;
    }
    vector<vecll> dp(n+1,vecll (k+1,-1));
    cout<<doKnapSack(dp,k,0,opsNeeded,c,n)<<endl;
}

int main()
{
    FASTIO
    opsFrom1[1]=0;
    forn(1,N){
        for(int j=1;j<=i;j++){
            ll val = i/j;
            ll jumpTo = i+val;
            if(jumpTo<N){
                opsFrom1[jumpTo] = min<ll>(opsFrom1[jumpTo],opsFrom1[i]+1LL);
            }
        }
    }
    int t;
    cin>>t;
    int i=0;
    while(t--)
    {
        i++;
        if(i==18)
            solve(true);
        else solve(false);
    }
    return 0;
}