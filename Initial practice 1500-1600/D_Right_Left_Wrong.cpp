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
        string s;
        cin>>s;
        vecll L;
        vecll R;
        vecll prefixSum(n,0);
        ll sum=0;
        forn(0,n){
            sum+=a[i];
            prefixSum[i]=sum;
            if(s[i]=='L'){
                L.pb(i);
            }
            else R.pb(i);
        }
        reverse(itr(L));
        sum=0;
        while(!L.empty() && !R.empty()){
            int start,end;
            int l1 = L.size();
            int r1 = R.size();
            start = L[l1-1];
            end = R[r1-1];
            if(start<end){
                ll temp = prefixSum[end];
                ll prev = start>0 ? prefixSum[start-1] : 0;
                temp -= prev;
                sum+=temp;
            }
            L.pop_back();
            R.pop_back();
        }
        cout<<sum<<endl;
    }
    return 0;
}