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

void helper()
{
    
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
        vecll a(n,0);
        forn(0,n) cin>>a[i];
        int m;
        cin>>m;
        forn(0,m){
            string s;
            cin>>s;
            um<ll,ll> map;
            int flag=0;
            if(s.size()<n || s.size()>n){
                cout<<"NO"<<endl;
                continue;
            }
            vecll alpha(26,LLONG_MAX);
            for(int j=0;j<n;j++){
                if(map[a[j]]==0 && alpha[s[j]-'a']==LLONG_MAX){
                    alpha[s[j]-'a']=a[j];
                    map[a[j]]=s[j];
                }
                else if(map[a[j]]!=s[j] || alpha[s[j]-'a']!=a[j]){
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<"YES"<<endl;
        }
    }
    return 0;
}