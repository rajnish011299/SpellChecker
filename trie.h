#ifndef TRIE_H
#define TRIE_H

#include<fstream>
#include<string>
const int alphabet_size = 26;
class Dictionary
{
private:
    struct Node
    {
        struct Node* child[alphabet_size] = {NULL};
        bool isEOW = false;
        long long int frequency = 0;
    };

    Node* head = new Node;

    void insert(std::string ,long long int);

    void build();

    bool search_code(std::string);

    long long int get_frequency_code(std::string);

    
    
public:
    Dictionary();
    
    bool search(std::string);
    
    long long int get_frequency(std::string);
    
};


#endif