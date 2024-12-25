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

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll sum = sumOfnNaturalNumbers(n);
    ll free = 0;
    ll borrowedForRemoval = 0;
    for(int j=n-1;j>=0;j--){
        if(s[j]=='0'){
            borrowedForRemoval = max<ll>(0,borrowedForRemoval-1);
            continue;
        }
        ll numberBeforeJ = j;
        ll needed = 1 + borrowedForRemoval;
        if(needed <= numberBeforeJ){
            free+=(j+1);
            borrowedForRemoval+=1;
            continue;
        }
        else {
            borrowedForRemoval = max<ll>(0,borrowedForRemoval-1);
        }
    }
    cout<<(sum-free)<<endl;
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