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

ll findKnightPositionCount(ll remRow,ll col){
    ll total = col*col*remRow + sumOfnNaturalNumbers(col-1LL);
    ll toBeRemoved = 0;
    if(remRow>=2){
        toBeRemoved += 2LL*(col-2LL)+2LL;
    }
    if(remRow>=1){
        toBeRemoved += 2LL*(col-2LL);
    }
    return total-toBeRemoved;
}

void solve(){
    ll n;
    cin>>n;
    forn(1,n+1){
        ll count=0;
        for(int j=1;j<=i;j++){
            count+=findKnightPositionCount(i-j,i);
        }
        cout<<count<<endl;
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