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

void helper(string s,int n)
{
    int count=0;
    int permit=0;
    for(int i=0;i<n;i++){
        if(i>permit){
            break;
        }
        if(s[i]=='.'){
            permit=i+2;
            continue;
        }
        else if(s[i]=='@'){
            count++;
            permit=i+2;
            continue;
        }
        else{
            continue;
        }
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        helper(s,n);
    }
    return 0;
}