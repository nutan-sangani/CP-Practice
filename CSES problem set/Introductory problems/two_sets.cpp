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
    ll n;
    cin>>n;
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        sum+=(i+1);
        a[i]=sum;
    }
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    ll target = sum/2;
    ll index = (lower_bound(itr(a),target) - a.begin());
    ll diff = a[index] - target;
    vecll set1,set2;
    if(diff!=0)
        set2.pb(diff);
    forn(1,n+1){
        if(i<=(index+1)){
            if(i!=diff)
                set1.pb(i);
        }
        else{
            set2.pb(i);
        }
    }
    cout<<set1.size()<<endl;
    forn(0,set1.size())
        cout<<set1[i]<<" ";
    cout<<endl;
    cout<<set2.size()<<endl;
    forn(0,set2.size())
        cout<<set2[i]<<" ";
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}