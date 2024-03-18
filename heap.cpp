#include<iostream>
using namespace std;

class Heap{
int arr[20];
int count;
public:
    Heap()
    {
        for(int i=0;i<count;i++)
        {
            arr[i]=0;
        }
    }


    void add()
    {
        int j=0;
        char choice;
        int elem;
        int count=0;
        do
        {
            cout<<"Enter the node"<<endl;
            cin>>elem;
            arr[j]=elem;
            insert(arr,j+1);
            j++;
            count++;
            cout<<"Do you want to enter more nodes(y/n)"<<endl;
            cin>>choice;
        } while (choice=='y');
            display();
    }

    void insert(int a[],int n)
    {
        int i=n;
        int elem=arr[n-1];
        if(i!=1)
        {
            while((i>1)&&(a[(i/2)-1]<elem))
            {
                a[i-1]=a[(i/2)-1];
                i=i/2;
            }
            a[i-1]=elem;
            
        }
    }

    void display()
    {
        for(int i=0;i<count;i++)
        {
            cout<<arr[i]<<"\t"<<endl;
        }
    }

   void deleteheap(){
    char ch;
    do{
        arr[0]=arr[0]+arr[count-1];
        arr[count-1]=arr[0]-arr[count-1];
        arr[0]=arr[0]-arr[count-1];
        count--;
        adjust(count-1,0);
        display();
        cout << "Do you want to delete more node: (y/n)";
        cin >> ch;
    } while (ch == 'y');
}
	
	void adjust(int n,int i){
    do{
        int j=2*i+1;
        if((j+1<=n)&&(arr[j+1]>arr[j]))
            j++;
            if(arr[i]>=arr[j])
                break;
            else{
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
                i=j;
            }
    }while(2*i+1<=n);
}
    
};

int main()
{
    Heap h;
    h.add();
    h.display();
    h.deleteheap();
}

