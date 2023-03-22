
#include "elephant.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Elephant *new_elephant(const char name[], enum type which_type,
                       unsigned int id, unsigned short weight,
                       float trunk_length) {
    Elephant *elephant = malloc(sizeof(Elephant));
    if (name == NULL) {
        return NULL;
    }

    elephant->name = malloc(strlen(name) + 1);
    strcpy(elephant->name, name);
    elephant->elephant_type = which_type;
    elephant->id = id;
    elephant->weight = weight;
    elephant->trunk_length = trunk_length;

    return elephant;
}

unsigned short get_type(const Elephant *const el_ptr,
                        enum type *const type_ptr) {
    if (el_ptr == NULL || type_ptr == NULL) {
        return 0;
    }

    *type_ptr = el_ptr->elephant_type;
    return 1;
}

void print_elephant(const Elephant *const el_ptr) {
    if (el_ptr == NULL || el_ptr->name == NULL) {
        return;
    }

    printf("%s ", el_ptr->name);
    if (el_ptr->elephant_type == AFRICAN) {
        printf("AFRICAN ");
    } else {
        printf("ASIAN ");
    }
    printf("%d %d %g\n", el_ptr->id, el_ptr->weight, el_ptr->trunk_length);
}

short compare(const Elephant *const el_ptr1,
              const Elephant *const el_ptr2) {
    if (el_ptr1 == NULL || el_ptr2 == NULL || el_ptr1->name == NULL ||
        el_ptr2->name == NULL) {
        return -1;
    }

    if (!(strcmp(el_ptr1->name, el_ptr2->name)) &&
        el_ptr1->elephant_type == el_ptr2->elephant_type &&
        el_ptr1->id == el_ptr2->id && el_ptr1->weight == el_ptr2->weight &&
        el_ptr1->trunk_length == el_ptr2->trunk_length) {
        return 1;
    } else {
        return 0;
    }
}

unsigned short change_name(Elephant *const el_ptr, const char new_name[]) {
    char *elephant_name;

    /* Checks */
    if (new_name == NULL || el_ptr == NULL) {
        return 0;
    }

    elephant_name = malloc(strlen(new_name) + 1);
    strcpy(elephant_name, new_name);
    /* Assign value */
    free(el_ptr->name);
    el_ptr->name = elephant_name;
    return 1;
}

unsigned short copy(Elephant *const el_ptr1,
                    const Elephant *const el_ptr2) {
    /* Variables */
    if (el_ptr1 == NULL || el_ptr2 == NULL || el_ptr1->name == NULL ||
        el_ptr2 == NULL) {
        return 0;
    }
    change_name(el_ptr1, el_ptr2->name);
    el_ptr1->id = el_ptr2->id;
    el_ptr1->elephant_type = el_ptr2->elephant_type;
    el_ptr1->weight = el_ptr2->weight;
    el_ptr1->trunk_length = el_ptr2->trunk_length;
    return 1;
}

const char *get_name(const Elephant *const el_ptr) {
    char *elephant_name;

    if (!el_ptr) {
        return NULL;
    }

    elephant_name = malloc(strlen(el_ptr->name) + 1);
    strcpy(elephant_name, el_ptr->name);
    return elephant_name;
}