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
          cout<<"Do you have edge between "<<i+1<<" and "<<j+1<<"(1/0)?"<<endl;
          cin>>choice;
          if(choice)
          {
            cout<<"Enter the cost of edge between "<<i+1<<" and "<<j+1<<endl;
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
          cout<<cost[i][j]<<"\t";
        }
      cout<<endl;
    }
}

int prims()
{
    int start_v;
    int r=0;
    int j;
    int mincost=0;
    int min;
    int t[cities-1][3];
    int nearest[cities];
    cout<<"Enter starting vertex"<<endl;
    cin>>start_v;
    nearest[start_v]=-1;
        for(int i=0;i<cities-1;i++)
            {
            if(i!=start_v)
                nearest[i]=start_v;
            }
    
    for(int i=0;i<cities-1;i++)
        {
             min=999;
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
        t[r][2]=min;
        r=r+1;
        mincost+=cost[j][nearest[j]];
        nearest[j]=-1;

        for(int k=0;k<cities-1;k++)
        {
            if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
            nearest[k]=j;
        }
        cout<<"T matrix"<<endl;
        for(int i=0;i<cities;i++)
        {
          for(int a=0;a<3;a++)
          {
            cout<<t[i][a]<<"\t";
          }
          cout<<"\n";
        }
        
        }
        return mincost;
}
};

int main() {
 graph g1;
  g1.create();
  g1.display();
  int mincost=g1.prims();
cout<<"Mincost:"<<mincost<<endl;
}