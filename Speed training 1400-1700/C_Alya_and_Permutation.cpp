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

void makeWithOdd(ll n,vecll& ans,umll& takenNumber,int end){
    ans.pb(n);
    takenNumber[n]=1;
    takenNumber[1]=1;
    takenNumber[3]=1;
    //abhi n ke last bit pe if 1 h, toh usko zero krna h.
    //can do it using XOR, 
    ll value = n ^ 1LL;
    takenNumber[value]=1;
    ans.pb(value);
    ans.pb(3);
    ans.pb(1);
    forn(1,end+1){
        if(takenNumber[i]==0){
            ans.pb(i);
        }
    }
} //this adds 4 no.s thus cannot make number less then 4
void solve(){
    ll n;
    cin>>n;
    vecll ans;
    ll k=0;
    ll amountToMakeWithOdd = n;
    umll takenNumber;
    if(n==6){
        int kk[6]={1, 2, 4, 6, 5, 3};
        cout<<7<<endl;
        forn(0,6){
            cout<<kk[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(n%2==0){
        ans.pb(n);
        takenNumber[n]=1;
        amountToMakeWithOdd = pow(2,floor(log2(n)))-1LL;
    }
    makeWithOdd(amountToMakeWithOdd,ans,takenNumber,n);
    reverse(itr(ans));
    k = n | amountToMakeWithOdd;
    cout<<k<<endl;
    forn(0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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