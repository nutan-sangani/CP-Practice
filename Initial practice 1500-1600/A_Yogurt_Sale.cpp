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

using namespace std;

void helper(int n,int a,int b)
{
    if(b<2*a){
        int count = n/2;
        ll cost = (b*count*1LL);
        cost+=(n%2)*(a*1LL);
        cout<<cost<<endl;
        return;
    }
    else{
        cout<<a*1LL*n<<endl;
        return;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        helper(n,a,b);
    }
    return 0;
}