#Frequency Dictionary
##1. Problem
With Google Search, while you key in any sequence of characters, there is always a list
of words/phrases as guesses of your input (see below for a screen shot while you put in a
letter “U”).

Such a guess is mostly based on the frequency of the keywords that have been used by
Google users. This assignment is to simulate such a facility. To do this, you firstly have
to build up a frequency dictionary, i.e., a dictionary with a statistics of how often each
word is used. You can learn such a dictionary by reading a number of articles and
calculating the frequency of appearances of each word. Once you have such a dictionary,
you can dynamically create a priority queue of words that matches the input of a user and
display such a queue (or part of the queue). For instance, if you get an input of character
“u”, you will provide a list of words/phrases starting with “u” in the order of their
frequency (not necessarily all the words beginning with the letter). The list should be
dynamically updated once another character is put in, say “n”.

Your list can be empty if there is no word/phase that matches to your input.

##2. Requirements

###2.1 Coding
**Basic tasks (50 marks):** Implement a frequency dictionary. For efficiency of use, we
required the dictionary to be stored in an AVL tree. The AVLTree ADT is available in
vUWS for both C++ and Java users. You can also use any AVLTree ADT
implementation from other resources for either more functionalities or higher efficiency.
You can change the existing code of an AVLTree ADT for your purpose. Your program
should have the following functionalities:
  1. Build a dictionary, represented in an AVL tree, by reading any text file. Each
node of the AVL tree represents a word (as the key) and its frequency (as data).
  2. Print the whole dictionary with the information of each word and its frequency.
  3. Print the AVL tree with the information of the total number of words in the
dictionary, and the balance factor and level of each node in the tree (you may use
the built-in functions of AVLTree ADT).

**Add-on task set 1 (15 marks):** Extend your base level code so that a list of guessed
words will display while you key in a sequence of characters. Your program should have
the following functionalities on top of the pass level code:
  4. Generate a priority queue for each input of characters in the order of frequency
from your frequency dictionary.
  5. Display the list of words from the priority queue according to your input.

**Add-on task set 2 (10 marks):** Extend your code to enable of learning a frequency
dictionary from multiple files. Your program should have the following functionalities on
top of the credit level code:
  6. Save your dictionary into a file.
  7. Rebuilt your dictionary by reading the dictionary file saved previously (Note that
the way you save the dictionary determines the efficiency you rebuild the
dictionary).
  8. Extend your program so that it can read multiple text files to enhance your
frequency dictionary.

**Add-on task set 3 (10 marks):** Extend your frequency dictionary so that it can also
include phrases. You can limit the length of a phrase to two to three words and include
only highly frequently appeared phrases. Note that you might have to make changes for
other functions so that the input and output work well with phrases.

**Add-on task set 4 (10 marks):** Extend your frequency dictionary so that it can delete
words/phrases with lower frequency (users supply a threshold, say 0.1 per thousand
words). If you implement it by adding more functions in the AVL ADT, you receive 10
marks. If you implement it by exporting the dictionary into a file and then reload the
dictionary from the file, you receive 5 marks.

You can receive up to 90 marks for coding.

Note: To avoid spending too much time on the assignment, you do not have to implement
a fancy GUI. Focus on your algorithms and data structures.

###2.2 Documentation
In this assignment, you are required to submit a formal document no matter which level
of code you have implemented. You will lose 10% of marks if you do not submit your
document. The document should explain the algorithms and data structures you have
used in your code. You should also use the document to demonstrate the depth of your
understanding of the data structures you have used in your code. Your document should
include the following sections (marking will be tougher than I did in assignment 1):
  1. Introduction: demonstrate your understanding of the problem.
  2. Algorithms: Choose two algorithms (functions) in your program to explain your
idea of implementation using pseudocode or simplified source code (list the major
operations only).
  3. Data Structures: List all the major data structures you have used for your
implementation and briefly explain why they need to be used.
  4. Complexity analysis: Depending on the level of your code, you would need to
show the complexity of the following operations:
    * The complexity of building up a frequency dictionary assuming that the
total number of words in the text file is n.
    * The complexity of generating a priority queue for a string, assuming the
total number of words in the dictionary is n (for Credit or upper level
only).
    * The complexity of rebuilding a dictionary from a dictionary file (for D or
HD level only).
  5. Conclusion: summarize what you did. 