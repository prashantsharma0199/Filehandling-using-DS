#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::getline;

void insertion(fstream&);
void display(fstream&);

typedef struct ndata{
    int n_regid;
    string n_name;
    string n_email;
}ndata;

typedef struct node{
    ndata data;
    struct node *next;
}node;

node *head= NULL;
node *tail= NULL;
node *nw;

int main() {
    fstream n_file;
    

    int op=0;

    while(1){
        cout<<"Select any one of the following options"<<endl;
        cout<<"1. Register into the database"<<endl;
        cout<<"2. Display the Registration database"<<endl;
        cout<<"3. Exit\n\n";

        cin>>op;

        switch(op){
            case 1:{
                insertion(n_file);
                break;
            }

            case 2:{
                display(n_file);
                break;
            }

            case 3:{
                exit(0);
            }

            default:{
                cout<<"Invalid Input"<<endl;
            }
        }
        
    }
    
    
    return 0;  
}

void insertion(fstream& n_file){
    n_file.open("database.txt",std::ios::app);  
    
    if(!n_file){
        cout<<"Database creation failed\n"<<endl;
    }
    else{
        // n_file<<"RID\tName\tEmail Address\n"; 
        cout<<"Database created successfully\n"<<endl;
    } 

    int op;
    do{
        int regid;
        string name;
        string email;

        nw= (node*)malloc(sizeof(node));
        cout<<"Enter your 3-4 digit registration id: ";
        cin>>regid;
        cin.ignore(1,'\n');
        
        cout<<"Enter your complete name: ";
        getline(cin, name);

        cout<<"Enter your email address: ";
        getline(cin, email);

        nw->data.n_regid= regid;
        nw->data.n_name= name;
        nw->data.n_email= email;

        nw->next=NULL;

        if(head ==NULL && tail ==NULL){
            head=nw;
            tail=nw;
        }
        else if(tail!=NULL){
            tail->next=nw;
            tail=nw;
        }

        n_file<<regid<<"\t\t"<<name<<"\t"<<email<<"\n";  
        // n_file<<regid<<", "<<name<<", "<<email<<"\n";  

        cout<<"Press 0 to continue:";
        cin>>op;
        cout<<"\n";

    }while(op==0);  

    n_file.close();
}


void display(fstream& n_file){
    n_file.open("database.txt",std::ios::in);  
    
    if(!n_file){
        cout<<"\nDatabase access failed"<<endl;
    }
    else{
        // n_file<<"RID\t\tName\tEmail Address\n"; 
        cout<<"\nDatabase accessed successfully"<<endl;
    } 
    cout<<"\nRegistration Database\n\n";
    string str;
    while (getline(n_file, str)) {
        cout << str << "\n";
    }

    cout<<"\n";
    n_file.close();
}