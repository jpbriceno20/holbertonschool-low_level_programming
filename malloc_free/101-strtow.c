#include "main.h"
#include <stdlib.h>

/**
 * free_words - Frees the memory allocated for all words in the array
 * @words: The array of word strings
 * @w: The index of the word to free from
 */
static void free_words(char **words, int w)
{
	while (w > 0)
	{
		w--;
		free(words[w]);
	}
	free(words);
}

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */
static int count_words(char *str)
{
	int i = 0, words = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			words++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
		}
	}
	return (words);
}

/**
 * get_word_length - Returns the length of the next word starting at index i
 * @str: The input string
 * @start: The starting index of the word
 *
 * Return: The length of the word
 */
static int get_word_length(char *str, int start)
{
	int length = 0;

	while (str[start] != '\0' && str[start] != ' ')
	{
		start++;
		length++;
	}
	return (length);
}

/**
 * copy_word - Copies a word of given length from str into a new string
 * @str: The original input string
 * @start: The starting index of the word in str
 * @length: The length of the word
 *
 * Return: Pointer to the newly allocated word (null-terminated), or NULL on fail
 */
static char *copy_word(char *str, int start, int length)
{
	char *word;
	int i;

	word = malloc((length + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		word[i] = str[start + i];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into an array of words, separated by spaces
 * @str: The input string
 *
 * Return: Pointer to an array of word strings, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int total_words, w = 0, i = 0, length, start;

	if (str == NULL || *str == '\0')
		return (NULL);

	total_words = count_words(str);
	if (total_words == 0)
		return (NULL);

	words = malloc((total_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (w < total_words)
	{
		while (str[i] == ' ')
			i++;
		start = i;
		length = get_word_length(str, i);
		i += length;

		words[w] = copy_word(str, start, length);
		if (words[w] == NULL)
		{
			free_words(words, w);
			return (NULL);
		}
		w++;
	}
	words[w] = NULL;

	return (words);
}
