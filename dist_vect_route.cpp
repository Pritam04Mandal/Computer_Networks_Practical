#include<conio.h>
#include <iostream>
#include<stdlib.h>
using namespace std;
class node{
public:
int dist[20];
int from[20];
}route[10];
int main()
{
    int dm[20][20],no;
    cout<<"Enter the number of nodes: ";
    cin>>no;
    cout<<"Enter the distance matrix........(Enter 999 if no direct connection available)"<<endl;
    for (int i=0;i<no;i++)
    {
        for (int j=0;j<no;j++)
        {
        cin>>dm[i][j];
        dm[i][i]=0;
        route[i].dist[j]=dm[i][j];
        route[i].from[j]=j;
        }
    }
    int flag=0;
    do
    {
        flag=0;
        for(int i=0;i<no;i++)
        {
            for(int j=0;j<no;j++)
            {
                for(int k=0;k<no;k++)
                {
                    if(route[i].dist[j]>(dm[i][k]+(route[k].dist[j])))
                    {
                        route[i].dist[j]=dm[i][k]+(route[k].dist[j]);
                        route[i].from[j]=k;
                        flag++;
                    }
                }
            }
        }
    }while(flag!=0);
    for (int i = 0; i< no; i++)
    {
        cout<<"Router info for router: "<<i+1<<endl;
        cout<<"Dest\tNext Hop\tDist" <<endl;
        for (int j = 0; j< no; j++)
        {
            cout<<j+1<<"\t"<<route[i].from[j]+1<<"\t\t"<<route[i].dist[j]<<endl;
        }
    }
    getch();
    return 0;
}
