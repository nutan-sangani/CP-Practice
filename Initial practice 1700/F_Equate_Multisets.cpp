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
    vecll a(n,0),b(n,0);
    umll count;
    forn(0,n){
        cin>>a[i];
        while(a[i]%2==0) a[i]/=2; //atmost logn times ie 32 times chalega
        ++count[a[i]];
    }
    forn(0,n){
        cin>>b[i];
    }
    sort(itr(b));
    int i=0;
    while(i<n){
        if(count[b[i]]!=0){
            count[b[i]]--;
            i++;
            continue;
        }
        else if(b[i]==1){
            //isse jyada divide nhi hosakta;
            cout<<"NO"<<endl;
            return;
        }
        else{
            b[i]/=2;
        }
    }
    cout<<"YES"<<endl;
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