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
//ab+bc+ac<=n
//

void solve(){
    ll n,x;
    cin>>n>>x;
    ll count=0;
    forn(1,x-1){ //a can be from 1 to x-2
        ll limit = n/i;
        for(int j=1;j<limit;j++){ //b can be from 1 to n/a se chota always
            ll eq1 = x - i - j;
            ll eq2 = (n - (i*j))/(i+j);
            ll mini = min<ll>(eq1,eq2);
            if(mini>0) count+=mini;
        }
    }
    cout<<count<<endl;
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