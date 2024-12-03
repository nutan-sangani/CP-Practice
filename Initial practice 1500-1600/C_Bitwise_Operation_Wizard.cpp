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

char query(int a,int b,int c,int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout.flush();
    char k;
    cin>>k;
    return k;
}

void solve(){
    int n;
    cin>>n;
    //0, 1, 2
    //00, 01, 10
    //first pass me max nikal from 0 to n-1th index.
    int maxIndex=0;
    forn(0,n){
        char a = query(maxIndex,maxIndex,i,i);
        if(a=='<'){
            maxIndex=i;
        }
    }
    //then sare max banane wale nikal
    vecll maxFormingIndexes;
    int pair=0;
    forn(0,n){
        char a = query(maxIndex,pair,maxIndex,i);
        if(a=='='){
            maxFormingIndexes.pb(i);
        }
        else if(a=='<'){
            maxFormingIndexes.clear();
            maxFormingIndexes.pb(i);
            pair=i;
        }
    }
    //than un max banane walo se min nikal.
    int size = maxFormingIndexes.size();
    int minIndex=maxFormingIndexes[0];
    forn(0,size){
        char a = query(minIndex,minIndex,maxFormingIndexes[i],maxFormingIndexes[i]);
        if(a=='>'){
            minIndex=maxFormingIndexes[i];
        }
    }
    cout<<"! "<<minIndex<<" "<<maxIndex<<endl;
    return;
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