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
    ll n,m,d;
    cin>>n>>m>>d;
    vecll a(m,0);
    forn(0,m){
        cin>>a[i];
    }
    ll sum;
    if(a[0]==1) sum=0;
    else sum=1;
    forn(0,m){
        ll prev = i>0 ? a[i-1] : 1;
        // sum+=findCountEaten(prev,a[i],d,true);
        sum+=(((a[i]-prev-1)/d)+1);
    }
    if(a[m-1]!=n){
        sum+=(((n-a[m-1])/d));  //isme plus one nhi hoga.
    }
    ll mini=LLONG_MAX;
    ll count=0;
    forn(1,m-1){
        ll prevSum,nextSum,currSum;
        prevSum = ((a[i]-1-a[i-1])/d)+1;
        nextSum = ((a[i+1]-1-a[i])/d)+1; //plus 1,since a[i+1] pe humesha cookie milegi
        currSum = ((a[i+1]-1-a[i-1])/d)+1;
        ll temp = sum + currSum - prevSum - nextSum;
        if(temp<mini){
            mini=temp;
            count=1;
        }
        else if(temp==mini){
            ++count;
        }
    }
    //custom made for 1st wala element.
    ll temp = sum;
    if(m>1)
        temp -= (((a[1]-1-a[0])/d)+1);
    if(a[0]!=1)
        temp -= (((a[0]-1-1)/d)+1);
    ll first = 1;
    ll last = m>1 ? a[1] : a[0];
    temp += (((last-1-first)/d)+1);
    if(temp<mini){
        mini=temp;
        count=1;
    }
    else if(temp==mini){
        ++count;
    }
    temp = sum;
    if(m>1)
        temp -= (((a[m-1]-1-a[m-2])/d)+1);
    if(a[m-1]!=n)
        temp -= (((n-a[m-1])/d));
    first = m>1 ? a[m-2] : a[m-1];
    last = n;
    temp += (((last-first)/d));
    if(temp<mini){
        mini=temp;
        count=1;
    }
    else if(temp==mini){
        ++count;
    }
    cout<<mini<<" "<<count<<endl;
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