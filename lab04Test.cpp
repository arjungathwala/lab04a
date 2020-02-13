#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Testing class WordCount..." << endl;

  string wordList[] =
  {"perm,lname,fname234",
    "12345Smith,Malory Logan",
    "q0189234;kf;jldkfj;lkasdf23984023",
    "2222222,Conrad,Phillip Todd",
    "8888888,Preble,Ethan Awesome",
    "1111111,Laux,Hunter",
    "can't",
    "good-hearted",
    "12mOnkEYs-$", 
    "mOnkEYs"};
  int items = 10;

  WordCount w;


  ASSERT_EQUALS(0,w.getNumUniqueWords());
  ASSERT_EQUALS(0,w.getTotalWords());
  ASSERT_EQUALS(0,w.getWordCount("test"));

  for (int i = 0; i < items - 1;i++) {
  	//cout << "passing in word : " << wordList[i] << endl;
	ASSERT_EQUALS(1,w.incrWordCount(wordList[i]));
  }
  ASSERT_EQUALS(2,w.incrWordCount(wordList[items - 1]));
  ASSERT_EQUALS(2,w.getWordCount("12monkeys"));
  ASSERT_EQUALS(1,w.getWordCount("can3't"));
  ASSERT_EQUALS(1,w.getWordCount("LA342@#$%@uxhunter"));
  ASSERT_EQUALS(8,w.getNumUniqueWords());
  ASSERT_EQUALS(10,w.getTotalWords());
  ASSERT_EQUALS(true,w.isWordChar('a'));
  ASSERT_EQUALS(false,w.isWordChar('%'));
  ASSERT_EQUALS("fum",w.makeValidWord("...fum***"));
  ASSERT_EQUALS("",w.makeValidWord("--$$--"));

  WordCount a;

  ASSERT_EQUALS(2,a.incrWordCount("foO"));
  ASSERT_EQUALS(2,a.incrWordCount("foo"));
  ASSERT_EQUALS(1,a.incrWordCount("bAr"));
  ASSERT_EQUALS(1,a.incrWordCount("Bar"));
  ASSERT_EQUALS(1,a.incrWordCount("foo#bar"));
  ASSERT_EQUALS(1,a.incrWordCount("foo_bar-"));
  ASSERT_EQUALS(1,a.incrWordCount("'foo-bar-"));
  ASSERT_EQUALS(0,a.incrWordCount("--$$--"));
  ASSERT_EQUALS(7,a.getTotalWords());
  ASSERT_EQUALS(4,a.getNumUniqueWords());

  return 0;
}
