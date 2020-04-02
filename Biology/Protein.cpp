#include "Protein.h"

Protein::Protein()
{
    //ctor
}
Protein::Protein(char*p,Protein_Type  atype): Sequence(strlen(p)){

     strcpy(this->seq, p);
     type=atype;

}
Protein::~Protein(){
delete [] seq;
}
DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA){

}
void Protein::Print(){
     cout<<"the PROTIEN is : ";
    for(int i=0 ; i<strlen(seq) ; i++){
        cout<<seq[i];
    }
    cout<<endl<<endl;
      string arr[4]={"Hormon", "Enzyme", "TF", "Cellular_Function"};
        cout<<arr[type]<<endl;

}
ostream &operator<<(ostream &out ,Protein obj){
    out<<obj.seq;
    return out;
}
istream &operator >>(istream &in,Protein obj){
    int len;
    cout<<"enter the RNA length"<<endl;
    cin>>len;
    for (int i=0 ; i<len ; i++){
        in>>obj.seq[i];
    }

}
bool Protein::operator ==(Protein obj){
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
bool Protein::operator !=(Protein obj){
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

void Protein::LoadSequenceFromFile(){
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

void Protein::SaveSequenceToFile()
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

Protein Protein::operator+ (Protein& d) {
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
    Protein temp(result,TF);
    return temp;
}
Protein Protein :: operator= (const DNA& D)
{
    seq = new char [strlen(D.seq)];
    for(int i=0 ; i<strlen(D.seq) ; i++)
    {
        seq[i] = D.seq[i];
    }
    return *this;
}

