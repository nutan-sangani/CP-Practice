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

bool isPowerOf2(ll n){
    ll copy = n;
    int setIndices=0;
    while(copy){
        if(copy & 1LL){
            setIndices+=1;
        }
        copy/=2;
    }
    if(setIndices==1) return true;
    return false;
}

void solve(){
    int n;
    cin>>n;
    ll sum=0;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n!=0){
        cout<<"NO"<<endl;
        return;
    }
    umll count;
    ll avg = sum/n;
    forn(0,n){
        ll diff = avg - a[i];
        if(diff<0){ //means nikalna h.
            diff = abs(diff);
            ll upperPower = log2(diff)+1;
            ll totalRemoval = pow(2,upperPower);
            ll rem = totalRemoval - diff;
            if(isPowerOf2(rem)){
                count[rem]-=1;
                count[totalRemoval]+=1;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(diff>0){ //means dalna h
            ll upperPower = log2(diff)+1;
            ll totalAddition = pow(2,upperPower);
            ll rem = totalAddition - diff;
            if(isPowerOf2(rem)){
                count[rem]+=1;
                count[totalAddition]-=1;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        //probable bug for diff==0, par badme dekh
    }
    for(pll it : count){
        if(it.second!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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