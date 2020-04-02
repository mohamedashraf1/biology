#ifndef DNA_H
#define DNA_H
#include "RNA.h"
#include "Sequence.h"
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>

enum DNA_Type{promoter, motif, tail, noncoding};


class RNA;

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(const char* p,DNA_Type atype);

        DNA(DNA& rhs);
        void set_startIndex(int num);
        void set_endIndex(int num);
        int get_startIndex();
        int get_endIndex();
        ~DNA();
 	 	// function printing DNA sequence information to user
        void Print();

        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand(int s ,int e);
        RNA ConvertToRNA(int s,int e);
         void LoadSequenceFromFile();
         void SaveSequenceToFile();
        //int getIndex();
        friend ostream &operator<<(ostream &out ,DNA& obj);
        friend istream &operator >>(istream &in,DNA& obj);
        bool operator ==(DNA& obj);
        bool operator !=(DNA& obj);
        DNA operator+ (DNA& d);
        DNA operator= (const DNA& D);
  };


#endif // DNA_H
