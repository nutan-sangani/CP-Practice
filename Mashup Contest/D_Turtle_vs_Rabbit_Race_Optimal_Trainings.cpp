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

ll findGain(ll n,ll u){
    return ((n*u*1LL) - sumOfnNaturalNumbers(n-1));
}

void solve(){
    int n;
    cin>>n;
    vecll a(n,0);
    vecll prefixSum(n,0);
    ll sum=0;
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
        prefixSum[i]=sum;
    }
    int q;
    cin>>q;
    //ps = 
    forn(0,q){
        ll l,u;
        cin>>l>>u;
        l-=1;
        ll previ = l>0 ? prefixSum[l-1] : 0; 
        ll target = previ+u;
        ll index = (lower_bound(itr(prefixSum),target) - prefixSum.begin());
        // cout<<target<<" "<<index<<endl;
        if(lower_bound(itr(prefixSum),target)==prefixSum.end()){
            cout<<n<<" ";
            continue;
        }
        else{
            ll greater = index;
            ll smaller = index-1;
            ll maxi = -1;
            ll prev = l>0 ? prefixSum[l-1] : 0;
            ll temp = prefixSum[greater] - prev;
            maxi = findGain(temp,u);
            int idx = greater;
            if(smaller!=-1 && smaller>=l){
                temp = findGain(prefixSum[smaller] - prev,u);
                if(maxi<=temp){
                    idx = smaller;
                }
            }
            cout<<(idx+1)<<" ";
            continue;
        }
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