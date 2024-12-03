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

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vecll> a;
    vecll temp;
    forn(0,n){
        int l=0;
        cin>>l;
        for(int j=0;j<l;j++){
            ll k;
            cin>>k;
            temp.pb(k);
        }
        sort(itr(temp));
        a.pb(temp);
        temp.clear();
    }
    vector<pll> pairs;
    ll maxi = -1;
    forn(0,n){
        int j=0;
        ll mex1=-1;
        ll mex2=-1;
        int size=a[i].size();
        ll count=0;
        while(j<size){
            if(a[i][j]<count){
                j+=1;
                continue;
            }
            else if(a[i][j]>count){
                if(mex1==-1){
                    mex1=count;
                    count+=1;
                    continue;
                }
                else if(mex2==-1){
                    mex2=count;
                    break;
                }
            }
            else{
                count+=1;
                j+=1;
            }
        }
        if(j==size && mex1==-1){
            mex1=count;
            mex2=mex1+1;
        }
        else if(j==size) mex2=count;
        pairs.pb(mp(mex1,mex2));
        maxi = max<ll>(maxi,mex2);
    }
    //sum of m elements from x to m will be equal to sum of m natural numbers,
    //than minus x-1 ka sum
    ll ans=0;
    if(m>maxi){
        ans = sumOfnNaturalNumbers(m) - sumOfnNaturalNumbers(maxi-1);
        m = maxi-1;
    }
    ans+=(maxi)*(m+1LL);
    cout<<ans<<endl;
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