#include "RNA.h"
#include <cmath>
RNA::RNA()
{
    //ctor
}

RNA::RNA(const char * p, RNA_Type atype): Sequence(strlen(p)){
    //seq=new char[strlen(p)];
   strcpy(this->seq, p);
    type=atype;
}
RNA::RNA(RNA& rhs){
    this->seq=new char [strlen(rhs.seq)];

        strcpy(this->seq, rhs.seq);

    type=rhs.type;
}
void RNA::set_startIndex(int num)
{
    if(num==-1){
        startIndex=0;
    }
    else{
    startIndex = num-1;
    }
}

void RNA::set_endIndex(int num)
{
    if(num==-1){
        endIndex=strlen(seq);
    }
    else{
    endIndex = num;
    }
}

int RNA::get_startIndex()
{
    return startIndex;
}

int RNA::get_endIndex()
{
    return endIndex;
}
void RNA::Print(){
    cout<<"the rna is : ";
  for(int i=0 ; i<strlen(seq) ; i++){
        cout<<seq[i];
    }
        cout<<endl<<endl;
        string arr[4]={"mRNA", "pre_mRNA", "mRNA_exon", "mRNA_intron"};
        cout<<arr[type]<<endl;
}
Protein RNA::ConvertToProtein(const CodonsTable & table){
char check[4];
char *amino;
amino=new char[(strlen(seq))/3];
int c=0 , p=0;
for(int i=0 ; i<strlen(seq) ; i+=3){
    for(int j=0 ; j<3 ; j++){
        check[j]=seq[c];
        c++;
    }
    for(int z=0 ; z<64 ; z++){
        if(check[0]==table.codons[z].value[0]&&check[1]==table.codons[z].value[1]&&check[2]==table.codons[z].value[2]){
            amino[p]=table.codons[z].AminoAcid;
            p++;
        }
    }
}
Protein p1(amino,TF);
return p1;
}
DNA RNA::ConvertToDNA(int s , int e){
    set_startIndex(s);
    set_endIndex(e);
char* arr=new char[strlen(seq)];
    for(int i=startIndex ; i<endIndex ;i++){
            if(seq[i]=='U'){
                arr[i]='T';
            }
            else{
                arr[i]=seq[i];
            }
            cout<< arr[i];
        }
    RNA r(arr,mRNA);


}
RNA::~RNA(){

}
ostream &operator<<(ostream &out ,RNA obj){
    out<<obj.seq;

    return out;
}
istream &operator >>(istream &in,RNA obj){
    int len;
    cout<<"enter the RNA length"<<endl;
    cin>>len;
    for (int i=0 ; i<len ; i++){
        in>>obj.seq[i];
    }

}
bool RNA::operator ==(RNA obj){
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
bool RNA::operator !=(RNA obj){
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

void RNA:: LoadSequenceFromFile(){
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

void RNA::SaveSequenceToFile()
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
RNA RNA::operator+ (RNA& d) {
    int m = strlen(seq), n = strlen(d.seq);
    char *result = new char[(m + n)+1];
    int c=0;
    result[(m + n)+1]='\0';
    for(int i=0;i<m;i++){

        result[i]=seq[i];
    }
    for(int i=m;i<m+n;i++){
        result[i]=d.seq[c];
        c++;
    }
    RNA temp(result,mRNA);
    return temp;
}
RNA RNA ::operator= (const RNA& D)
{
    seq = new char [strlen(D.seq)];
    for(int i=0 ; i<strlen(D.seq) ; i++)
    {
        seq[i] = D.seq[i];
    }
    return *this;
}

