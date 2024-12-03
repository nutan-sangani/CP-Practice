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
    int n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    vecll gcd(n-1,0);
    forn(0,n-1){
        ll val = __gcd(a[i],a[i+1]);
        gcd[i]=val;
    }
    vector<bool> fromLeftND(n-1,true),fromRightND(n-1,true);
    forn(1,n-1){
        if(fromLeftND[i-1]==true && (gcd[i]>=gcd[i-1])){
            fromLeftND[i]=true;
        }
        else{
            fromLeftND[i]=false;
        }
    }
    for(int i=n-3;i>=0;--i){
        if(fromRightND[i+1]==true && (gcd[i]<=gcd[i+1])){
            fromRightND[i]=true;
        }
        else fromRightND[i]=false;
    }
    forn(0,n){ //kisko gayab karu from a
        ll val = -1;
        if(i>0 && i<n-1){
            val = __gcd(a[i-1],a[i+1]);
        }
        ll prev = i>1 ? i-2 : -1; //handle case of i==-1
        ll next = i<n-2 ? i+1 : -1;
        if((prev==-1 || (fromLeftND[prev]==true && (gcd[prev]<=val || val==-1))) && (next==-1 || (fromRightND[next]==true && (gcd[next]>=val || val==-1)))){
            cout<<"YES"<<endl;
            return;
        }
        else continue;
    }
    cout<<"NO"<<endl;
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