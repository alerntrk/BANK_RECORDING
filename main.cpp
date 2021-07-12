#include"bank_rec.h"
int main()
{
     int choice;
     account A;

    cout<<"***Acount Information System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";

        cout<<"\n\t3-->Update Record";
        cout<<"\n\t4-->Delete Record";
        cout<<"\n\t5-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.writeRec();
            break;
        case 2:
            A.showRec();
            break;

        case 3:
            A.edit();
            break;
        case 4:
            A.Delete();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";

        }
    }
    system("pause");
    return 0;
}
