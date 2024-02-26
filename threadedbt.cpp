#include <iostream>
using namespace std;

class tbtnode
{
    char data;
    bool rbit;
    bool lbit;
    tbtnode *rightc;
    tbtnode *leftc;
    friend class tbt;

public:
    tbtnode()
    {
        lbit = 0;
        rbit = 0;
    }
};
class tbt{
    tbtnode *head;
    public:
    void create()
    {
    tbtnode *root=new tbtnode;
    cout<<"Enter data for root node"<<endl;
    cin>>root->data;
    head->lbit=1;
    root->leftc=root->rightc=head;
    head->leftc=root;
    char ch;
    char ch1;

    do{
        int flag=0;
        tbtnode *temp=root;
        tbtnode *curr=new tbtnode;
        cout<<"Enter data"<<endl;
        cin>>curr->data;
        while(flag==0){
            cout<<" Left or Right (l/r)"<<endl;
            cin>>ch;
            if(ch=='l'){
                if(temp->lbit==0){
                    curr->rightc=temp;
                    curr->leftc=temp->leftc;
                    temp->leftc=curr;
                    temp->lbit=1;
                    flag=1;
                }
                else{
                    temp=temp->leftc;
                }
            }
            else if(ch=='r'){
                if(temp->rbit==0){
                    curr->leftc=temp;
                    curr->rightc=temp->rightc;
                    temp->rightc=curr;
                    temp->rbit=1;
                    flag=1;
                }
                else{
                    temp=temp->rightc;
                }
            }
        }
        cout<<"Enter more nodes (y/n)"<<endl;
        cin>>ch1;
    }while(ch1=='y');
}

   void preorder(){
        tbtnode* temp = head->leftc;
        while(temp!= head){
            cout << temp->data;
            while(temp->lbit != 0){
                temp = temp->leftc;
                cout << temp->data;

            }
            while(temp->rbit == 0){
                temp = temp->rightc;
            }
            temp = temp->rightc;
}}

    tbtnode* presuccr(tbtnode *temp);
    void inorder()
    {
    tbtnode *temp=head;
    while(1){
        temp=insuccr(temp);
        if(temp==head)
            break;
        cout<<temp->data;
    }
}
    tbtnode *insuccr(tbtnode *temp){
    tbtnode *x= new tbtnode;
    x=temp->rightc;
    if(temp->rbit==1){
        while(x->lbit==1){
            x=x->leftc;
        }
    }
    return x;
}
    tbt(){
        head=new tbtnode;
        head->rbit=1;
        head->leftc=head;
        head->rightc=head;
    }
    friend class tbtnode;
};







int main(){
    tbt t;
t.create();
t.inorder();
cout<<endl;
t.preorder();
}