/*
 * Machine Problem #1
 * CS 241, Spring 2010
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libdictionary.h"
#include <assert.h>


enum _boolean_t { TRUE=0, FALSE};

typedef enum _boolean_t boolean_t;

static boolean_t is_key_present(dictionary_t* , char*);

static void rec_delete(dictionary_t*); 

int dictionary_init(dictionary_t *d)
{
      // allocate memory to it and see if memory is allocated successfully;
      //d = (dictionary_t *) malloc(sizeof(dictionary_t));
      if(d == NULL) {
         return -1;
      }
      assert(d != NULL);

      d->key = NULL;
      d->value = NULL;
      d->next = NULL;

      return 0;
}

int dictionary_add(dictionary_t *d, char *key, char *value)
{
        // check if dictionary is initialized
        assert(d != NULL);
 
        // check if key is already present if so return a non-zero value.
        if((d->key != NULL && is_key_present(d, key) == TRUE)) {
            return strlen(key);
        }

        // go to the end of the list
        while(d->next != NULL) { 
            d = d->next;
        }

        // add this key to the end of the list.
        // create a new dictionary item and append this to end of the list.
        assert(d->next == NULL);
        dictionary_t* new_d = d;
        if(d->key != NULL) {
          new_d = (dictionary_t*)malloc(sizeof(dictionary_t));
          memset(new_d, 0, sizeof(dictionary_t));
          d->next = new_d;
	}
        if(new_d == NULL) {
            d->next = NULL;
            return -1;
        }

        new_d->key = (char*)malloc(sizeof(char)*(strlen(key)+1));
        new_d->value = (char*)malloc(sizeof(char)*(strlen(value)+1));
        new_d->next = NULL;

        assert(new_d->key != NULL);
        assert(new_d->value != NULL);

        strcpy(new_d->key, key);
        strcpy(new_d->value, value);

	return 0;
}

void dictionary_remove(dictionary_t *d, char *key)
{
  // check if the key is present in the dictionary
  if(is_key_present(d, key) == TRUE) {
       // find the location of the dictionary entry to be removed.
       while(strcmp(d->next->key, key) != 0) {
           d = d->next;
           assert(d!= NULL);
       }
       assert(strcmp(d->next->key,key)==0);
       dictionary_t* to_be_removed = d->next;
       d->next = d->next->next;
       // free to_be_removed dictionary entry
       free(to_be_removed->key);
       free(to_be_removed->value);
       free(to_be_removed);
  }
}

int dictionary_parse(dictionary_t *d, char *key_value)
{
        char* key, *value;
        int len = strlen(key_value);
	assert(strlen(key_value) > 0);

        key = (char*)malloc(sizeof(char)*strlen(key_value));
        value = (char*)malloc(sizeof(char)*strlen(key_value));

        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(key));

        assert(key != NULL);
        assert(value != NULL);

        int i = 0;
        while (key_value[i] != ':' && key_value[i] != '\0') {
                assert(key_value[i] != '\0');
                assert(key_value[i] != ':');
                assert(i < len);
		key[i] = key_value[i]; 
		i++;
        }
        if(key_value[i] == '\0') {
           free(key);
           free(value);
           return -1;
        } 
        i++;
	key[i] = '\0';
        if(key_value[i] != ' ') {
           free(key);
           free(value);
           return -2;
        }	
        i++;
        strcpy(value, key_value+i);
        if(dictionary_add(d, key, value) != 0) {
           free(key);
           free(value);
           return -3;
        }
        free(key);
        free(value);
       
        return 0;
}

void dictionary_print(dictionary_t *d)
{
     printf("Printing dictionary contents\n");
     while(d != NULL) {
        printf("%s: %s\n", d->key, d->value);
        d = d->next;
     }
}

/*
 * Recursively delete the dictionary.
 */
void dictionary_destroy(dictionary_t *d)
{
    assert(d != NULL); 
    rec_delete(d->next);
    free(d->key); 
    free(d->value);     
}

static void rec_delete(dictionary_t* d) 
{ 
   if(d == NULL){
     return ;
   }
   else { 
      rec_delete(d->next);
      assert(d != NULL);
      free(d->key);
      free(d->value);
      free(d);
   }
}

/*
 * check if the given key is present in the dictionary
 */
static boolean_t is_key_present(dictionary_t* d, char* key) {
   while( d != NULL) {
        if(strcmp(d->key,key) == 0) {
           return TRUE;
        }
        d = d->next;
   }
   return FALSE;
}
