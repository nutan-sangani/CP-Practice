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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

void solve(){
    ll n,k;
    cin>>n>>k;
    um<ll,vecll> insertedCount;
    tree<pll,null_type,MyComp,rb_tree_tag,tree_order_statistics_node_update> set;
    vecll a(n,0);
    vecll ans;
    forn(0,n){
        cin>>a[i];
    }
    forn(0,k){
        ll count = insertedCount[a[i]].size();
        insertedCount[a[i]].push_back(count);
        set.insert(mp(a[i],count));
    }
    ll start = 0;
    ll end = k-1;
    while(end<n){
        ll median;
        if(k%2==0){
            median = min<ll>((*(set.find_by_order(((k+1)/2)-1))).first,(*(set.find_by_order(((k+1)/2)))).first);
        }
        else{
            median = (*(set.find_by_order(((k+1)/2)-1))).first;
        }
        ans.push_back(median);
        ll toBeRemoved = a[start];
        ll toBeAdded;
        end++;
        start++;
        if(end<n){
            toBeAdded = a[end];
        }
        else break;
        ll secondOfRemoved = insertedCount[toBeRemoved][insertedCount[toBeRemoved].size()-1];
        insertedCount[toBeRemoved].pop_back();
        set.erase(mp(toBeRemoved,secondOfRemoved));

        ll count = insertedCount[toBeAdded].size();
        insertedCount[toBeAdded].push_back(count);
        set.insert(mp(toBeAdded,count));
    }
    for(auto val : ans){
        cout<<val<<" ";
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
//can use ordered_set, but usme duplicates ka issue.
//usko solve krne ke liye maintain a um<ll,vecll>. aur set me (a_i,countOfAi) dalte ja
//if nikalna, toh map se vec se last nikal and wo wale ko delete krde.
//implementation me nlogn hoga, as well as easy impl h

//other approach would be using a set, to store elem in sorted fashion
//ek bar mid nikal pura traverse krke, uske baad jitne bhi cases h, usme ek step aage
//ya ek step piche hi move hoga. Thus wo logn time me kar sakte (including insertion and deletion).
//if same side se insertion and deletion, then no problem
//if oppo side se, then jo side insert hoga wo side move kr
//if same nikala and same dala, toh no issues
//if median hi nikala toh?
//complexity increases, thus usse acha h, ki 1st easy wale method se hi krlu.