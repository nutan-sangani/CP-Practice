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

um<ll,vecll> divisors;

bool isPerfectSquare(ll n){
    ll sqRoot = sqrt(n);
    ll square = pow(sqRoot,2);
    if(square==n) return true; //checks for rounding errors
    return false;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    umll count;
    forn(0,n){
        cin>>a[i];
        count[a[i]]+=1;
    }
    ll ans=0;
    for(auto it : count){
        if(it.second>=3){
            ans+=((it.second)*(it.second-1)*(it.second-2));
        }
    }
    for(auto it : count){
        vecll divs = divisors[it.first];
        for(auto divisor : divs){
                if(isPerfectSquare(divisor) && divisor!=1){
                    ll root = sqrt(divisor);
                    ll prev=it.first/root,prevToPrev=prev/root;
                    if(count.count(prevToPrev)==1 && count.count(prev)==1){
                        ans+=((it.second*count[prev]*count[prevToPrev]));
                    }
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    FASTIO
    
    int t;
    cin>>t;
    ll limit = 1000009;
    for(int i=1;i<=limit;i++){ //the numbers
        ll multiple=1;
        while((i*multiple)<=limit){
            ll number = (i*multiple);
            divisors[number].pb(i);
            ++multiple;
        }
    }
    while(t--)
    {
        solve();
    }
    return 0;
}