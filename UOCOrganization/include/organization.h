#ifndef __ORGANIZATION_H__
#define __ORGANIZATION_H__

#include <stdbool.h>
#include "guest.h"

// Definition of an organization
typedef struct {
    char* name;
    tGuestTable* guests;    
} tOrganization;

// Table of organization
typedef struct {
    unsigned int size;
    tOrganization* elements;
} tOrganizationTable;

// Initialize the organization structure
tError organization_init(tOrganization* organization, const char* name, tGuestTable* guests);

// Remove the memory used by organization structure
void organization_free(tOrganization* object);

// Compare two organizations
bool organization_equals(tOrganization* organization1, tOrganization* organization2);

// Copy the data of a organization to another organization
tError organization_cpy(tOrganization* dest, tOrganization* src);

// Get the guests of a organization
tGuestTable* organization_getGuests(tOrganization* organization);


// Initialize the Table of organizations
void organizationTable_init(tOrganizationTable* table);

// Remove the memory used by organizationrTable structure
void organizationTable_free(tOrganizationTable* object);

// Add a new organization to the table
tError organizationTable_add(tOrganizationTable* table, tOrganization* organization);

// Delete a organization from the table
tError organizationTable_remove(tOrganizationTable* table, tOrganization* organization);

// Get organization by organization_name
tOrganization* organizationTable_find(tOrganizationTable* table, const char* organization_name);

// Get the size of a the table
unsigned int organizationTable_size(tOrganizationTable* table);

#endif // __organization_H__