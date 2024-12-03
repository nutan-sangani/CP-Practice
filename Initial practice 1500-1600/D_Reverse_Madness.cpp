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

void helper(string s,int n,int k)
{
    vecll l(k),r(k);
    for(int i=0;i<k;i++)
        cin>>l[i];
    for(int i=0;i<k;i++)
        cin>>r[i];
    int q;
    cin>>q;
    vecll count(n,0);
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        count[x-1]++;
    }
    for(int i=0;i<k;i++){
        int a,b;
        a=l[i]-1;
        b=r[i]-1;
        int sum=0;
        int mid = (a+b)/2;
        int z=0;
        for(int j=a;j<=mid;j++){
            sum+=count[a+z]+count[b-z];
            if(sum%2!=0){
                char temp = s[a+z];
                s[a+z]=s[b-z];
                s[b-z]=temp;
            }
            z++;
        }
    }
    cout<<s<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        helper(s,n,k);
    }
    return 0;
}