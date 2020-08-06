#ifndef METAPHONE_H
#define METAPHONE_H

#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<map>
#include<vector>


static const char *VOWELS="AEIOU",
     *FRONTV="EIY",
     *VARSON="CSPTG";

class metaphone{
	std::map<std::string,std::vector<std::string> > sound_dict;
public:
	metaphone();
	std::string sound(std::string&);
	std::vector<std::string> get(std::string&);

};

#endif
