#include "spellcheck.h"
#include <iostream>

int main()
{

    std::string word ;     //the incorrect word
    std::cout<<"Enter a word to verify its spelling or ESC to exit\n";

    while(std::cin>>word && word!=std::string(1,27))
    {
       
        std::string ans = spellcheck(word);
        std::cout<<ans<<std::endl<<std::endl;
    }
}

