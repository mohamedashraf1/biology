#include <iostream>
using namespace std;
#include "CodonsTable.h"
#include "DNA.h"
#include "Sequence.h"
#include "RNA.h"
#include "Protein.h"

void DNA_menu();
void RNA_menu();
void Protein_menu();
void Add_Sequence();
void Equal_Sequence();

int main()
{
    while(true)


    {


        cout<<"Welcome To Our Program.\n"
            <<"1- Enter DNA Sequence.\n"
            <<"2- Enter RNA Sequence.\n"
            <<"3- Enter Protein Sequence.\n"
            <<"4- Add Two Sequences.\n"
            <<"5- Check if Two Sequence Are Equal.\n"
            <<"6- Check if Two Sequence Are Not Equal.\n"
            <<"0- Exit.\n";

        int choice;
        cout<<"Please, Enter Your Choice >>> ";
        cin>>choice;
        cout<<endl;
        if(choice==1)
        {
            DNA_menu();
        }
        else if(choice==2)
        {
            RNA_menu();
        }
        else if(choice==3)
        {
            Protein_menu();
        }
        else if (choice==4)
        {
            Add_Sequence();
        }
        else if (choice==5 || choice==6)
        {
            Equal_Sequence();
        }
        else if (choice==0)
        {
            break;
        }
        else
            cout<<"Please, Enter a right number : ";
    }
    return 0;
}


void DNA_menu()
{
    DNA D;
    cout<<"1- Load DNA Sequence From File.\n"
        <<"2- Enter DNA Sequence From Console.\n";
    int num ;
    cout<<"Please, Enter Your Choice >>> ";
    cin>>num;
    if(num==1)
    {
        D.LoadSequenceFromFile();
    }
    else if (num==2)
    {
        try
        {
            cin>>D;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
    }
    D.Print();
    cout<<"1- Convert To RNA.\n"
        <<"2- Convert To Protein.\n"
        <<"3- Save DNA Sequence To File.\n";
    int n;
    cout<<"Please, Enter Your Choice >>>> ";
    cin>>n;
    if(n==1)
    {
        int x,y;
        cout<<"enter the start index :";
        cin>>x;
        cout<<"enter the end index :";
        cin>>y;
//        D.set_startIndex(x);
//        D.set_endIndex(y);
        D.BuildComplementaryStrand(x,y);
        RNA R;
        R = D.ConvertToRNA(x,y);
        R.Print();
        cout<<"Do You Want To Save The RNA Sequence..... Type Y/N >>>>> ";
        char c;
        cin>>c;
        if(c=='Y')
        {
            R.SaveSequenceToFile();
        }
    }
    else if(n==2)
    {
        int x,y;
        cout<<"enter the start index :";
        cin>>x;
        cout<<"enter the end index :";
        cin>>y;
        D.BuildComplementaryStrand(x,y);
        RNA r ;
//        r= D.ConvertToRNA(x,y);
        CodonsTable obj;
        Protein p = r.ConvertToProtein(obj);
        p.Print();
        cout<<"Do You Want To Save The Protein Sequence..... Type Y/N >>>>> ";
        char c;
        cin>>c;
        if(c=='Y')
        {
            p.SaveSequenceToFile();
        }
    }
    else if (n==3)
    {
        D.SaveSequenceToFile();
    }
}

void RNA_menu()
{
    RNA R;
    cout<<"1- Load RNA Sequence From File.\n"
        <<"2- Enter RNA Sequence From Console.\n";
    int num ;
    cout<<"Please, Enter Your Choice >>> ";
    cin>>num;
    if(num==1)
    {
        cin.ignore();
        R.LoadSequenceFromFile();
    }
    else if (num==2)
    {
        try
        {
            cin>>R;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
    }
    R.Print();
    cout<<"1- Convert To DNA.\n"
        <<"2- Convert To Protein.\n"
        <<"3- Save DNA Sequence To File.\n";
    int n;
    cout<<"Please, Enter Your Choice >>>> ";
    cin>>n;
    if(n==1)
    {
        DNA D;
//        D = R.ConvertToDNA();
        D.Print();
        cout<<"Do You Want To Save The DNA Sequence..... Type Y/N >>>>> ";
        char c;
        cin>>c;
        if(c=='Y')
        {
            D.SaveSequenceToFile();
        }
    }
    else if (n==2)
    {
        CodonsTable obj;
        Protein P = R.ConvertToProtein(obj);
        P.Print();
        cout<<"Do You Want To Save The Protein Sequence..... Type Y/N >>>>> ";
        char c;
        cin>>c;
        if(c=='Y')
        {
            P.SaveSequenceToFile();
        }
    }
}

void Protein_menu()
{
    Protein P;
    cout<<"1- Load RNA Sequence From File.\n"
        <<"2- Enter RNA Sequence From Console.\n";
    int num ;
    cout<<"Please, Enter Your Choice >>> ";
    cin>>num;
    if(num==1)
    {
        P.LoadSequenceFromFile();
    }
    else if (num==2)
    {
        try
        {
            cin>>P;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
    }
    P.Print();
    cout<<"1- Save DNA Sequence To File.\n";
    int n;
    if(n==1)
    {
        P.SaveSequenceToFile();
    }
}

void Add_Sequence()
{
    cout<<"1- Two DNA Sequence.\n"
        <<"2- Two RNA Sequence.\n"
        <<"3- Two Protein Sequence.\n";
    int num;
    cout<<"Please, Enter Your Choice >>>> ";
    cin>>num;
    if(num==1)
    {
        DNA D1, D2 ;
        cout<<"Enter First DNA Sequence : "<<endl;
        try
        {
            cin>>D1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second DNA Sequence : "<<endl;
        try
        {
            cin>>D2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        DNA D3 ;
        D3= D1 + D2 ;
        cout<<"The Third DNA Sequence : "<<endl;
        D3.Print();
    }
    else if (num==2)
    {
        RNA R1, R2 ;
        cout<<"Enter First RNA Sequence : "<<endl;
        try
        {
            cin>>R1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second RNA Sequence : "<<endl;
        try
        {
            cin>>R2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        RNA R3;
      R3= R1 + R2 ;
        cout<<"The Third RNA Sequence : "<<endl;
        R3.Print();
    }
    else if (num==3)
    {
        Protein P1, P2 ;
        cout<<"Enter First DNA Sequence : "<<endl;
        try
        {
            cin>>P1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second DNA Sequence : "<<endl;
        try
        {
            cin>>P2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        Protein P3 = P1 + P2 ;
        cout<<"The Third DNA Sequence : "<<endl;
        P3.Print();
    }
}

void Equal_Sequence()
{
    cout<<"1- Check If Two DNA Sequence Are Equal.\n"
        <<"2- Check If Two RNA Sequence.\n"
        <<"3- Check If Two Protein Sequence.\n";
    int num;
    if(num==1)
    {
        DNA D1, D2 ;
        cout<<"Enter First DNA Sequence : "<<endl;
        try
        {
            cin>>D1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second DNA Sequence : "<<endl;
        try
        {
            cin>>D2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        if(D1==D2)
        {
            cout<<"The Two DNA Sequences Are Equal."<<endl;
        }
        else if (D1!=D2)
        {
            cout<<"The Two DNA Sequence Are Not Equal."<<endl;
        }
    }
    else if (num==2)
    {
        RNA R1, R2 ;
        cout<<"Enter First RNA Sequence : "<<endl;
        try
        {
            cin>>R1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second RNA Sequence : "<<endl;
        try
        {
            cin>>R2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        if(R1==R2)
        {
            cout<<"The Two RNA Sequences Are Equal."<<endl;
        }
        else if (R1!=R2)
        {
            cout<<"The Two RNA Sequence Are Not Equal."<<endl;
        }
    }
    else if (num==3)
    {
        Protein P1, P2 ;
        cout<<"Enter First Protein Sequence : "<<endl;
        try
        {
            cin>>P1;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        cout<<"Enter Second Protein Sequence : "<<endl;
        try
        {
            cin>>P2;
        }
        catch(string s)
        {
            cout<<s<<endl;
            return ;
        }
        if(P1==P2)
        {
            cout<<"The Two Protein Sequences Are Equal."<<endl;
        }
        else if (P1!=P2)
        {
            cout<<"The Two Protein Sequence Are Not Equal."<<endl;
        }
    }
}
