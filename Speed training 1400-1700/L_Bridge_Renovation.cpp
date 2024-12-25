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
    return a%b==0 ? a/b : ((a/b)+1);
}

ll decrement(ll n,ll by){
    return max<ll>(0,n-by);
}

void solve(){
    ll n;
    cin>>n;
    ll a,b,c;
    a=b=c=n;
    //25=a,21=b,18=c
    ll count = Ceil(a,2);
    a = a%2==0 ? 0 : 1;
    if(b>0){
        b=decrement(b,a);
    }
    else c=decrement(c,a);
    while(b>0 && c>0){
        if(b==1){
            b=decrement(b,1);
            c=decrement(c,2);
            count+=1;
        }
        else{
            b=decrement(b,2);
            c=decrement(c,1);
            count+=1;
        }
    }
    if(b>0){
        count+=Ceil(b,2);
    }
    if(c>0){
        count+=Ceil(c,3);
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    solve();
    return 0;
}