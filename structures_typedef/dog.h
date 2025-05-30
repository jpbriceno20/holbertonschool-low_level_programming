#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic info
 * @name: First member, name of the dog (char *)
 * @age: Second member, age of the dog (float)
 * @owner: Third member, owner of the dog (char *)
 *
 * Description: Defines a struct with name, age, and owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
