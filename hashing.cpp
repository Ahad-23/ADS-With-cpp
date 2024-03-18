//Implementation of  direct access file using Hashing: linear probing with replacment and without replacment

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
    int rollno;
    char name[20];
    int marks;
    friend class Hashing;
};
class Hashing
{
   public:
   Hashing()
   {
       int i;
       student e;
       fstream file("data.txt",ios::app|ios::binary);
       file.seekp(0,ios::end);
       for(i=0;i<10;i++)
       {
           e.rollno=-1;
           strcpy(e.name,"----");
           e.marks=-1;
           file.write((char*)&e,sizeof(e));
       }
       file.close();
   }
   void display_hashtable();
   void linearprowithoutrep();
   void linearprobingwithrep();
};
void Hashing::linearprobingwithrep()
{
    student e;
    int loc,i,newloc;
    char ch;
    fstream file("data.txt",ios::in|ios::out|ios::binary);
    do{
        fflush(stdin);
        file.seekp(0,ios::beg);
        cout<<"Enter rollno,name and marks";
        cin>>e.rollno>>e.name>>e.marks;
        loc=e.rollno%10;
        student temp;
        file.seekg((long int)loc*(sizeof(e)),ios::beg);
        file.read((char*)&temp,sizeof(temp));
        if(temp.rollno==-1)
        {
            cout<<"Inside first if";
            file.seekp((long int)loc*sizeof(e),ios::beg);
            file.write((char*)&e,sizeof(e));
        }
        else
        {
            newloc=temp.rollno%10;
            if(newloc==loc)
            {
            for(i=(loc+1)%10;i!=loc;i=(i+1)%10)
            {
                file.seekg((long int)i*sizeof(e),ios::beg);
                file.read((char*)&temp,sizeof(temp));
                if(temp.rollno==-1)
                {
                    cout<<"inside if";
                    file.seekp((long int)i*sizeof(e),ios::beg);
                    file.write((char*)&e,sizeof(e));
                    break;
                }
            }
            }
            else
            {
                student temp1=temp;
                file.seekp(loc*sizeof(e),ios::beg);
                file.write((char*)&e,sizeof(e));
                for(i=(loc+1)%10;i!=loc;i=(i+1)%10)
                {
                    file.seekg(i*sizeof(e),ios::beg);
                    file.read((char*)&temp,sizeof(temp));
                    if(temp.rollno==-1)
                    {
                        file.seekp(i*(sizeof(e)),ios::beg);
                        file.write((char*)&temp1,sizeof(temp1));
                        break;
                    }
                }
            }
            if(i==loc) cout<<"Hash Table full";
        }
        file.flush();
        display_hashtable();
    cout<<"Do you want to continue";
    cin>>ch;
    }while(ch=='y');
}

void Hashing::linearprowithoutrep()
{
    student e;
    int loc,i;
    char ch;
    fstream file("data.txt",ios::in|ios::out|ios::binary);
    do{
        fflush(stdin);
        file.seekp(0,ios::beg);
        cout<<"Enter rollno,name and marks";
        cin>>e.rollno>>e.name>>e.marks;
        loc=e.rollno%10;
        student temp;
        file.seekg((long int)loc*(sizeof(e)),ios::beg);
        file.read((char*)&temp,sizeof(temp));
        if(temp.rollno==-1)
        {
            cout<<"Inside first if";
            file.seekp((long int)loc*sizeof(e),ios::beg);
            file.write((char*)&e,sizeof(e));
        }
        else
        {
              cout<<"Inside else";
            for(i=(loc+1)%10;i!=loc;i=(i+1)%10)
            {
                file.seekg((long int)i*sizeof(e),ios::beg);
                file.read((char*)&temp,sizeof(temp));
                if(temp.rollno==-1)
                {
                    cout<<"inside if";
                    file.seekp((long int)i*sizeof(e),ios::beg);
                    file.write((char*)&e,sizeof(e));
                    break;
                }
            }
            if(i==loc) cout<<"Hash Table full";
        }
        file.flush();
        display_hashtable();
    cout<<"Do you want to continue";
    cin>>ch;
    }while(ch=='y');
}
void Hashing::display_hashtable()
{
    int i;
    student a;
    cout<<"RollNo"<<"|"<<"Name"<<"|"<<"Marks"<<endl;
   ifstream file("data.txt",ios::in|ios::binary);
   
   while(file.read((char *)&a,sizeof(a)))
   {
    cout<<a.rollno<<"|"<<a.name<<"|"<<a.marks<<endl;
   }
    file.close();
}
int main()
{
    Hashing h;
    h.display_hashtable();
  h.linearprowithoutrep();
  h.display_hashtable();
 h.linearprobingwithrep();

    return 0;
}