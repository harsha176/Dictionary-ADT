Machine Problem #1
CS 241, Spring 2010

===============================================================================
1) PURPOSE

During the first few weeks in CS 241, you have learned the basics of C and how
C handles strings. This MP is designed to expose you to three main concepts:
 * How pointers work in C
 * How strings work in C
 * How functions work in C

This machine problem will be divided up into two pieces. In the first piece,
you will need to write some code to call some 'creatively defined' functions
so that those functions produce the desired output. In the second piece, you
will be creating a simple dictionary data structure to parse and hold the
values of the parsed strings.

While programming, ensure that you are writing readable code that correctly
frees up any memory you allocate. The grading section (see CS241.txt) outlines
points for program execution, memory management, and code documentation. You
should review the grading policy before you begin programming.


===============================================================================
2) ASSIGNMENT

This assignment is broken up into two parts, all of which must be completed
to receive full credit for the MP. 

[Part 1]:
  Edit the provided part1.c file to print out the twelve "Illinois" lines
  that are provided in the code inside mp1-functions.c.

  You will need to open up mp1-functions.c and read and understand the twelve
  different functions in order to figure out what code you need to write such
  that calling those functions will print out the "Illinois" line.

  Your output should look exactly like the following:

     1: Illinois
     2: Illinois
     3: Illinois
     4: Illinois
     5: Illinois
     6: Illinois
     7: Illinois
     8: Illinois
     9: Illinois
     10: Illinois
     11: Illinois
     12: Illinois

  You should NOT edit the mp1-functions.c file. In fact, when we grade your
  program, we will replace the mp1-functions.c file with a new version of
  the file (and we'll change the "Illinois" string so printing out
  "Illinois" in a for-loop will get you no credit).


[Part 2]:
  Edit the provided libdictionary/libdictionary.c file to implement a
  basic dictionary data structure.  We have already provided you with
  the struct dictionary_t (see libdictionary/libdictionary.h) that you will
  store the contents of your dictionary in. Further, we have already provided
  you with a simple program to populate your dictionary from a file (see
  part2.c).

  You will implement the following functions:


  int dictionary_init(dictionary_t *d):
     This function should initialize the dictionary data structure `d`.

     If the initialization was successful, return 0. Otherwise, return
     any non-zero integer.


  int dictionary_add(dictionary_t *d, char *key, char *value)
     This function should add the key `key`, with value `value`, to the
     dictionary `d`. You should make a copy of the strings `key` and `value`
     before adding them to the dictionary; you should NOT just store the
     pointer to the string that was passed in.

     If the key already exists in the dictionary, you should not edit the
     dictionary and return a non-zero integer. Otherwise, add the key/value
     pair and return 0.


  void dictionary_remove(dictionary_t *d, char *key)
     This function should remove the key `key` from the dictionary `d`, if it
     exists. (Remember, you have made local copies of the key and value strings,
     so you should free this memory here.)


  int dictionary_parse(dictionary_t *d, char *key_value)
     This is the most complex function and takes in a string `key_value` that
     will be formatted as an HTTP header field. The format of the string
     will always consist of a key followed immediately by a colon, a single
     space character, and the field value. The key must be at least one
     character in length. For the purpose of this MP, you can assume that
     the value portion will be the entire rest of the string `key_value`
     after the key, the colon, and the space.

     (You can read more about this format in the HTTP spec:
         http://www.w3.org/Protocols/HTTP/1.0/draft-ietf-http-spec.html#Message-Headers)

     After parsing the key and value portions of the string, you should call
     dictionary_add(...) to add the entry to your dictionary.

     If the string does not comply with the format given or if the call to 
     dictioanry_add(...) fails, you should return a non-zero integer.
     Otherwise, return 0.


  void dictionary_print(dictionary_t *d)
     This function should print out the entire contents of the dictionary.
     The print out should be done using the following print statement:

         printf("%s: %s", key, value);

     ...where key and value are variables storing the key and the value of
     the entry.


  void dictionary_destroy(dictionary_t *d)
     This function should remove all entries in the dictionary `d` (by calling 
     dictionary_remove()) and free up any other memory associated with the
     dictionary `d`.


  *NOTE*: While we provide you with some sample input, this input may not test
  all that is asked of you in this README. You should generate some new, more
  interesting input files to test the robustness of your program.


===============================================================================
3) COMPILING AND RUNNING YOUR PROGRAM

To compile these programs, we have provided a makefile for your use. To compile
the following programs, run the following commands from a command prompt on
a Linux machine:

   %> make clean
   %> make



After compiling the program, you will need to execute your compiled program to
ensure that it works as you intended.

  TO RUN... | RUN THE COMMAND...
  -----------------------------------------------------
  [Part 1]  | ./part1
  [Part 2]  | ./part2 input1.txt


===============================================================================
4) GRADING / SUBMISSION / OTHER DETAILS

Please fully read CS241.txt for more details on grading, submission, and other
topics that are shared between all MPs in CS 241.
