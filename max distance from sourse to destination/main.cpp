/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void solve(int r,int c,vector<vector<int>>mat,vector<vector<bool>>visited,int&ans,int prow,int pcol,int dx,int dy,int pathlength){
    
    if(prow==dx &&pcol==dy)
    {
        if(ans<pathlength)
        {
            ans=pathlength;
        }
        return;
    }
    
    if(prow<0 ||pcol<0||prow>=r||pcol>=c||visited[prow][pcol]||mat[prow][pcol]==0)
    {
        return ;
    }
    visited[prow][pcol]=true;
    solve(r,c,mat,visited,ans,prow,pcol+1,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow,pcol-1,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow+1,pcol,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow-1,pcol,dx,dy,pathlength+1);
    visited[prow][pcol]=false;
    return;
}

int main()
{
    int r,c;
    cin>>r>>c;
    int x1,y1,x2,y2;
    vector<vector<int>>mat(r,vector<int>(c,0));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"enter the source indexes";
    cin>>x1>>y1;
    cout<<"enter the destination indexes";
    cin>>x2>>y2;
    int ans=INT_MIN;
    vector<vector<bool>>visited(r,vector<bool>(c,false));
    if(mat[x1][y1]==0)
    {
        cout<<"source is a hurdle";
    }
    else{
        solve(r,c,mat,visited,ans,x1,y1,x2,y2,0);
        cout<<"max distance from the source to destination is"<<endl;
    
        cout<<ans;
    }
    return ans;
}
