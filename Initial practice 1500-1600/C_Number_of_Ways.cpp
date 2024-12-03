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
    
    int n;
    cin>>n;
    if(n<3){
         cout<<0<<endl;
         return 0;
    }      
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0){
        cout<<0<<endl;
        return 0;
    }
    ll target = sum/3;
    vecll prefixWithTargetSum;
    sum=0;
    ll count=0;
    vecll ps(n,0);
    forn(0,n){
        sum+=a[i];
        if(sum==target){
            prefixWithTargetSum.pb(i);
        }
        ps[i]=sum;
    }
    sum=0;
    count=0;
    if(prefixWithTargetSum.size()>0){
         for(int i=n-1;i>0;--i){
            sum+=a[i];
            if(sum==target){
                int index = (lower_bound(itr(prefixWithTargetSum),i)) - prefixWithTargetSum.begin();
                index-=1; //since lower bound gives greater or equal val, and we want lesser val.
                if(index>=0){
                    ll midSum = ps[i-1] - ps[prefixWithTargetSum[index]];
                    if(midSum==target && i-1!=prefixWithTargetSum[index]){
                        count+=(index+1);
                    }
                    else count+=(index);
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
//ps = {0,1,0,0}
//pst = {0,2,3}
//