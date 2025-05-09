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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b) const { //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

void findOverLapping(multiset<pll,MyComp>& allRanges,multiset<ll>& rightBounds){
    if(rightBounds.size()<=1){
        cout<<"NO"<<endl;
        return;
    }
    pll lastStarting = *(allRanges.rbegin());
    ll leftBoundsOfLastStarting = lastStarting.first;
    auto it = rightBounds.lower_bound(leftBoundsOfLastStarting);
    if(it==rightBounds.end() || it!=rightBounds.begin()){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
}

void solve(){
    ll n;
    cin>>n;
    multiset<ll> rightBoundOfEach;
    multiset<pll,MyComp> allRanges;
    forn(0,n){
        string type;
        cin>>type;
        if(type=="+"){
            ll l,r;
            cin>>l>>r;
            allRanges.insert(mp(l,r));
            rightBoundOfEach.insert(r);
            findOverLapping(allRanges,rightBoundOfEach);
        }
        else{
            ll l,r;
            cin>>l>>r;
            auto it = allRanges.find(mp(l,r));
            auto it2 = rightBoundOfEach.find(r);
            allRanges.erase(it);
            rightBoundOfEach.erase(it2);
            findOverLapping(allRanges,rightBoundOfEach);
        }
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}