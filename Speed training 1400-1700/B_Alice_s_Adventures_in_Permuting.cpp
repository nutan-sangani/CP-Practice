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

ll Ceil(ll a,ll b){
    if(b==0) return 0;
    if(a>=0)
        return a%b==0 ? a/b : ((a/b)+1);
    else return a/b;
}

void solve(){
    ll n,b,c;
    cin>>n>>b>>c;
    if(b==0 && c<=n-3){
        cout<<-1<<endl;
        return;
    }
    ll count=0;
    ll limitOfI=0;
    if(b==0){
        if(c>(n-1)){
            cout<<n<<endl;
        }
        else cout<<n-1<<endl;
        return;
    }
    else
        limitOfI = (((n-1)-c)%b)==0 ? (((n-1-c)/b)+1) : Ceil((n-1)-c,b);
    limitOfI=max<ll>(0,limitOfI);
    count+=(((n)-limitOfI));
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