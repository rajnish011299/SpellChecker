#include "trie.h"

void Dictionary::insert(std::string key,long long int fre)
    {
        Node* temp = head;
        for(int i=0;i<key.size();i++)
        {
            int index = key[i]-'a';
            if(temp->child[index] == NULL)
                temp->child[index] = new Node;
            temp = temp->child[index];
        }
        temp->isEOW = true;
        temp->frequency = fre;
    }
void Dictionary::build()
    {
        std::fstream fin;
        fin.open("dict.txt");
        std::string word;
        while(fin>>word)
        {
            long long int f; fin>>f;
            insert(word,f);
        }
    }
bool Dictionary::search_code(std::string key)
    {
        Node* temp = head;
        for(int i=0;i<key.size();i++)
        {
            int index = key[i]-'a';
            if(temp->child[index] == NULL)
                return false;
            temp = temp->child[index];
        }
        return (temp!=NULL && temp->isEOW);
    }
long long int Dictionary::get_frequency_code(std::string key)
    {
        Node* temp = head;
        for(int i=0;i<key.size();i++)
        {
            int index = key[i]-'a';
            if(temp->child[index] == NULL)
                return false;
            temp = temp->child[index];
        }
        return temp->frequency;
    }
Dictionary::Dictionary()
    {
        build();
    }
bool Dictionary::search(std::string s)
    {
        return search_code(s);
    }
long long int Dictionary::get_frequency(std::string s)
  	{
        return get_frequency_code(s);
  	}