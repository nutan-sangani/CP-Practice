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
    ll n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    sort(itr(a));
    vecll nums(8,-1);
    ll xCount=0,yCount=0;
    int i=0;
    int lastI=-1;
    while(i<(n-1)){
        if(a[i]==a[i+1]){
            if(xCount==0){
                xCount=1;
                nums[0]=a[i];
                nums[1]=a[i];
                i+=2;
                continue;
            }
            else{
                xCount=2;
                nums[2]=a[i];
                nums[3]=a[i];
                lastI=i+1;
                break;
            }
        }
        i+=1;
    }
    i=n-1;
    while((i-1)>lastI){
        if(a[i]==a[i-1]){
            if(yCount==0){
                yCount=1;
                nums[7]=nums[6]=a[i];
                i-=2;
                continue;
            }
            else{
                yCount=2;
                nums[4]=nums[5]=a[i];
                break;
            }
        }
        i-=1;
    }
    if(xCount<2 || yCount<2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vecll x(4,0);
    vecll y(4,0);
    x[0]=x[1]=nums[0];
    x[2]=x[3]=nums[4];
    y[0]=y[3]=nums[2];
    y[1]=y[2]=nums[7];
    forn(0,4){
        cout<<x[i]<<" "<<y[i]<<" ";
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