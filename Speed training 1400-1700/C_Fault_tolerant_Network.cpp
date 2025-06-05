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

int getPositionWithMinimumCost(vecll& a,int b){
    ll minCost = LLONG_MAX;
    ll pos = -1;
    forn(0,a.size()){
        ll cost = abs(a[i]-b);
        if(cost<minCost){
            minCost=cost;
            pos=i;
        }
    }
    return pos;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n);
    vecll b(n);
    forn(0,n) cin>>a[i];
    forn(0,n) cin>>b[i];
    vecll optionsForA0 = {0,n-1,getPositionWithMinimumCost(b,a[0])};
    vecll optionsForALast = {0,n-1,getPositionWithMinimumCost(b,a[n-1])};
    ll minCost = LLONG_MAX;
    for(auto forFirstOfA : optionsForA0){
        for(auto forLastOfA : optionsForALast){
            ll cost = abs(a[0] - b[forFirstOfA]) + abs(a[n-1]-b[forLastOfA]);
            if(forFirstOfA!=0 && forLastOfA!=0){
                ll bestOption = getPositionWithMinimumCost(a,b[0]);
                cost += abs(b[0]-a[bestOption]);
            }
            if(forFirstOfA!=(n-1) && forLastOfA!=(n-1)){
                ll bestOption = getPositionWithMinimumCost(a,b[n-1]);
                cost += abs(b[n-1]-a[bestOption]);
            }
            minCost = min<ll>(minCost,cost);
        }
    }
    cout<<minCost<<endl;
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

//isme ek bug h, ki A ne B ke 0 and n-1 mese kuch select kiya toh B mese wapis usko use
//mat kr, but solve nhi ho rha wo bug, since its not greedy, optimality ki taraf jaa rha soln,
//so simpler implementation pe jaa rha.
//agr distinct values hoti toh kafi easy pdta.


// vecll firstAndLastInA(2),firstAndLastInB(2);
// firstAndLastInA[0]=a[0];
// firstAndLastInA[1]=a[n-1];
// firstAndLastInB[0]=b[0];
// firstAndLastInB[1]=b[n-1];
// ll minCost = (abs(a[0] - b[0]) + abs(a[n-1]-b[n-1]));
// minCost = min<ll>(minCost,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
// sort(itr(a));
// sort(itr(b));
// ll temp = 0;
// multiset<ll> connectedTo;
// forn(0,2){
//     auto lb = lower_bound(itr(b),firstAndLastInA[i]);
//     ll mini = LLONG_MAX;
//     ll val = -1;
//     if(lb!=b.end()){
//         mini = abs(firstAndLastInA[i]-*lb);
//         val = *lb;
//     }
//     if(lb!=b.begin()){
//         lb--;
//         if(mini>abs(firstAndLastInA[i]-*lb)){
//             mini = min<ll>(mini,abs(firstAndLastInA[i]-*lb));
//             val = *lb;
//         }
//         else if(mini==abs(firstAndLastInA[i]-*lb)){
//             connectedTo.insert(*lb);
//         }
//     }
//     connectedTo.insert(val);
//     temp+=mini;
// }
// forn(0,2){
//     auto lb = lower_bound(itr(a),firstAndLastInB[i]);
//     ll mini = LLONG_MAX;
//     if(connectedTo.count(firstAndLastInB[i])>0){
//         auto it = connectedTo.find(firstAndLastInB[i]);
//         connectedTo.erase(it);
//         continue;
//     }
//     if(lb!=a.end()){
//         mini = abs(firstAndLastInB[i]-*lb);
//     }
//     if(lb!=a.begin()){
//         lb--;
//         mini = min<ll>(mini,abs(firstAndLastInB[i]-*lb));
//     }
//     temp+=mini;
// }
// minCost = min<ll>(minCost,temp);
// cout<<minCost<<endl;