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

// bool isValid(vecll& a,ll mid,ll h){
    // ll currPower = h,greenLeft = 2,blueLeft=1;
    // forn(0,mid){
    //     debug(currPower);
    //     if(currPower>a[i]){
    //         currPower += a[i]/2;
    //     }
    //     else{
    //         if(greenLeft>=1 && (currPower*2LL) > a[i]){
    //             greenLeft-=1;
    //             currPower*=2LL;
    //             currPower += a[i]/2;
    //         }
    //         else if(blueLeft>0 && (currPower*3LL) > a[i]){
    //             blueLeft-=1;
    //             currPower*=3LL;
    //             currPower += a[i]/2;
    //         }
    //         else if(greenLeft>1 && (currPower*4LL) > a[i]){
    //             greenLeft-=2;
    //             currPower*=4LL;
    //             currPower += a[i]/2;
    //         }
    //         else if(greenLeft>0 && blueLeft>0 && ((currPower*6LL) > a[i])){
    //             greenLeft-=1;
    //             blueLeft-=1;
    //             currPower *= 6LL;
    //             currPower += a[i]/2;
    //         }
    //         else if(greenLeft>1 && blueLeft>0 && ((currPower*12LL) > a[i])){
    //             greenLeft-=2;
    //             blueLeft-=1;
    //             currPower *= 12LL;
    //             currPower += a[i]/2;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    // }
    // return true;
// }

ll getMaxScore(vecll &a,int n,multiset<ll>& choices,ll currPower,int index){
    if(index>=n) return 0;
    if(a[index]<currPower){
        return getMaxScore(a,n,choices,currPower+a[index]/2,index+1)+1;
    }
    ll maxScore = 0;
    multiset<ll> tempChoices(choices);
    for(auto choice : tempChoices){
        auto it = choices.find(choice);
        choices.erase(it);
        maxScore = max<ll>(maxScore,getMaxScore(a,n,choices,currPower*choice,index));
        choices.insert(choice);
    }
    return maxScore;
}

void solve(){
    ll n,h;
    cin>>n>>h;
    vecll a(n);
    forn(0,n) cin>>a[i];
    sort(itr(a));
    multiset<ll> multiplierChoices = {2,2,3};
    cout<<getMaxScore(a,n,multiplierChoices,h,0)<<endl;
}
//2 -> 4 + 1 = 5, 10 + 3 = 13 -> 13*3 = 39

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

//there is need for optimality here, thus dp ki taraf dekh raha, since khali 3 mese ek choice krni h
//so dp bhi nhi, its simply a brute force solution.
// ll low = 0;
// ll high = n;
// while(low<=high){
//     ll mid = (low+high)/2;
//     if(isValid(a,mid,h)){
//         low = mid+1;
//     }
//     else{
//         high = mid-1;
//     }
// }
// cout<<high<<endl;
// debug(isValid(a,4,h));