#include "Sequence.h"

Sequence::Sequence()
{
}

Sequence::Sequence(int length)
{
	seq = new char[length];

}

Sequence::~Sequence()
{
	delete seq;
}

Sequence::Sequence(const Sequence& rhs)
{
	seq = new char[sizeof(rhs.seq)];
	for (int i = 0; i <strlen(rhs.seq); i++)
		seq[i] = rhs.seq[i];
}

char*  Align(Sequence* s1,Sequence* s2)
{

}
