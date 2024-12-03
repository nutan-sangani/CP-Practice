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
        ll sum=0;
        forn(0,n){
            cin>>a[i];
            sum+=a[i];
        }
        if(n<=2){
            cout<<-1<<endl;
            continue;
        }
        sort(itr(a));
        int mid = (n/2);
        ll maxi = a[mid]*2LL;
        ll avg = sum%n==0 ? sum/n : (sum/n)+1;
        if(avg>maxi){
            cout<<0<<endl;
            continue;
        }
        maxi*=n;
        maxi-=sum;
        maxi+=1;
        cout<<maxi<<endl;
    }
    return 0;
}