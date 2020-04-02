#ifndef PROTEIN_H
#define PROTEIN_H
#include "DNA.h"

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class DNA;

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p,Protein_Type  atype);
 	 	~Protein();
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
           DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
           void LoadSequenceFromFile();
           void Print();
           friend ostream &operator<<(ostream &out ,Protein obj);
           friend istream &operator>>(istream &out ,Protein obj);
           bool operator ==(Protein obj);
           bool operator !=(Protein obj);
           void SaveSequenceToFile();
           Protein operator+ (Protein& d) ;
           Protein operator= (const DNA& D);


};

#endif // PROTEIN_H
