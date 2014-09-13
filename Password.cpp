#include "Password.h"
#include <iterator>
using CSC2110::ListArrayIterator;
using CSC2110::String;
using CSC2110::ListArray;

#include <iostream>
using namespace std;

Password::Password()
    : viable_words(new ListArray<String>), all_words(new ListArray<String>) {}

Password::~Password() {
    auto a_it = all_words->iterator();
    //auto v_it = viable_words->iterator();
    
    String* str;
    
    while (a_it->hasNext()) {
        str = a_it->next();
        delete str , str = 0;
    }
    
    /* // This block of code should NOT be executed, as the elements therein are already deleted from all_words
    while (v_it->hasNext()) {
        str = v_it->next();
        delete str , str = 0;
    }
    */
    
    delete viable_words , viable_words = 0;
    delete all_words , all_words = 0;
}

void Password::addWord(String* word) {
    viable_words->add(word);
    all_words->add(word);
}

void Password::guess(int try_password, int num_matches) {
    String* password = all_words->get(try_password);
    
    // NOTE: A get-based for loop is favored here, as using an iterator
    //       would result in potentially undefined side effects while
    //       removing elements.
    for (int i = 1; i <= viable_words->size(); i++) {
        if (getNumMatches(viable_words->get(i), password) != num_matches) {
            viable_words->remove(i);
            i--; // Make sure not to skip an element considering we just deleted one
        }
    }
}

int Password::getNumberOfPasswordsLeft() {
    return viable_words->size();
}




int Password::bestGuess()
{
   int best_guess_index = -1;
   int best_num_eliminated = -1;
   int num_viable_passwords = getNumberOfPasswordsLeft();

   //loop over ALL words, even if they have been eliminated as the password
   int count = 1;
   ListArrayIterator<String>* all_iter = all_words->iterator();
   while(all_iter->hasNext())
   {
      String* original_word = all_iter->next();

      //loop over only those words that could still be the password
      //count up the number of matches between a possible password and a word in the original list
      int* count_num_matches = new int[len + 1];

      for (int i = 0; i < len; i++) 
      {
         count_num_matches[i] = 0;
      }

      ListArrayIterator<String>* viable_iter = viable_words->iterator();
      while(viable_iter->hasNext())
      {
         String* viable_word = viable_iter->next();
         int num_matches = getNumMatches(viable_word, original_word);
         count_num_matches[num_matches]++;
      }
      delete viable_iter;

      //find the largest number in the count_num_matches array
      //the largest number indicates the guess that will generate the most eliminations
      int most_num_matches = 0;
      for (int j = 0; j < len; j++) 
      {
         int curr_num_matches = count_num_matches[j];
         if (curr_num_matches > most_num_matches)
         {
            most_num_matches = curr_num_matches;
         }
      }

      //compute the fewest that can possibly be eliminated by guessing the current word (original list)
      int num_eliminated = num_viable_passwords - most_num_matches;

      //select the word to guess that maximizes the minimum number of eliminations (minimax)
      if (num_eliminated > best_num_eliminated)
      {
         best_num_eliminated = num_eliminated;
         best_guess_index = count;
      }
      count++;
      delete[] count_num_matches;
   }

   delete all_iter;
   return best_guess_index;  //return a 1-based index into the all_words list of words (careful)
}

void Password::displayViableWords()
{
     //this needs to pull from the list of most probable passwords
     ListArrayIterator<String>* viable = viable_words->iterator();
     
     while(viable->hasNext()) {
            viable->next()->displayString();   
            cout << endl;
     }
}

String* Password::getOriginalWord(int index)
{
    return all_words->get(index);
}

int Password::getNumMatches(String* curr_word, String* word_guess) {
    auto fst = curr_word->getText();
    auto snd = word_guess->getText();
    
    int eql = 0;
    while ((*fst != 0) && (*snd != 0)) {
        if (*fst == *snd)
            eql++;
        fst++;
        snd++;
    }
    
    return eql;
    
}
