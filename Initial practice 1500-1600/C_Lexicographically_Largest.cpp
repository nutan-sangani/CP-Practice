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
        forn(0,n){
            ll b;
            cin>>b;
            a[i]=b+i+1;
        }
        vecll ans;
        umll count;
        set<ll> not_used;
        //8,8,9,10,12,13,13,14
        forn(0,n){
            if(count[a[i]]==0){
                ans.pb(a[i]);
                count[a[i]]=1;
                if(not_used.find(a[i])!=not_used.end()){
                    not_used.erase(a[i]);
                    if(count[a[i]-1]==0){
                        not_used.insert(a[i]-1);
                    }
                }
                else{
                    int val = a[i];
                    if(count[(val)-1]==0){
                        not_used.insert(val-1);
                    }
                }
            }
            else{
                auto it = not_used.lower_bound(a[i]);
                it--;
                ll val = *it;
                not_used.erase(it);
                count[val]=1;
                ans.pb(val);
                if(count[(val)-1]==0){
                    not_used.insert(val-1);
                }
            }
        }
        sort(itr(ans),greater<ll>());
        for(ll x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//8,8,9,10,12,13,13,14
//8,7,9,10,12,13,11,14
//14,13,12,11,10,9,8,7