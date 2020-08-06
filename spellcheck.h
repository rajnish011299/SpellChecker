#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include<fstream>
#include <limits.h>
#include <string>
#include "trie.h"
#include "metaphone.h"
#include "editdistance.h"

static Dictionary trie;    
static metaphone generator;
    
std::string spellcheck(std::string&);


#endif
