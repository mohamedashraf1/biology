#ifndef RNA_H
#define RNA_H
#include "CodonsTable.h"
#include "Protein.h"
#include "DNA.h"
#include "Sequence.h"



enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class DNA;
class Protein;

class RNA : public Sequence
{
  	private:
        RNA_Type type;
        int startIndex;
        int endIndex;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(const char * p, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
        void set_startIndex(int num);
        void set_endIndex(int num);
        int get_startIndex();
        int get_endIndex();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
         Protein ConvertToProtein(const CodonsTable & table);
         void LoadSequenceFromFile();
         void SaveSequenceToFile();
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA(int s, int e);
        friend ostream &operator<<(ostream &out ,RNA obj );
        friend istream &operator >>(istream &in,RNA obj);
        bool operator ==(RNA obj);
        bool operator !=(RNA obj);
        RNA operator+ (RNA& d);
        RNA operator= (const RNA& D);
};

#endif // RNA_H
