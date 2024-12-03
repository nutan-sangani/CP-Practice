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
    int ans=0;
    int flag=0;
    char prev=s[0];
    int n=s.size();
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(s[i]==prev){
            prev=s[i];
            continue;
        }
        else{
            if(flag==0 && (prev=='0' && s[i]=='1')){
                prev=s[i];
                flag=1;
            }
            else{
                ans++;
                prev=s[i];
            }
            continue;
        }
    }
    cout<<ans+1<<endl;
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