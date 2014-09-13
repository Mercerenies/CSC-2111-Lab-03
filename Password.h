#if !defined PASSWORD_H
#define PASSWORD_H

#include "Text.h"
#include "ListArray.h"

// NOTE: The seemingly extraneous "CSC2110::" is used, as a "using CSC2110;" declaration
//       would leak into any files that include this header, which may be undesired.

///The class to manage a password session of hacking.
/**
 * An instance of Password is constructed. It is then occupied using addWord
 * on all the words. guess will narrow the results based on a potential guess,
 * and bestGuess will determine the next best guess from the viable passwords
 * that remain.
 */
class Password
{
   private:
      CSC2110::ListArray<CSC2110::String>* viable_words;  //the list of words that can still be the password
      CSC2110::ListArray<CSC2110::String>* all_words;  //the original list of words
      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(CSC2110::String* curr_word, CSC2110::String* word_guess);

   public:
    ///Construct an empty Password instance
    Password();
    ///Destroy and clean up the password session
    ~Password();
    ///Determine the best guess out of all the possible words
    int bestGuess();
    ///Add a word to the list of all passwords
    void addWord(CSC2110::String* word);
    ///Perform a guess and narrow down the viable passwords
    void guess(int try_password, int num_matches);
    ///Get the number of potential passwords remaining
    int getNumberOfPasswordsLeft();
    ///Display the possible remaining passwords
    void displayViableWords();
    ///Look up a given index in the list of originally possible passwords
    CSC2110::String* getOriginalWord(int index);

};

#endif
