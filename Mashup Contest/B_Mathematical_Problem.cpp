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
    string s;
    cin>>s;
    if(n==2){
        cout<<stoi(s)<<endl;
        return;
    }
    vecll pSum(n,0),a(n,0);
    bool hasZero=false;
    ll sum=0;
    forn(0,n){
        int val = int(s[i]-'0');
        if(val==0) hasZero=true;
        a[i]=val;
        if(val!=1)
            sum+=val;
        pSum[i]=sum;
    }
    if((hasZero && n>3) || (n==3 && (s[0]=='0' || s[2]=='0'))){
        cout<<0<<endl;
        return;
    }
    ll mini=INT_MAX;
    int i=0;
    while(i<n-1){
        int windowEnd = i+1;
        int windowSum = a[i]*10+a[windowEnd];
        ll ps = i>0 ? pSum[i-1] : 0;
        ll ss = 0;
        if(windowEnd<n-1)
            ss = pSum[n-1] - pSum[windowEnd];
        if(windowSum==1 && (ps!=0 || ss!=0)) windowSum=0;
        mini=min<ll>(mini,ss+ps+windowSum);
        i++;
    }
    cout<<mini<<endl;
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