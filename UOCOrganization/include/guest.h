#ifndef __GUEST__H__
#define __GUEST__H__

#include <stdbool.h>
#include "error.h"

// Definition of a guest
typedef struct {
    char* username;
    char* name;    
    char* mail;
} tGuest;

// Table of guests
typedef struct {
    unsigned int size;
    
    // Using static memory, the elements is an array of a fixed length MAX_ELEMENTS. That means that we are using the same amount of memory when the table is empty and when is full. We cannot add more elements than MAX_ELEMENTS.
    // tGuest elemets[MAX_ELEMENTS];
    
    // Using dynamic memory, the elements is a pointer to a region of memory. Initially, we have no memory (NULL), and we need to allocate memory when we want to add elements. We can add as many elements as we want, the only limit is the total amount of memory of our computer.
    tGuest* elements;
    
} tGuestTable;

// Initialize the guest structure
tError guest_init(tGuest* object, const char* username, const char* name, const char* mail);

// Remove the memory used by guest structure
void guest_free(tGuest* object);

// Compare two guests
bool guest_equals(tGuest* guest1, tGuest* guest2);

// Compare two Table of guests
bool guestTable_equals(tGuestTable* guestTable1, tGuestTable* guestTable2);

// Copy the data of a guest to another guest
tError guest_cpy(tGuest* dest, tGuest* src);


// Initialize the Table of guests
void guestTable_init(tGuestTable* table);

// Remove the memory used by guestTable structure
void guestTable_free(tGuestTable* object);

// Add a new guest to the table
tError guestTable_add(tGuestTable* table, tGuest* guest);

// Remove a guest from the table
tError guestTable_remove(tGuestTable* table, tGuest* guest);

// Get guest by username
tGuest* guestTable_find(tGuestTable* table, const char* username);

// Get the size of the table
unsigned int guestTable_size(tGuestTable* table);


// Check the format of an email
bool check_mail(const char* mail);

#endif // __guest__H__