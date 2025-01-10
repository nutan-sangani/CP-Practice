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

// vecll precalculatedPowerOf2(1000005,-1); incorrect

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

// ll PreCalculateForOneColumn(ll n){
//     if(n==1) return 1;
//     else if(precalculatedPowerOf2[n]!=-1) return precalculatedPowerOf2[n];
//     // if(n<=1) return 1;
//     // else if(dp[n]!=-1) return dp[n];
//     // ll ways=0;
//     // //yaha pe 2 options, ya toh isko prev me count kr, ya isko alg se count se.

//     // //isko prev me count krta
//     // ways+=PreCalculateForOneColumn(n-1);
//     // ways%=mod;

//     // //isko alag se calc krta
//     // ways+=PreCalculateForOneColumn(n-1);
//     // ways%=mod;
//     // return dp[n]=ways;
//     // // this is always a power of 2, ie 2^(n-1), since its similar to having n-1 partition lines
//     // // and deciding no of combinations possible of this lines.
//     // // thus iske badle 2 se multiply krte jaa.
//     ll ways = PreCalculateForOneColumn(n-1)*2LL;
//     ways%=mod;
//     return precalculatedPowerOf2[n]=ways;
// }
//incorrect

// ll findCountFor2Cols(ll widthLimit,ll n,vector<vecll>& dp){
//     if(n<=0) return 1;
//     //isme bhi abhi 2 cases, ki purane ke width 2 ke sath jayega, ya fhir apna
//     //width=2 chalu krega, ya fhir width=1 krega 1,2,3,4....rem length ka.
// }
//wrong h, jab dp then sabse chote subproblem ko kese solve krenge wo dekh pehle
//then naye/larger subproblem uske sath kese related h wo dekh

vector<vecll> dp(1000002,vecll (3,0));

// ll findCount(ll n,ll width){
//     if(n==1) return 1;
//     else if(dp[n][width]!=-1) return dp[n][width];
//     ll ways=0;
//     if(width==1){
//         ways+=(findCount(n-1,1)*4LL);
//         ways%=mod;
//         ways+=findCount(n-1,2);
//         ways%=mod;
//         return dp[n][width]=ways;
//     }
//     else{
//         ways+=findCount(n-1,1);
//         ways%=mod;
//         ways+=(findCount(n-1,2)*2LL);
//         ways%=mod;
//         return dp[n][width]=ways;
//     }
// }

void preCalculate(){
    dp[1][1]=dp[1][2]=1;
    dp[0][1]=dp[0][2]=1;
    forn(2,1000001){
        for(int j=1;j<=2;j++){
            if(j==1){
                ll ways=0;
                ways+=(dp[i-1][1]*4LL);
                ways%=mod;
                ways+=dp[i-1][2];
                ways%=mod;
                dp[i][j]=ways;
            }
            else{
                ll ways=dp[i-1][1];
                ways%=mod;
                ways+=(dp[i-1][2]*2LL);
                ways%=mod;
                dp[i][j]=ways;
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    // ll ways = findCountFor2Cols(1,n,dp);
    // ways%=mod;
    // ways+= findCountFor2Cols(2,n,dp);
    //incorrect

    // cout<<(findCount(n,1)+findCount(n,2))%mod<<endl;
    //correct
    cout<<(dp[n][1]+dp[n][2])%mod<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    // PreCalculateForOneColumn(1000002);
    //incorrect

    // findCount(1000000,1);
    // findCount(1000000,2);
    //correct
    preCalculate();
    while(t--)
    {
        solve();
    }
    return 0;
}
//isko bahot complicated samaj rha tha (since recursive structure itna clear nhi tha and dono towers ko
//alg-alg dekh rha tha isiliye).