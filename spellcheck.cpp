#include "spellcheck.h"

std::string spellcheck(std::string& word)
{       
        for(int i=0;i<word.size();i++)
        {
            if('A'<=word[i] && word[i]<='Z')
                word[i] = 'a' + (word[i]-'A');
            else if('a'<=word[i] && word[i]<='z')
                continue;
            else
            {
                word = "*************ERROR***********";
                return word;
            }
        }
		if(trie.search(word))
        {
            
            return word;
        }
        std::string ans;                      //the correct word
        int cost = INT_MAX;             //cost of edit distance operation
      
        std::string sound_word = generator.sound(word);           //sound_word now contains sound of misspelt word word

        for(int i=0;i<generator.get(sound_word).size();i++)     //Apply Edit Distance on all words with same sound as word
        {
            int current_cost = editdistance(generator.get(sound_word)[i],word);
            if(current_cost<cost)
            {
                cost = current_cost;
                ans = generator.get(sound_word)[i];
            }
            else if(current_cost==cost && trie.get_frequency(generator.get(sound_word)[i])>trie.get_frequency(ans)) //when edit distance is same but the
            {
                ans = generator.get(sound_word)[i];                                                                 //current word is more probable
            }
        }

        if(cost == INT_MAX)  // if there is NO MATCHING SOUND WORDS IN THE DICTIONARY
        {
            std::fstream fin;
            fin.open("dict.txt",std::ios::in);
            std::string dict_word;
            long long int dict_word_freq;
            while(fin>>dict_word)
            {
                fin>>dict_word_freq;
                int current_cost = editdistance(dict_word,word);
                if(current_cost<cost)
                {
                    cost = current_cost;
                    ans = dict_word;
                }
                else if(current_cost==cost && dict_word_freq>trie.get_frequency(ans)) //when edit distance is same but the
                {
                    ans = dict_word;                                           //current word is more probable
                }
            }
            fin.close();
        }

        return ans;
}
