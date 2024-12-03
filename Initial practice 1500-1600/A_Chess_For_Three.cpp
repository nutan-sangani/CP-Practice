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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        if(((p1+p2+p3)%2)!=0){
            cout<<-1<<endl;
            continue;
        }
        int half = (p1+p2+p3)/2;
        if(p3>half){
            int totalDraw=0;
            int diff1 = p3-p2;
            totalDraw = min(p2,p3);
            totalDraw += min(diff1,p1);
            cout<<totalDraw<<endl;
            continue;
        }
        else cout<<(p1+p2+p3)/2<<endl;
    }
    return 0;
}