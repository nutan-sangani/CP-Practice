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

ll findSumOfDigits(string s){
    ll sum=0;
    for(auto digit : s){
        sum+=(ll)(digit-'0');
    }
    return sum;
}

void solve(){
    ll n;
    cin>>n;
    vector<string> odd,even;
    forn(0,n){
        string s;
        cin>>s;
        if(s.size()%2==0) even.pb(s);
        else odd.pb(s);
    }
    vector<vecll> countPresent(6,vecll (50,0));
    vector<vecll> countPresentEven(6,vecll (50,0));
    ll count=0;
    forn(0,odd.size()){
        string s = odd[i];
        ll sum = findSumOfDigits(s);
        ll size = s.size();
        ++countPresent[size][sum];
        if(size==3){
            ll sum1=0,sum2=0;
            ll sum3=0,sum4=0;
            sum3 = findSumOfDigits(s.substr(0,1));
            sum4 = findSumOfDigits(s.substr(size-1,1));
            sum1 = sum - 2*sum3;
            sum2 = sum - 2*sum4;
            if(sum1>=0)
                ++countPresent[1][sum1];
            if(sum2>=0)
                ++countPresent[1][sum2];
            continue;
        }
        else if(size==5){
            ll sum1=0,sum2=0,sum3=0,sum4=0;
            ll o1,o2,o3,o4;
            o1=findSumOfDigits(s.substr(0,1));
            o2=findSumOfDigits(s.substr(size-1,1));
            o3=findSumOfDigits(s.substr(0,2));
            o4=findSumOfDigits(s.substr(size-2,2));
            sum1 = sum - 2*o1;
            sum2 = sum - 2*o2;
            sum3 = sum - 2*o3;
            sum4 = sum - 2*o4;
            if(sum1>=0) ++countPresent[3][sum1];
            if(sum2>=0) ++countPresent[3][sum2];
            if(sum3>=0) ++countPresent[1][sum3];
            if(sum4>=0) ++countPresent[1][sum4];
        }
    }
    forn(0,odd.size()){
        ll sum = findSumOfDigits(odd[i]);
        count+=countPresent[odd[i].size()][sum];
    }
    forn(0,even.size()){
        string s = even[i];
        ll sum = findSumOfDigits(s);
        ll size = s.size();
        ++countPresentEven[size][sum];
        if(size==4){
            ll sum1=0,sum2=0;
            ll sum3=0,sum4=0;
            sum3=findSumOfDigits(s.substr(0,1));
            sum4=findSumOfDigits(s.substr(size-1,1));
            sum1 = sum - 2*sum3;
            sum2 = sum - 2*sum4;
            if(sum1>=0) ++countPresentEven[2][sum1];
            if(sum2>=0) ++countPresentEven[2][sum2];
        }
    }
    forn(0,even.size()){
        ll sum = findSumOfDigits(even[i]);
        count+=countPresentEven[even[i].size()][sum];
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}