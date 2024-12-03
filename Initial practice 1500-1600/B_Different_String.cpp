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

void helper(string s)
{
    umll map;
    int n=s.size();
    int x,y;
    vector<ll> indexes;
    for(int i=0;i<n;i++){
        if(map[s[i]]==0){
            indexes.pb(i);
        }
        map[s[i]]++;
    }
    if(map[s[0]]==n){
        cout<<"NO"<<endl;
        return;
    }
    char temp = s[indexes[0]];
    s[indexes[0]]=s[indexes[1]];
    s[indexes[1]]=temp;
    
    cout<<"YES"<<endl;
    forLoop
        cout<<s[i];
    cout<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        helper(s);
    }
    return 0;
}