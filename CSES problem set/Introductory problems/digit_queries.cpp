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

ll Ceil(ll a,ll b){
    return a%b==0 ? a/b : ((a/b)+1);
}

ll getDigitFromNumber(ll n,ll i){
    ll digit=-1LL;
    while(i>0){
        digit = n%10LL;
        n/=10LL;
        --i;
    }
    return digit;
}

void solve(){
    ll n;
    cin>>n;
    ll i=1LL;
    pll prevRange(0LL,0LL);
    pll currRange;
    ll multiple=1LL;
    while(1){
        ll begin = prevRange.second+1LL;
        ll end = (9LL*multiple*i+begin-1LL);
        currRange.first=begin;
        currRange.second=end;
        if(currRange.first<=n && currRange.second>=n){
            break;
        }
        multiple*=10LL;
        ++i;
        prevRange=currRange;
    }
    n-=prevRange.second;
    ll konsaNumber = Ceil(n,i);
    ll number = (multiple)+konsaNumber-1LL;
    ll konsaDigit = n%i;
    if(konsaDigit==0LL){
        konsaDigit=i;
    }
    konsaDigit = (i-konsaDigit+1LL);
    ll digit = getDigitFromNumber(number,konsaDigit);
    cout<<digit<<endl;
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
//isme bahot time laga due to implementation error. Division and mod etc krte waqt dekh
//if ceil ya aisa kuch lena ho toh.