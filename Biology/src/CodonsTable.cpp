#include "CodonsTable.h"
#include <fstream>
#include <iostream>
using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}
CodonsTable::~CodonsTable(){
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName){
    ifstream text;
    text.open(codonsFileName.c_str());
    int c=0;
    while(text>>codons[c].value,text>>codons[c].AminoAcid){
            c++;
    }
}
Codon CodonsTable::getAminoAcid(char * value){
    //value=new char[4];
    for(int i=0 ; i<64 ; i++){
        if(value[0]==codons[i].value[0]&&value[1]==codons[i].value[1]&&value[2]==codons[i].value[2]){
            return (codons[i]);
        }
    }
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index){
    Codon m;
    for(int i=0 ; i<4 ; i++){
        m.value[i]=value[i];
    }
    m.AminoAcid=AminoAcid;
    codons[index]=m;
}
