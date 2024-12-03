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

void towerOfHanoi(vector<pll>& moves,int n,int from,int withHelpOf,int to){
    if(n==1){
        moves.pb(mp(to,from));
        return;
    }
    towerOfHanoi(moves,n-1,from,to,withHelpOf);
    towerOfHanoi(moves,1,from,withHelpOf,to);
    towerOfHanoi(moves,n-1,withHelpOf,from,to);
}

void display(pll p){
    cout<<p.second<<" "<<p.first<<endl;
}

void solve(){
    vector<pll> moves;
    ll n;
    cin>>n;
    towerOfHanoi(moves,n,1,2,3);
    cout<<moves.size()<<endl;
    forn(0,moves.size()){
        display(moves[i]);
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