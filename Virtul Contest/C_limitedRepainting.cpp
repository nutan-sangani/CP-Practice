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

ll getMinPenalty(vector<vector<vecll>>& dp,vecll& blueMax,vecll& redMax,ll prevColored,ll index,ll kRem,ll n,vecll& remMax){
    if(kRem<0) return LLONG_MAX;
    else if(index>=n) return 0;
    else if(kRem==0 && prevColored==0){
        return remMax[index];
    }
    else if(dp[index][kRem][prevColored]!=-1) return dp[index][kRem][prevColored];
    ll temp = getMinPenalty(dp,blueMax,redMax,1,index+1,kRem-1,n,remMax); //curr ko color kar
    ll temp2 = max<ll>(blueMax[index],getMinPenalty(dp,blueMax,redMax,0,index+1,kRem,n,remMax));
    if(prevColored==1){
        ll temp3 = max<ll>(getMinPenalty(dp,blueMax,redMax,1,index+1,kRem,n,remMax),redMax[index-1]);
        temp2 = min<ll>(temp2,temp3);
    }
    temp = min<ll>(temp,temp2);
    return dp[index][kRem][prevColored] = temp;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    string color;
    cin>>color;
    vecll cost(n,0);
    forn(0,n){
        cin>>cost[i];
    }
    ll opsNeeded = 0;
    vecll blueMax,redMax;
    int i=0;
    bool bHua=false;
    while(i<n){
        if(color[i]=='B'){
            ll maxi = cost[i];
            bHua=true;
            ll first=i;
            while(i<n && color[i]=='B'){
                maxi = max<ll>(maxi,cost[i]);
                i++;
            }
            opsNeeded+=1;
            blueMax.pb(maxi);
        }
        else if(bHua && color[i]=='R'){
            ll maxi = cost[i];
            ll first=i;
            while(i<n && color[i]=='R'){
                maxi = max<ll>(maxi,cost[i]);
                i++;
            }
            redMax.pb(maxi);
        }
        else i+=1;
    }
    if(opsNeeded<=k){
        cout<<0<<endl;
        return;
    }
    ll sizei = blueMax.size();
    vector<vector<vecll>> dp(sizei,vector<vecll> (k+1,vecll(2,-1)));
    vecll remMax;
    n=blueMax.size();
    ll temp = blueMax[n-1];
    for(int i=n-1;i>=0;i--){
        temp = max<ll>(temp,blueMax[i]);
        remMax.pb(temp);
    }
    reverse(itr(remMax));
    cout<<getMinPenalty(dp,blueMax,redMax,0,0,k,n,remMax)<<endl;
}
//kya fayda ye likh ke,since ye n^2 wala code h aur dp se O(n) krna possible bhi nhi lag rha

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