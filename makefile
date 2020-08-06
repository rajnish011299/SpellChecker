# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -w
# ****************************************************


output: main.o trie.o metaphone.o editdistance.o spellcheck.o
	$(CXX) $(CXXFLAGS) -o output main.o trie.o metaphone.o editdistance.o spellcheck.o



main.o: main.cpp trie.h spellcheck.h metaphone.h editdistance.h
	$(CXX) $(CXXFLAGS)  -c main.cpp trie.cpp metaphone.cpp editdistance.cpp spellcheck.cpp


