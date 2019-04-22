#include <assert.h>
#include <string.h>
#include "test_pr2.h"
#include "presentation.h"
#include "guest.h"
#include "organization.h"
#include "congress.h"

// Run all tests for PR2
bool run_pr2(tTestSuite* test_suite) {
    bool ok = true;
    tTestSection* section = NULL;
    
    assert(test_suite != NULL);
    
    testSuite_addSection(test_suite, "PR2", "Tests for PR2 exercices");
    
    section = testSuite_getSection(test_suite, "PR2");
    assert(section != NULL);
        
    ok = run_pr2_ex1(section) && ok;
    ok = run_pr2_ex2(section) && ok;
    ok = run_pr2_ex3(section) && ok;
        
    return ok;
}

// Run tests for PR2 exercice 1
bool run_pr2_ex1(tTestSection* test_section) {    
    bool passed = true, failed = false;    
    tError err;
    
    tGuest  g1, g2, g3;
    tGuestTable guests;
    tPresentationQueue presentations;
    tPresentation presentation1, presentation2, presentation3;
    tOrganization organization1, organization2, organization3;
   // tTeam team1, team2, team3, team4;
    tCongress congress;
    bool queue_created = false;
    
    // Create test data
    
    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guestTable_init(&guests);
    guestTable_add(&guests, &g1);
    guestTable_add(&guests, &g2);
    guestTable_add(&guests, &g3);   
 
    organization_init(&organization1, "org1", &guests);
    organization_init(&organization2, "org2", &guests);        
    organization_init(&organization3, "org3", &guests);  
     
    presentation_init(&presentation1, &organization1, 1.0,"titulo1","tema1");
    presentation_init(&presentation2, &organization2, 1.0,"titulo2","tema2");
    presentation_init(&presentation3, &organization3, 1.0,"titulo2","tema2"); 
  
    congress_init(&congress,"congress");
    
    congress_registerOrganization(&congress, &organization1);
    congress_registerOrganization(&congress, &organization2);
    congress_registerOrganization(&congress, &organization3);  
    
    // TEST 1: Initialize the queue of presentations
    failed = false;
    start_test(test_section, "PR2_EX1_1", "Initialize the queue of presentations");
    
    presentationQueue_createQueue(&presentations);
    
    if(presentations.first != NULL || presentations.last != NULL) {
        failed = true;
    } else {
        queue_created = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX1_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_1", true);
    }
        
     
    // TEST 2: Test empty method with empty queue
    failed = false;
    start_test(test_section, "PR2_EX1_2", "Test empty method with empty queue");
    
    if(presentations.first != NULL || presentations.last != NULL) {
        failed = true;
    }
    
    if(!presentationQueue_empty(presentations)) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX1_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_2", true);
    }
    
    // TEST 3: Enqueue a new presentation
    failed = false;
    start_test(test_section, "PR2_EX1_3", "Enqueue a new presentation");
    
    err=presentationQueue_enqueue(&presentations, presentation1);
    
    if(err!=OK) {
        failed = true;
    } else
    {
        // Else added to exectue Test with not implemented functions
        if(presentations.first == NULL || presentations.last == NULL) {
            failed = true;
        }

        if(presentations.first != presentations.last) {
            failed = true;
        }
        
        if(!presentation_compare(presentation1, presentations.first->e)) {
            failed = true;
        }
    }    
    
    if(failed) {
        end_test(test_section, "PR2_EX1_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_3", true);
    }
    
    // TEST 4: Enqueue multiple presentations
    failed = false;
    start_test(test_section, "PR2_EX1_4", "Enqueue multiple presentations");
    
    err=presentationQueue_enqueue(&presentations, presentation2);
    
    if(err!=OK) {
        failed = true;
    } else
    {
        // Else added to exectue Test with not implemented functions
        if(presentations.first == NULL || presentations.last == NULL) {
            failed = true;
        }

        if(presentations.first == presentations.last) {
            failed = true;
        }
        
        if(!presentation_compare(presentation1, presentations.first->e)) {
            failed = true;
        }
        if(!presentation_compare(presentation2, presentations.last->e)) {
            failed = true;
        }
    }

    err=presentationQueue_enqueue(&presentations, presentation3);
    
    if(err!=OK) {
        failed = true;
    } else
    {
        // Else added to exectue Test with not implemented functions
        if(presentations.first == NULL || presentations.last == NULL) {
            failed = true;
        }

        if(presentations.first == presentations.last) {
            failed = true;
        }
        
        if(!presentation_compare(presentation1, presentations.first->e)) {
            failed = true;
        }
        if(!presentation_compare(presentation3, presentations.last->e)) {
            failed = true;
        }
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX1_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_4", true);
    }
    
    // TEST 5: Add a presentation with invalid organization
    failed = false;
    start_test(test_section, "PR2_EX1_5", "Add a presentation with invalid organization");
    
    if(!queue_created) {
        failed = true;
    }

    err = congress_addPresentation(&congress, "non_existing_organization", 1, "titulo1", "tema1");
    if (err != ERR_INVALID_ORGANIZATION) {
        failed = true;
    }
    
    
    err = congress_addPresentation(&congress, "other_non_existing_organization", 1, "titulo2", "tema2");
    if (err != ERR_INVALID_ORGANIZATION) {
        failed = true;
    }

    if(!presentationQueue_empty(congress.presentations)) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX1_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_5", true);
    }    

    // TEST 6: Add a presentation with valid organizations
    failed = false;
    start_test(test_section, "PR2_EX1_6", "Add a presentation with valid organizations");
    
    err = congress_addPresentation(&congress, "org1", 1.0, "titulo2", "tema2");
    if (err != OK) {
        failed = true;
    }
        
    if(failed) {
        end_test(test_section, "PR2_EX1_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX1_6", true);
    }        
        
    // Remove used data
    presentationQueue_free(&presentations);
    congress_free(&congress);    
 
    organization_free(&organization1);
    organization_free(&organization2);
    organization_free(&organization3);   
    guestTable_free(&guests);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    
    return passed;
}

// Run tests for PR2 exercice 2
bool run_pr2_ex2(tTestSection* test_section) {    
    bool passed = true, failed = false;    
    tError err;   

    tGuest  g1, g2, g3;
    tGuestTable guests;
    tOrganization organization1, organization2, organization3;
    tCongress congress;
    tPresentation* presentation;
    tPresentationQueue tmpQueue;
    
    bool queue_created = false;
    
    // Create test data     
    
    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guestTable_init(&guests);
    guestTable_add(&guests, &g1);
    guestTable_add(&guests, &g2);
    guestTable_add(&guests, &g3);   
 
    organization_init(&organization1, "org1", &guests);
    organization_init(&organization2, "org2", &guests);        
    organization_init(&organization3, "org3", &guests);  
    
    congress_init(&congress,"congress");
    
    congress_registerOrganization(&congress, &organization1);
    congress_registerOrganization(&congress, &organization2);
    congress_registerOrganization(&congress, &organization3);  
    
    
    err = congress_addPresentation(&congress, "org1", 1.0, "titulo1", "tema1");   
    if (err != OK) {
        failed = true;
    }
    err = congress_addPresentation(&congress, "org2", 2.0, "titulo2", "tema2");   
    if (err != OK) {
        failed = true;
    }
    err = congress_addPresentation(&congress, "org3", 3.0, "titulo3", "tema4");   
    if (err != OK) {
        failed = true;
    }
    err = congress_addPresentation(&congress, "org3", 4.0, "titulo4", "tema4");   
    if (err != OK) {
        failed = true;
    }
    

    // TEST 1: Request the head of an empty queue
    failed = false;
    start_test(test_section, "PR2_EX2_1", "Request the head of an empty queue");
    
    presentationQueue_createQueue(&tmpQueue);
    
    if(tmpQueue.first == NULL && tmpQueue.last == NULL) {
        queue_created = true;
    }
    
    presentation = presentationQueue_head(tmpQueue);
    
    if(presentation != NULL) {
        failed = true;
    }    
    
    if(failed) {
        end_test(test_section, "PR2_EX2_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_1", true);
    }
    
    // TEST 2: Get the head from a queue with multiple elements
    failed = false;
    start_test(test_section, "PR2_EX2_2", "Get the head from a queue with multiple elements");
    
    presentationQueue_createQueue(&tmpQueue);
    
    if ((congress.presentations.first != NULL) && (congress.presentations.last != NULL))
    {
        presentationQueue_duplicate(&tmpQueue, congress.presentations); // NOW 4 elements
            
        presentation = presentationQueue_head(tmpQueue);
        
        if(queue_created) {
            if (presentation == NULL) {
                failed = true;
            } else {
                if (presentation != &(tmpQueue.first->e)) {
                    failed = true;
                }
                if (strcmp(presentation->presentationTitle, "titulo1") || strcmp(presentation->presentationTopic, "tema1") || presentation->score !=1.0 || strcmp(presentation->organization.name,"org1") )      {
                    failed = true;
                }
            }
        } else {
            failed = true;
        }
    }
    else{
        // Functions are not implemented
        failed = true;
    }
        
    if(failed) {
        end_test(test_section, "PR2_EX2_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_2", true);
    }
    
    // TEST 3: Dequeue from a queue with multiple elements
    failed = false;
    start_test(test_section, "PR2_EX2_3", "Dequeue from a queue with multiple elements");
    
    presentationQueue_dequeue(&tmpQueue); // NOW 3 elements
    
    if(queue_created) {
        presentation = presentationQueue_head(tmpQueue);    
        if (presentation == NULL) {
            failed = true;
        } else {        
            if (strcmp(presentation->presentationTitle, "titulo2") || strcmp(presentation->presentationTopic, "tema2") || presentation->score !=2.0 || strcmp(presentation->organization.name,"org2") )      {
                failed = true;
            }
        }
    } else {
        failed = true;
    }
    
    presentationQueue_dequeue(&tmpQueue); // NOW 2 elements
    presentationQueue_dequeue(&tmpQueue); // NOW 1 elements
    
    if(tmpQueue.first != tmpQueue.last) {
        failed = true;
    }
    
    if(queue_created) {
        presentation = presentationQueue_head(tmpQueue); 
        if (presentation == NULL) {
            failed = true;
        } else {        
            if (strcmp(presentation->presentationTitle, "titulo4") || strcmp(presentation->presentationTopic, "tema4") || presentation->score !=4.0 || strcmp(presentation->organization.name,"org3") )      {
                failed = true;
            }
        }
    } else {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_3", true);
    }
    
    // TEST 4: Dequeue from a queue with only one element
    failed = false;
    start_test(test_section, "PR2_EX2_4", "Dequeue from a queue with only one element");
    
    if(tmpQueue.first != tmpQueue.last) {
        failed = true;
    }
    else{
        // Else added to exectue Test with not implemented functions
        presentationQueue_dequeue(&tmpQueue); // Now empty
        if(!presentationQueue_empty(tmpQueue)) {
            failed = true;
        }
        if(tmpQueue.first != NULL || tmpQueue.last != NULL) {
            failed = true;
        }
        
        presentation = presentationQueue_head(tmpQueue);    
        if (presentation != NULL) {
            failed = true;
        }
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_4", true);
    }

    // TEST 5: Dequeue from an empty queue
    failed = false;
    start_test(test_section, "PR2_EX2_5", "Dequeue from an empty queue");
    
    //presentationQueue_createQueue(&tmpQueue);    
    presentationQueue_dequeue(&tmpQueue);
    
    if(tmpQueue.first != NULL || tmpQueue.last != NULL) {
        failed = true;
    }

    if(failed) {
        end_test(test_section, "PR2_EX2_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_5", true);
    }

    // TEST 6: Get wins for a non existing organization  
    failed = false;
    start_test(test_section, "PR2_EX2_6", "Get wins for a non existing organization");
   
    if( congress_getOrganizationWins(&congress, "non_existing_organization", "tema1") != ERR_NOT_EXISTS) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_6", true);
    }
   
    // TEST 7: Get wins for an existing organization
    failed = false;
    start_test(test_section, "PR2_EX2_7", "Get wins for an existing organization");

    if( congress_getOrganizationWins(&congress, "org3", "tema4")  != 3) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_7", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_7", true);
    }

    // TEST 8: Get wins for an existing organization (with draw)
    err = congress_addPresentation(&congress, "org2", 3.0, "titulo2_1", "tema1");   
    if (err != OK) {
        failed = true;
    } else
    {
        // Else added to exectue Test with not implemented functions
        err = congress_addPresentation(&congress, "org3", 3.0, "titulo3_1", "tema1");   
        if (err != OK) {
            failed = true;
        }
    }

    failed = false;
    start_test(test_section, "PR2_EX2_8", "Get wins for an existing organization (with draw)");
    
    if(congress_getOrganizationWins(&congress, "org2", "tema1") != 1) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_8", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_8", true);
    }
    
    // TEST 9: Get wins for a non existing topic
    failed = false;
    start_test(test_section, "PR2_EX2_9", "Get wins for a non existing topic");
   
    if( congress_getOrganizationWins(&congress, "org1", "non_existing_organization") != ERR_NOT_EXISTS) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX2_9", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX2_9", true);
    }

    // Remove used data    
    presentationQueue_free(&tmpQueue);
    congress_free(&congress);
    
    organization_free(&organization1);
    organization_free(&organization2);
    organization_free(&organization3);   
    guestTable_free(&guests);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    
    return passed;
}

// Run tests for PR2 exercice 3
bool run_pr2_ex3(tTestSection* test_section) {    
    bool passed = true, failed = false;    
    tError err;  
    tPresentationQueue queuePresentations, presentationsOrg;
    tGuest  g1, g2, g3;
    tGuestTable guests;
    tOrganization organization1, organization2, organization3;
    tCongress congress;
    double score;
    
    // Create test data
    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guestTable_init(&guests);
    guestTable_add(&guests, &g1);
    guestTable_add(&guests, &g2);
    guestTable_add(&guests, &g3);   
 
    organization_init(&organization1, "org1", &guests);
    organization_init(&organization2, "org2", &guests);        
    organization_init(&organization3, "org3", &guests);   
  
    congress_init(&congress,"congress");
    
    congress_registerOrganization(&congress, &organization1);
    congress_registerOrganization(&congress, &organization2);
    congress_registerOrganization(&congress, &organization3);         
    
    congress_addPresentation(&congress, "org1", 1.0, "titulo1", "tema1");   
    congress_addPresentation(&congress, "org2", 2.0, "titulo2", "tema2");   
    congress_addPresentation(&congress, "org2", 3.0, "titulo3", "tema3");           
        
    presentationQueue_createQueue(&queuePresentations);        

    presentationQueue_duplicate(&queuePresentations, congress.presentations);
    
    // TEST 1: Get organization score for an empty list of presentations
    failed = false;
    start_test(test_section, "PR2_EX3_1", "Get organization score for an empty list of presentations");
    
    // Get the total score for a team
    score = congress_getOrganizationScore(&congress,organization3.name);

    if (score != 0) {
        failed = true;
    }

    if(failed) {
        end_test(test_section, "PR2_EX3_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_1", true);
    }
    
    // TEST 2: Get presentations of an organization for an empty list of presentations
    failed = false;
    start_test(test_section, "PR2_EX3_2", "Get presentations of an organization for an empty list of presentations");
    presentationQueue_createQueue(&presentationsOrg);
    // Get a queue with all the presentations of an organization
    err = presentationQueue_getOrganizationPresentationsRecursive(&queuePresentations, &organization3, &presentationsOrg);

    if (err != OK) {
        failed = true;
    } 
    else{
        // Else added to exectue Test with not implemented functions
        if (!presentationQueue_empty(presentationsOrg)) {
            failed = true;
        }
    }

    if(failed) {
        end_test(test_section, "PR2_EX3_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_2", true);
    }
    
    // TEST 3: Get organization score for a non existing organization
    failed = false;
    start_test(test_section, "PR2_EX3_3", "Get organization score for a non existing organization");    
 
    if(presentationQueue_empty(congress.presentations)) {
        failed = true;
    }
    else{
        // Else added to exectue Test with not implemented functions

        // Get the total score of an organization
        score = congress_getOrganizationScore(&congress, "none_existing_organization");
        if (score != 0) {
            failed = true;
        }
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX3_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_3", true);
    }
    
    // TEST 4: Get  presentations for a non existing organization
    failed = false;
    start_test(test_section, "PR2_EX3_4", "Get presentations for a non existing organization");
    
    if(presentationQueue_empty(congress.presentations)) {
        failed = true;
    }

    // Get a queue with all the presentations of an organization
    presentationQueue_duplicate(&queuePresentations, congress.presentations);

    presentationQueue_createQueue(&presentationsOrg);
    err = congress_getOrganizationPresentations(&congress, "none_existing_organization", &presentationsOrg);
    if(err != ERR_INVALID_ORGANIZATION) {
        failed = true;
    }     
   
    if(failed) {
        end_test(test_section, "PR2_EX3_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_4", true);
    }
    
    // TEST 5: Get organization score from a valid organization
    failed = false;
    start_test(test_section, "PR2_EX3_5", "Get organization score from a valid organization");
    
    if(presentationQueue_empty(congress.presentations)) {
        failed = true;
    }
    
    // Get the total score for a valid organization
    score = congress_getOrganizationScore(&congress, "org2");
    if (score != 5) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR2_EX3_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_5", true);
    }
    
    // TEST 6: Get presentations from a valid organization
    failed = false;
    start_test(test_section, "PR2_EX3_6", "Get presentations from a valid organization");
    
    if(presentationQueue_empty(congress.presentations)) {
        failed = true;
    }

    // Get a queue with all the presentations from an organization
    presentationQueue_createQueue(&presentationsOrg);
    
    err = congress_getOrganizationPresentations(&congress, "org2", &presentationsOrg);
    if(err != OK) {
        failed = true;
    }
    else{
        // Else added to exectue Test with not implemented functions
        if(presentationQueue_empty(presentationsOrg)) {
            failed = true;
        } else {    
            if(!organization_equals(&presentationsOrg.first->e.organization, congress_findOrganization(&congress, "org2"))) {
                failed = true;
            }
            
            if(!organization_equals(&presentationsOrg.last->e.organization , congress_findOrganization(&congress, "org2"))) {
                failed = true;
            }          
        }
    }
   
    if(failed) {
        end_test(test_section, "PR2_EX3_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR2_EX3_6", true);
    }
    
    // Remove used data    
    presentationQueue_free(&queuePresentations);
    congress_free(&congress);
    
    organization_free(&organization1);
    organization_free(&organization2);
    organization_free(&organization3);   
    guestTable_free(&guests);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    
    return passed;
}
