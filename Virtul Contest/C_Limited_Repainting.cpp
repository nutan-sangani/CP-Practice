#include <iostream>
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
//#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
//using namespace __gnu_pbds;

bool isValid(ll mid,vector<pair<char,ll>>& a,ll k){
    int n = a.size();
    ll needed = 0;
    char last='R';
    forn(0,n){
        if(a[i].second>mid){
            if(a[i].first=='B' && last=='R') needed+=1;
            last=a[i].first;
        }
    }
    if(needed>k) return false;
    return true;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vecll cost(n,0);
    forn(0,n) cin>>cost[i];
    ll low=0,high=LLONG_MIN;
    forn(0,n){
        high = max<ll>(high,cost[i]);
    }
    high+=2;
    ll i=0;
    vector<pair<char,ll>> a;
    while(i<n){
        if(s[i]=='B'){
            ll maxi = cost[i];
            // while(i<n && s[i]=='B'){
            //     maxi = max<ll>(maxi,cost[i]);
            //     i++;
            // }
            a.pb(mp('B',maxi));
            i++;
        }
        else{
            ll maxi = cost[i];
            a.pb(mp('R',cost[i]));
            i++;
        }
    }
    ll ans = -1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(isValid(mid,a,k)){
            ans=mid;
            high = mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<endl;
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