#ifndef __PRESENTATION_H__
#define __PRESENTATION_H__

#include <stdbool.h>
#include "organization.h"

// Definition of a presentation structure
typedef struct {
    char* presentationTitle;
    char* presentationTopic;
    tOrganization organization; 
    double score; 
} tPresentation;


// Definition of a queue node
typedef struct _tPresentationQueueNode {
    tPresentation e;
    struct _tPresentationQueueNode* next;
} tPresentationQueueNode;


// Definition of a queue of presentations
typedef struct {
    tPresentationQueueNode* first;
    tPresentationQueueNode* last;
} tPresentationQueue;



// Compare two organization scores
bool organizationScore_compare(tPresentation p1, tPresentation p2);

// Duplicate a organization score
void organizationScore_duplicate(tPresentation* dst, tPresentation src);

// Initialize a presentation structure
void presentation_init(tPresentation *object, tOrganization *organization, double score, const char* presentationTitle, const char* presentationTopic);

// Compare two presentations
bool presentation_compare(tPresentation p1, tPresentation p2);

// Duplicate a presentation
void presentation_duplicate(tPresentation* dst, tPresentation src);

// Implementation of compare method between two presentations queues using iterative algorithm
bool presentationQueue_compareIterative(tPresentationQueue *q1, tPresentationQueue *q2);

// Implementation of compare method between two presentation queues using recursive algorithm
bool presentationQueue_compareRecursive(tPresentationQueue *q1, tPresentationQueue *q2);

// Compare two presentation queues
bool presentationQueue_compare(tPresentationQueue q1, tPresentationQueue q2);

// Make a copy of the queue
void presentationQueue_duplicate(tPresentationQueue* dst, tPresentationQueue src);

// Create the presentation queue
void presentationQueue_createQueue(tPresentationQueue* queue);

// Enqueue a new match to the match queue
tError presentationQueue_enqueue(tPresentationQueue* queue, tPresentation presentation);

// Dequeue a presentation from the presentation queue
void presentationQueue_dequeue(tPresentationQueue* queue);

// Return the first element from the queue
tPresentation* presentationQueue_head(tPresentationQueue queue);

// Check if the queue is empty
bool presentationQueue_empty(tPresentationQueue queue);

// Remove all elements of the queue
void presentationQueue_free(tPresentationQueue* queue);

// Get the average score for an organization
double presentationQueue_getOrganizationScoreRecursive(tPresentationQueue *queue, tOrganization *organization);

// Get a queue with all the presentations for an organization
tError presentationQueue_getOrganizationPresentationsRecursive(tPresentationQueue *queue, tOrganization *organization, tPresentationQueue* presentations);

#endif // __PRESENTATION_H__