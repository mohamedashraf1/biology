#include "DNA.h"
#include<cmath>
#include <iostream>
using namespace std;
DNA::DNA()
{}

DNA ::DNA(const char* p,DNA_Type atype): Sequence(strlen(seq)){

    strcpy(this->seq, p);
    type=atype;
}


DNA::DNA(DNA& rhs){
    this->seq=new char [strlen(rhs.seq)];

        strcpy(this->seq, rhs.seq);

    type=rhs.type;
}
DNA::~DNA(){
    delete [] seq;
}

void DNA::Print(){
    cout<<"the DNA is : ";
    for(int i=0 ; i<strlen(seq) ; i++){
        cout<<seq[i];
    }
        cout<<endl<<endl;
        string arr[4]={"promoter","motif","tail","noncoding"};
        cout<<arr[type]<<endl;
}
void DNA::set_startIndex(int num)
{
    if(num==-1){
        startIndex=0;
    }
    else{
    startIndex = num-1;
    }
}

void DNA::set_endIndex(int num)
{
    if(num==-1){
        endIndex=strlen(seq);
    }
    else{
    endIndex = num;
    }
}

int DNA::get_startIndex()
{
    return startIndex;
}

int DNA::get_endIndex()
{
    return endIndex;
}

void DNA::BuildComplementaryStrand(int s , int e)
{
    complementary_strand=new DNA;
    set_startIndex(s);
    set_endIndex(e);
    complementary_strand->seq[strlen(seq)]='\0';
    int c=0;
    for(int i=endIndex ; i>startIndex ; i--){
        if(seq[i]='A'){
            complementary_strand->seq[c]='T';
            c++;
        }
        else if(seq[i]=='T'){
            complementary_strand->seq[c]='A';
            c++;
        }
        else if(seq[i]=='G'){
            complementary_strand->seq[c]='C';
            c++;
        }
        else if(seq[i]=='C'){
            complementary_strand->seq[c]='G';
            c++;
        }
    }
}

RNA DNA::ConvertToRNA(int s,int e)
{
    set_startIndex(s);
    set_endIndex(e);
    char* arr=new char[strlen(seq)+1];
    for(int i=startIndex ;i<endIndex+1 ;i++){
            if(complementary_strand->seq[i]=='T'){
                arr[i]='U';
            }
            else{
                arr[i]=complementary_strand->seq[i];
            }
        }
    RNA r(arr,mRNA);
    return r;
}

ostream &operator<<(ostream &out ,DNA& obj){
    out<<obj.seq;
    return out;
}

istream &operator >>(istream &in,DNA& obj){
    int len;
    string s="invalid sequence";
    cout<<"enter the DNA length"<<endl;
    cin>>len;
    obj.seq=new char[len+1];
    cout<<"enter the seq :";
    for (int i=0 ; i<len ; i++){
        in>>obj.seq[i];
        if(obj.seq[i]!='A' &&obj.seq[i]!='T'&&obj.seq[i]!='G'&&obj.seq[i]!='C'){
            throw s;
        }
}
    return in;
}

bool DNA::operator ==(DNA& obj){
    int a=0;
    if(strlen(seq)==strlen(obj.seq)){
        for(int i=0 ; i<strlen(seq) ; i++){
            if(seq[i]!=obj.seq[i]){
                a=1;
            }
        }
    }
    else {
        cout<<"they have different size :";
    }
    if(a==1){
        return false;
    }
    else{
        return true;
    }
}
bool DNA::operator !=(DNA& obj){
    int a=0;
    if(strlen(seq)==strlen(obj.seq)){
        for(int i=0 ; i<strlen(seq) ; i++){
            if(seq[i]!=obj.seq[i]){
                a=1;
            }
        }
    }
    else {
        cout<<"they have different size :";
    }
    if(a==1){
        return true;
    }
    else{
        return false;
    }
}
void DNA::LoadSequenceFromFile()
{
    string name;
    fstream datafile;
    char filename[80];
    cout<<"Please, Enter file name : ";
    cin.getline(filename,80);
    datafile.open(filename);
    while(!datafile.eof() && !datafile.fail())
    {
        datafile >> name;
    }
    seq = new char [name.size()];
    for(int i=0 ; i<name.size()+1 ; i++)
    {
        seq[i]=name[i];
    }
    datafile.close();
}

void DNA::SaveSequenceToFile()
{
    fstream datafile;
    char filename[80];
    cout<<"Please, Enter file name : ";
    cin.ignore();
    cin.getline(filename,80);
    datafile.open(filename,ios::app);
    for(int i=0 ; i<strlen(seq) ; i++)
    {
        datafile << seq[i];
    }
    datafile.close();
}
DNA DNA::operator+ (DNA& d) {
    int m = strlen(seq), n = strlen(d.seq);
    char *result = new char[(m + n)+1];
    int c=0;
    result[(m + n)]='\0';
    for(int i=0;i<m;i++){

        result[i]=seq[i];
    }
    for(int i=m;i<m+n;i++){
        result[i]=d.seq[c];
        c++;
    }
    DNA temp(result,tail);
    return temp;
}
DNA DNA :: operator= (const DNA& D)
{
    seq = new char [strlen(D.seq)];
    for(int i=0 ; i<strlen(D.seq) ; i++)
    {
        seq[i] = D.seq[i];
    }
    return *this;
}



