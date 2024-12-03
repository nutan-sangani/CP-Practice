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
#define mod 100000007

using namespace std;

enum class Type{
    prog,
    test
};

void helper(vecll& a,vecll& b,int n,int m,int total)
{
    int pFav = 0;
    int tFav = 0;
    Type limiting;
    forn(0,total)
    {
        if(a[i]>b[i]) pFav++;
        else tFav++;
    }
    if(pFav>n){
        limiting=Type::prog;
    }
    else limiting = Type::test;
    int limitIndex=-1;
    int nextIndex=-1;
    ll sumBefore = 0;
    ll sumAfter = 0;
    int countP=0;
    int countT=0;
    forn(0,total)
    {
        if(a[i]>b[i]){
            ++countP;
            if(countP==n && limiting==Type::prog){
                limitIndex=i;
            }
            if(countP>n){
                sumAfter+=b[i];
            }
            else sumBefore+=a[i];
            if(countP==n+1){
                nextIndex=i;
            }
            continue;
        }
        else{
            ++countT;
            if(countT==m && limiting==Type::test){
                limitIndex=i;
            }
            if(countT>m){
                sumAfter+=a[i];
            }
            else sumBefore+=b[i];
            if(countT==m+1){
                nextIndex=i;
            }
            continue;
        }
    }
    ll sum = sumAfter+sumBefore;
    // cout<<nextIndex<<endl;
    // cout<<limitIndex<<endl;
    //5 | 11
    //nextIndex = 1
    //limitIndex = 0;
    forn(0,total)
    {
        if(i>limitIndex){
            if(limiting==Type::prog){
                ll temp = sum - b[i];
                cout<<temp<<" ";
                continue;
            }
            else{
                ll temp = sum - a[i];
                cout<<temp<<" ";
                continue;
            }
        }
        else{ //16-5-3+5=11+2=13
            if(a[i]>b[i])
            {
                ll temp = sum - a[i];
                if(limiting==Type::prog){
                    temp -= b[nextIndex];
                    temp += a[nextIndex];
                }
                cout<<temp<<" ";
                continue;
            }
            else{
                ll temp = sum - b[i];
                if(limiting==Type::test){
                    temp -= a[nextIndex];
                    temp += b[nextIndex];
                }
                cout<<temp<<" ";
                continue;
            }
        }
    }
    cout<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vecll a(n+m+1);
        vecll b(n+m+1);
        forn(0,n+m+1)
            cin>>a[i];
        forn(0,n+m+1)
            cin>>b[i];
        helper(a,b,n,m,n+m+1);
        
    }
    return 0;
}