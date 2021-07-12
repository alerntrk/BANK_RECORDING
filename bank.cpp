#include"bank_rec.h"
void account::readData(){
cout<<"enter name:  ";
cin>>name;
cout<<"enter surname:   ";
cin>>surname;
cout<<"enter account number:    ";
cin>>ac_no;
cout<<"enter total balance ";
cin>>total_balance;
}
void account::writeRec(){
    account a;
    readData();
    a=(*this);
    string ac_n=ac_no;
    ifstream f;
    f.open("bank.bin", ios::binary);
    bool flag=false;
    while(!f.eof()){
            if(f.read(reinterpret_cast<char*>(this),sizeof(*this))){

                if(ac_n==ac_no){
                   flag=true;
                   cout<<"unavaileble account number..."<<endl;
                    break;
                }
        }
    }
   (*this)=a;
    f.close();
    if(flag==false){
   ofstream outfile;
    outfile.open("bank.bin", ios::binary|ios::app);
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
    isempty=false;
    }
}
void account::printData(){
    cout<<"-------------------"<<endl<<name<<endl<<surname<<endl<<ac_no<<endl<<total_balance<<"-------------------"<<endl;
}
void account::showRec(){

    ifstream f("bank.bin",ios::binary);
    while(!f.eof()){
        if(f.read(reinterpret_cast<char*>(this),sizeof(*this))) printData();
    }
    f.close();
}
void account::edit(){

        string ac_n;
        cout<<"enter the account number of the account to be editted ";
        cin>>ac_n;
        fstream f("bank.bin",ios::binary|ios::in|ios::out);
        int n=0;
        while(!f.eof()){
            if(f.read(reinterpret_cast<char*>(this),sizeof(*this))){
                n++;
                if(ac_n==ac_no){
                    readData();
                    f.seekg((n-1)*sizeof(*this));
                    f.write(reinterpret_cast<char*>(this),sizeof(*this));
                    break;
                }
        }
    }
    f.close();
}

void account::Delete(){

    string ac_n;
    cout<<"enter the account number of the account to be deleted ";
    cin>>ac_n;
    ifstream f("bank.bin",ios::binary);
    ofstream fn("newbank.bin",ios::binary|ios::app);
    int c=0;

    while(!f.eof()){
        c++;
        if(f.read(reinterpret_cast<char*>(this),sizeof(*this))){
            if(ac_n!=ac_no)fn.write(reinterpret_cast<char*>(this),sizeof(*this));
        }
    }
    if(c==1)isempty=true;

    f.close();fn.close();
    remove("bank.bin");
    rename("newbank.bin","bank.bin");

}
