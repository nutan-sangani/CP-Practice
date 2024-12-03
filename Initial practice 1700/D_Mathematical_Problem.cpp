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
    if(n==1){
        cout<<1<<endl;
        return;
    }
    else if(n==3){
        cout<<169<<endl;
        cout<<196<<endl;
        cout<<961<<endl;
        return;
    }
    vector<string> ans;
    int zeroCount = 0;
    int totalZeros = n-3; //this will be fixed
    while(n>=3){
        string s1="";
        string s2="";
        s1+="1";
        int zeroCountCopy=zeroCount;
        while(zeroCountCopy){
            zeroCountCopy-=2;
            s1+="0";
            s2+="0";
        }
        s1+="6";
        s2+="9";
        s1+=s2;
        int rem = totalZeros - zeroCount;
        while(rem){
            rem-=1;
            s1+="0";
        }
        ans.pb(s1); //16900
        s1="";
        s2="";
        s1+="9";
        zeroCountCopy=zeroCount;
        while(zeroCountCopy){
            zeroCountCopy-=2;
            s1+="0";
            s2+="0";
        }
        s1+="6";
        s2+="1";
        s1+=s2;
        rem = totalZeros - zeroCount;
        while(rem){
            rem-=1;
            s1+="0";
        }
        ans.pb(s1);//96100
        zeroCount+=2;
        n-=2;
    }
    string s1="196";
    while(totalZeros){
        s1+="0";
        totalZeros-=1;
    }
    ans.pb(s1);
    n=ans.size();
    forn(0,n){
        cout<<ans[i]<<endl;
    }
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