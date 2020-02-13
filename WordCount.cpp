// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	//cout << "2 start" << endl;
	int count = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (vector<pair<string,size_t>>::const_iterator it = table[i].begin(); it < table[i].end(); it++) {
			count += it->second;
		}
	}
	return count;
}

int WordCount::getNumUniqueWords() const {
	//cout << "3 start" << endl;
	int count = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (vector<pair<string,size_t>>::const_iterator it = table[i].begin(); it < table[i].end(); it++) {
			cout << "found word " << it->first << " with num items " << it->second << endl;
			count++;
		}
	}
	return count;
}

int WordCount::getWordCount(std::string word) const {
	word = stripWord(word);
	for (size_t i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	//cout << "recieved word : " << word << endl;
	for (vector<pair<string,size_t>>::const_iterator it = table[hash(word)].begin(); it < table[hash(word)].end(); it++) {
		if (it->first == word) {
			return it->second;	
		}
	}
	return 0;
}
	

int WordCount::incrWordCount(std::string word) {
	//cout << "5 start" << endl;
	word = stripWord(word);
	if (word == "")
		return 0;

	for (size_t i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	for (vector<pair<string,size_t>>::iterator it = table[hash(word)].begin(); it < table[hash(word)].end(); it++) {
		//cout << "found word " << it->first << endl;
		if (it->first == word) {
			//cout << "found matching word" << endl;
			it->second++;
			return it->second;	
		}
	}
  	std::pair<std::string, size_t> newPair = {word,1};
	//cout << word << " inserted at " << hash(word) << endl;  	
	table[hash(word)].push_back(newPair);
	//cout << "5 end" << endl;
	return 1;
}


bool WordCount::isWordChar(char c) {
	if (isalpha(c))
		return true;
	return false;
}


std::string WordCount::stripWord(std::string word) {
	cout << "7 start" << endl;
	//trim left
	if (word.length() == 0)
		return "";


	while (!isalpha(word[0]) && word.length() > 0) {
		if (word.length() == 1)
			return "";
			
		cout << "erasing start char " << word[0] << endl;	
		word = word.substr(1,word.length());
		cout << word << endl;
	}
	
	cout << "7 : 1" << endl;	
	//trim right
	

	while (!isalpha(word[word.length()-1]) && word.length() > 0) {
		if (word.length() == 1)
			return "";

		cout << "erasing end char " << word[word.length()-1] << endl;	
		word = word.substr(0,word.length()-1);
		cout << word << endl;
	}

	cout << "7 : 2" << endl;
	
	// scan for bad chars in the middle
	unsigned long i = 1;
	while (word.length() > 2 && i < word.length() - 2) {
		cout << "found char - " << word[i];
		if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-') {
			cout << "   not char, erasing" << endl;
			word = word.substr(0, i) + word.substr(i + 1, word.length() - 1);	
		}
		else {
			i++;
			cout << "   good" << endl;
		}
	}
	cout << "7 : 3" << endl;
	// convert string to upper
	cout << "string : " << word << endl;
	cout << "7 end" << endl;
	return word;
}
