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

void helper(int a,int b,int c,int d)
{
    if(a>b){
        int temp = a;
        a=b;
        b=temp;
    }
    if(c>d){
        int temp = c;
        c=d;
        d=temp;
    }
    //2 9, 6 10
    if((c<=b && c>=a) && d>=b){
        cout<<"YES"<<endl;
        return;
    }
    else if((a<=d && a>=c) && b>=d){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        helper(a,b,c,d);
    }
    return 0;
}