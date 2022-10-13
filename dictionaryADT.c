#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#define INITIAL_SIZE 1024
#define GROWTH_FACTOR 2
#define MAX_LOAD_FACTOR 1
#define MULTIPLIER 97
struct element
{
    struct element *next;
    char *key;
    char *value;
};
struct dict
{
    int size;
    int n;
    struct element **table;
};
static unsigned long hash_function(const char *s)
{
    unsigned const char *us;
    unsigned long hash;
    hash = 0;
    for (us = (unsigned const char *)s; *us; us++)
    {
        hash = hash * MULTIPLIER + *us;
    }
    return hash;
}
struct dict *dictCreate(int size)
{
    struct dict *dictionary = NULL;
    dictionary = (struct dict *)malloc(sizeof(struct dict));
    int i;
    dictionary->size = size;
    dictionary->n = 0;
    dictionary->table = malloc(sizeof(struct element *) * dictionary->size);
    for (i = 0; i < dictionary->size; i++)
        dictionary->table[i] = 0;
    return dictionary;
}
void insertPair(struct dict *dictionary, const char *key, const char *value)
{
    struct element *element;
    unsigned long hash;
    element = malloc(sizeof(*element));
    element->key = strdup(key);
    element->value = strdup(value);
    hash = hash_function(key) % dictionary->size;
    element->next = dictionary->table[hash];
    dictionary->table[hash] = element;
    dictionary->n++;
}
void search(struct dict *dictionary, const char *key)
{
    struct element *element;
    element = dictionary->table[hash_function(key) % dictionary->size];
    if (!strcmp(element->key, key))
        printf("The Value for Key: %s, is: %s \n", element->key, element->value);
}
void delete (struct dict *dictionary, const char *key)
{
    struct element **prev;
    struct element *e;
    for (prev = &(dictionary->table[hash_function(key) % dictionary->size]);
         *prev != 0; prev = &((*prev)->next))
    {
        if (!strcmp((*prev)->key, key))
        {
            e = *(prev);
            *prev = e->next;
            free(e->key);
            free(e->value);
            free(e);
            return;
        }
    }
}
void traverseAllValues(struct dict *dictionary)
{
    struct element *e;
    int i;
    for (i = 0; i < INITIAL_SIZE; i++)
    {
        if (dictionary->table[i] != 0)
        {
            e = dictionary->table[i];
            printf("Element is: %s , Key is: %s\n", e->key, e->value);
        }
    }
}
int main()
{
    struct dict *dictionary = dictCreate(INITIAL_SIZE);
    insertPair(dictionary, "Hello", "World");
    insertPair(dictionary, "Hash", "Table");
    traverseAllValues(dictionary);
    search(dictionary, "Hash");
    delete (dictionary, "Hash");
    traverseAllValues(dictionary);
}
