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

void displayAns(vector<int>& ans){
    int n = ans.size();
    forLoop
        cout<<ans[i]<<" ";
    cout<<endl;
}

void helper(string s)
{
    int n = s.size();
    if(n==1){
        cout<<0<<endl;
        return;
    }
    vector<int> ans(n,0);
    int front,rear;
    front=s[0];
    rear=s[1];
    if(n==2){
        ans[0]=0;
        if(front<rear){
            ans[1]=0;
        }
        else ans[1]=1;
        displayAns(ans);
        return;
    }
    int i=2;
    while(i<n){
        if(front==rear){
            while(i<n && s[i]==front){
                i++;
            }
            if(i>=n) break;
            else{
                ans[i-1]=0;
                rear=s[i];
                i++;
                continue;
            }
        }
        if(rear==s[i]){
            ans[i-1]=0;
            i++;
            continue;
        }
        else{
            ans[i-1]=1;
            int temp=front;
            front=rear;
            rear=temp;
            i++;
            continue;
        }
    }
    if(front>rear){
        ans[n-1]=1;
    }
    displayAns(ans);
    return;
}

int main()
{
    FASTIO
    
    string s;
    cin>>s;
    helper(s);
    return 0;
}