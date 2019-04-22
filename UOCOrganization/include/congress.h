#ifndef __CONGRESS_H__
#define __CONGRESS_H__

#include "guest.h"
#include "organization.h"
#include "presentation.h"

// Definition of a congress
typedef struct {
	char* name;
    tOrganizationTable* organizations;
    tPresentationQueue presentations;
} tCongress;

// Initialize the congress
void congress_init(tCongress* object, char* name);

// Remove all data for a congress
void congress_free(tCongress* object);

// Register a new organization to the congress
tError congress_registerOrganization(tCongress* object, tOrganization* organization);

// Remove an organization from the congress
tError congress_removeOrganization(tCongress* object, tOrganization* organization);

// Find an organization
tOrganization* congress_findOrganization(tCongress* object, const char* organizationName);

// Get guests all gests of a congress
tError congress_getGuests(tCongress* object, tGuestTable* guests);

// Add a new presentation
tError congress_addPresentation(tCongress* object, const char* organization_name, double score, const char* presentationTitle, const char* presentationTopic);

// Get if an organization wins on a topic. Wins means best score on a topic
int congress_getOrganizationWins(tCongress* object, const char* organization_name, const char* topic);

// Get the average score for an organization
double congress_getOrganizationScore(tCongress* object, const char* organization_name);

// Get a queue with all the presentations for an organization
tError congress_getOrganizationPresentations(tCongress* object, const char* organization_name, tPresentationQueue* presentations);

#endif // __CONGRESS_H__