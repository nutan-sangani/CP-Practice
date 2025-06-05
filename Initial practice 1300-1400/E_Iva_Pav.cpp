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

int MSBSetIn(ll n){
    int end = -1;
    forn(0,64){
        if(n & 1LL<<i){
            end = i;
        }
    }
    return end;
}

bool isBitSetInRange(int l,int r,vecll& psOfBitCount){
    ll prev = l>0 ? psOfBitCount[l-1] : 0;
    ll length = r-l+1;
    if(psOfBitCount[r]-prev >= length) return true;
    return false;
}

bool isValid(vector<vecll>& psOfSetBitCount,ll mid,ll l,ll k,int msbSetInK){
    forn(msbSetInK+1,64){
        if(isBitSetInRange(l,mid,psOfSetBitCount[i])){
            return true;
        }
    }
    for(int i=msbSetInK;i>=0;i--){
        if(k & 1LL<<i){
            if(isBitSetInRange(l,mid,psOfSetBitCount[i])){
                continue;
            }
            else return false;
        }
        else{
            if(isBitSetInRange(l,mid,psOfSetBitCount[i])){
                return true;
            }
        }
    }
    return true;
}
//1110
//1111

//0111
void solve(){
    ll n;
    cin>>n;
    vecll a(n);
    forn(0,n) cin>>a[i];
    vector<vecll> psOfSetBitCount(64,vecll (n,0));
    forn(0,64){
        ll setCount = 0;
        for(int j=0;j<n;j++){
            setCount+=((a[j] & 1LL<<i)>0 ? 1 : 0);
            psOfSetBitCount[i][j]=setCount;
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll l,k;
        cin>>l>>k;
        l-=1;
        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }
        if(k==0){
            cout<<n<<" ";
            continue;
        }
        ll low=l,high=n-1;
        ll msbSetInK = MSBSetIn(k);
        // debug("this",isValid(psOfSetBitCount,1,0,k,msbSetInK));
        while(low<=high){
            ll mid = (low+high)/2;
            if(isValid(psOfSetBitCount,mid,l,k,msbSetInK)){
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<high+1<<" ";
    }
    cout<<endl;
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