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

void helper(int n,string& a,string& b)
{
    vecll moves;
    int i,j,k;
    i=0;
    j=n-1;
    k=n-1;
    while(i<=j){
        if(a[i]==b[k]){
            moves.pb(0);
        }
        moves.pb(k);
        k--;
        i++;
        if(i<=j){
            if(a[j]!=b[k]){
                moves.pb(0);
            }
            moves.pb(k);
            k--;
            j--;
        }
    }
    cout<<moves.size()<<" ";
    forn(0,moves.size()){
        cout<<moves[i]+1<<" ";
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
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        helper(n,a,b);
    }
    return 0;
}