#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    a = __gcd(a,b);
    vecll arr(n,0);
    forn(0,n){
        cin>>arr[i];
        arr[i]%=a;
    }
    sort(itr(arr));
    ll ans = arr[n-1] - arr[0];
    forn(1,n){
        ans = min<ll>(ans,(arr[i-1]+a-arr[i]));
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