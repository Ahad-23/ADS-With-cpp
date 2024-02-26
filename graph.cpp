#include <iostream>
using namespace std;
class graph
{
  int cost[10][10];
  int cities;
public:
graph()
{
  cities=0;
  cout<<"Enter the number of cities:"<<endl;
  cin>>cities;
  for(int i=0;i<cities;i++)
    {
      for(int j=0;j<cities;j++)
        {
          cost[i][j]=999;
        }
    }
}

  void create()
{
  cout<<"Enter the cost matrix:"<<endl;
  for(int i=0;i<cities;i++)
    {
      for(int j=0;j<cities;j++)
        {
          bool choice=0;
          cout<<"Do you have edge between "<<i<<" and "<<j<<"(1/0)?"<<endl;
          cin>>choice;
          if(choice)
          {
            cout<<"Enter the cost of edge between "<<i<<" and "<<j<<endl;
            cin>>cost[i][j];
          }
          else
            cost[i][j]=999;
        }
    }
}

void display()
{
  cout<<"The cost matrix is:"<<endl;
  for(int i=0;i<cities;i++)
    {
      for(int j=0;j<cities;j++)
        {
          cout<<cost[i][j]<<" ";
        }
      cout<<endl;
    }
}

int prims( int start_v)
{
    int mincost=0;
    int t[cities][2];
    int nearest[cities];
    nearest[start_v]=-1;
        for(int i=0;i<cities-1;i++)
            {
            if(i!=start_v)
                nearest[i]=start_v;
            }
    int r=0;
    int j;
    for(int i=1;i<cities-1;i++)
        {
            int min=999;
            for(int k=0;k<cities-1;k++)
            {
                
                if(nearest[k]!=-1 && cost[k][nearest[k]]<min )
                {
                    j=k;
                    min=cost[k][nearest[k]];
                }
            }
        t[r][0]=j;
        t[r][1]=nearest[j];
        r=r+1;
        mincost+=cost[j][nearest[j]];
        nearest[j]=-1;

        for(int k=0;k<cities-1;k++)
        {
            if(nearest[k]!=-1&& cost[k][nearest[k]]>cost[k][j])
            nearest[k]=j;
        }
        return mincost;
        }
}
};

int main() {
 graph g1;
  g1.create();
  g1.display();
  cout<<"Enter the value of start_v"<<endl;
  int start_v;
  cin>>start_v;
  int mincost=g1.prims(start_v);
cout<<mincost<<endl;
}