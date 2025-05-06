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
    bool operator()(pair<ll,pll>&a, pair<ll,pll>&b){ //for max heap and ascending sort in vector
        return a.first>b.first;
    }
};

//ghumake krne wala approach, the basic idea is ki k-- krne pe, koi ek edge ka color
//uske kisi node ke dusre edge ka color ban jayega, so wo node ka amt decr hoga
//like ek ek krke wo sare edges same component me aate jayenge
// void solve(){
//     ll n;
//     cin>>n;
//     vecll cost(n+1);
//     forn(0,n) cin>>cost[i+1];
//     um<ll,vecll> tree;
//     ll total = 0;
//     vecll count(n);
//     priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,MyComp> pq;
//     forn(0,n-1){
//         ll u,v;
//         cin>>u>>v;
//         tree[u].pb(v);
//         tree[v].pb(u);
//         if(cost[u]>cost[v]){
//             int temp = u;
//             u=v;
//             v=temp;
//         }
//         pq.push(mp(cost[u],mp(u,v)));
//     }
//     umll nodeInDifferentColorCount;
//     forn(0,n){
//         ll degree = tree[i+1].size();
//         total += (cost[i+1]*degree);
//         nodeInDifferentColorCount[i+1]=degree;
//     }
//     count[n-1]=total;
//     for(int i=n-2;i>=1;i--){
//         while(1){
//             pair<ll,pll> top = pq.top();
//             pq.pop();
//             if(nodeInDifferentColorCount[top.second.first]<=1){
//                 if(nodeInDifferentColorCount[top.second.second]<=1){
//                     continue;
//                 }
//                 top.first = cost[top.second.second];
//                 ll u=top.second.first;
//                 ll v = top.second.second;
//                 top.second.first=v;
//                 top.second.second=u;
//                 pq.push(top);
//             }
//             else{
//                 nodeInDifferentColorCount[top.second.first]-=1;
//                 total-=top.first;
//                 top.first = cost[top.second.second];
//                 int temp = top.second.first;
//                 top.second.first = top.second.second;
//                 top.second.second = temp;
//                 pq.push(top);
//                 break;
//             }
//         }
//         count[i] = total;
//     }
//     forn(0,n-1){
//         cout<<count[i+1]<<" ";
//     }
//     cout<<endl;
// }

void solve(){
    ll n;
    cin>>n;
    vecll cost(n+1);
    forn(0,n) cin>>cost[i+1];
    um<ll,vecll> tree;
    ll total = 0;
    vecll count(n);
    priority_queue<ll,vecll,greater<ll>> pq;
    forn(0,n-1){
        ll u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    forn(1,n+1){
        ll degree = tree[i].size();
        total += (degree*cost[i]);
        while(degree>1){
            pq.push(cost[i]);
            degree--;
        }
    }
    vecll ans;
    forn(0,n-1){
        ans.pb(total);
        if(!pq.empty()){
            total-=pq.top();
            pq.pop();
        }
    }
    reverse(itr(ans));
    printArray(ans);
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
//5th may se dhundh lena band h