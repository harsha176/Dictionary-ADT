/*
 * Machine Problem #1
 * CS 241, Spring 2010
 */

#ifndef LIBDICTIONARY_H__
#define LIBDICTIONARY_H__

typedef struct _dictionary_t
{
	char *key, *value;
	struct _dictionary_t *next;
} dictionary_t;


int dictionary_init(dictionary_t *d);
int dictionary_add(dictionary_t *d, char *key, char *value);
void dictionary_remove(dictionary_t *d, char *key);
int dictionary_parse(dictionary_t *d, char *key_value);
void dictionary_print(dictionary_t *d);
void dictionary_destroy(dictionary_t *d);

#endif
