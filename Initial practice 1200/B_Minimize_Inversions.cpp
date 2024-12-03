#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void helper()
{
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> list(n,make_pair(1,2));
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            list[i].first=val;
        }
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            list[i].second=val;
        }
        sort(list.begin(),list.end());
        for(int i=0;i<n;i++){
            cout<<list[i].first<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<list[i].second<<" ";           
        }
        cout<<endl;
    }
    return 0;
}