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
    string s;
    cin>>s;
    int size = s.size();
    if(size==1){
        cout<<"NO";
        return;
    }
    ll elem = size%2==0 ? 2 : 1;
    while(elem<size){
        ll start = (size)/2;
        start-=(elem/2);
        int length=(size - elem)/2 + elem;
        string s1,s2;
        s1=s.substr(0,length);
        s2=s.substr(start,length);
        if(s1.compare(s2)==0){
            cout<<"YES"<<endl;
            cout<<s1<<endl;
            return;
        }
        elem+=2;
    }
    cout<<"NO"<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}