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

ll makeComparable(ll* prevPower,ll previ,ll a){
    while((*prevPower>0) && previ<=a){
        previ*=2;
        (*prevPower)-=1;
    }
    return previ;
}

void solve(){
    int n;
    cin>>n;
    ll count=0;
    ll previ=-1;
    ll prevPower=0;
    forn(0,n){
        ll a;
        cin>>a;
        if(previ==-1){
            previ=a;
            prevPower=0;
        }
        else{
            if(previ<=a){
                previ = makeComparable(&prevPower,previ,a);
                if(previ<=a){
                    previ=a;
                    prevPower=0;
                    continue;
                }
                ll additional = ceil(log2(Ceil(previ,a)));
                prevPower += additional;
                previ=a;
                count+=prevPower;
            }
            else{
                ll additional = ceil(log2(Ceil(previ,a)));
                prevPower += additional;
                previ=a;
                count+=prevPower;
            }
        }
    }
    cout<<count<<endl;
}
//count=0+3

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