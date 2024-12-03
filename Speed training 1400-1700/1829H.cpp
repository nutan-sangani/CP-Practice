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

void generateAllCombinations(vector<vecll>& combinations,vecll& currCombination,ll rem,ll i){
    if(i>5){
        if(rem==0){
            combinations.pb(currCombination);
        }
        return;
    }
    generateAllCombinations(combinations,currCombination,rem,i+1);
    if(rem>0){
        currCombination.pb(i);
        generateAllCombinations(combinations,currCombination,rem-1,i+1);
        currCombination.pop_back();
    }
    return;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    vector<vecll> combinations;
    vecll temp;
    generateAllCombinations(combinations,temp,k,0);
    
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