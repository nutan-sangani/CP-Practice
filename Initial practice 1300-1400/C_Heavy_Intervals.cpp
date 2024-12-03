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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vector<ll> l,vector<ll> r,vector<ll> c,ll n){
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    sort(c.begin(),c.end(),greater<ll>());
    vector<ll> diff(n);
    forLoop
        diff[i]=r[i]-l[i];
    sort(diff.begin(),diff.end());
    ll ans=0;
    // forLoop
    //     ans+=(c[i]*diff[i]*1LL);
    // cout<<ans<<endl;
    forLoop
        cout<<diff[i]<<" ";
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> l(n);
        vector<ll> r(n);
        vector<ll> c(n);
        forLoop
            cin>>l[i];
        forLoop
            cin>>r[i];
        forLoop
            cin>>c[i];
        helper(l,r,c,n);
    }
    return 0;
}
//20439 23390 46555 81217 81570 l
//97805 160683 160994 176054 184462 r 
//9      8      4      3       1    c
//77366 94837 102892 114439 137293 diff


//1 2
//3 4 (2,2) vs (1,3)
//1 2 (2+4) vs (3+2)
//1,2,3,4 = (())

//1,2,5,20
//3,4,10,30
//1,2,3,4,5,10,20,30 = (())()()
//1,3,5,10
//3,3,2,2

//25 45
//10 5
//475