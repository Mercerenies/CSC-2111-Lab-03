#if !defined PASSWORD_H
#define PASSWORD_H

#include "Text.h"
#include "ListArray.h"

// NOTE: The seemingly extraneous "CSC2110::" is used, as a "using CSC2110;" declaration
//       would leak into any files that include this header, which may be undesired.

class Password
{
   private:
      CSC2110::ListArray<CSC2110::String>* viable_words;  //the list of words that can still be the password
      CSC2110::ListArray<CSC2110::String>* all_words;  //the original list of words
      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(CSC2110::String* curr_word, CSC2110::String* word_guess);

   public:
    Password();
    ~Password();
    int bestGuess();
    void addWord(CSC2110::String* word);
    void guess(int try_password, int num_matches);
    int getNumberOfPasswordsLeft();
    void displayViableWords();
    CSC2110::String* getOriginalWord(int index);

};

#endif
