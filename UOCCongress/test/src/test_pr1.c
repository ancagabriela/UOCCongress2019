#include <assert.h>
#include <string.h>
#include "test_pr1.h"
#include "guest.h"
#include "organization.h"
#include "congress.h"

// Run all tests for PR1
bool run_pr1(tTestSuite* test_suite) {
    bool ok = true;
    tTestSection* section = NULL;
    
    assert(test_suite != NULL);
    
    testSuite_addSection(test_suite, "PR1", "Tests for PR1 exercices");
    
    section = testSuite_getSection(test_suite, "PR1");
    assert(section != NULL);
        
    ok = run_pr1_ex1(section) && ok;
    ok = run_pr1_ex2(section) && ok;
    ok = run_pr1_ex3(section) && ok;
    ok = run_pr1_ex4(section) && ok;
    
    return ok;
}

// Run tests for PR1 exercice 1
bool run_pr1_ex1(tTestSection* test_section) {    
    bool passed = true, failed = false;
    tGuest *gAux, g1, g2, g3, g1_2;
    tGuestTable guests;
    tError err;
    
    // TEST 1: Initialize the table of guest
    failed = false;
    start_test(test_section, "PR1_EX1_1", "Initialize the table of guests");
    guestTable_init(&guests);
    
    if(guestTable_size(&guests) != 0) {        
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR1_EX1_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_1", true);
    }
    
    // TEST 2: Initialize a guest
    failed = false;
    start_test(test_section, "PR1_EX1_2", "Initialize a guest");
    
    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g1_2, "g1", "name of g1", "g1@uoc.edu");
    
    if(!guest_equals(&g1, &g1_2)) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR1_EX1_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_2", true);
    }
    
    // TEST 3: Add a new guest
    failed = false;
    start_test(test_section, "PR1_EX1_3", "Add a new guest");
        
    err = guestTable_add(&guests, &g1);
    if(err != OK) {    
        failed = true;
    }
    if(guestTable_size(&guests) != 1) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g1");
    if(gAux == NULL) {
        failed = true;
    } else if(!guest_equals(gAux, &g1)) {                
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR1_EX1_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_3", true);
    }
        
    // TEST 4: Add more guests
    failed = false;
    start_test(test_section, "PR1_EX1_4", "Add more guests");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    
    err = guestTable_add(&guests, &g2);
    if(err != OK) {    
        failed = true;
    }
    if(guestTable_size(&guests) != 2) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g2");
    if(gAux == NULL) {
        failed = true;
    }
    if(!guest_equals(gAux, &g2)) {        
        failed = true;
    }
    
    err = guestTable_add(&guests, &g3);
    if(err != OK) {    
        failed = true;
    }
    if(guestTable_size(&guests) != 3) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g3");
    if(gAux == NULL) {
        failed = true;
    } else if(!guest_equals(gAux, &g3)) {
        failed = true;
    }
    
    if(failed) {
        end_test(test_section, "PR1_EX1_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_4", true);
    }
    
    // TEST 5: Remove a guest
    failed = false;
    start_test(test_section, "PR1_EX1_5", "Remove a guest");
    
    gAux = guestTable_find(&guests, "g2");
    if(gAux == NULL) {
        failed = true;
    } 
    err = guestTable_remove(&guests, &g2);
    if(err != OK) {    
        failed = true;
    }
    if(guestTable_size(&guests) != 2) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g2");
    if(gAux != NULL) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g1");
    if(gAux == NULL) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g3");
    if(gAux == NULL) {
        failed = true;
    }

    if(failed) {
        end_test(test_section, "PR1_EX1_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_5", true);
    }

    // TEST 6: Remove a non existing guest
    failed = false;
    start_test(test_section, "PR1_EX1_6", "Remove a non existing guest");
    
    err = guestTable_remove(&guests, &g2);
    if(err != ERR_NOT_FOUND) {    
        failed = true;
    }
    if(guestTable_size(&guests) != 2) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g2");
    if(gAux != NULL) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g1");
    if(gAux == NULL) {
        failed = true;
    }
    gAux = guestTable_find(&guests, "g3");
    if(gAux == NULL) {
        failed = true;
    } 
    
    if(failed) {
        end_test(test_section, "PR1_EX1_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_6", true);
    }
    
    // TEST 7: Register a guest with invalid email
    failed = false;
    start_test(test_section, "PR1_EX1_7", "Register a guest with invalid email");
        
    err = guest_init(gAux, "g1", "name of g1", "wrong.mail@");
    if(err != ERR_INVALID) {
        failed = true;
    }
        
    if(failed) {
        end_test(test_section, "PR1_EX1_7", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX1_7", true);
    }
    
    // Remove used memory
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    guest_free(&g1_2);
    
    guestTable_free(&guests);    
    
    return passed;
}

// Run tests for PR1 exercice 2
bool run_pr1_ex2(tTestSection* test_section) {
    bool passed = true, failed = false;
    tGuest g1, g2, g3;
    tGuestTable guests1, guests2, guests3;
    tOrganization orgAux, org1, org2, org1_2;
    tError err;

    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guestTable_init(&guests1);
    guestTable_add(&guests1, &g1);
    guestTable_add(&guests1, &g2);
    guestTable_add(&guests1, &g3);
    guestTable_init(&guests2);
    guestTable_init(&guests3);
    guestTable_add(&guests3, &g1);
    guestTable_add(&guests3, &g2);
    guestTable_add(&guests3, &g3);

    // TEST 1: Initialize an organizations
    failed = false;
    start_test(test_section, "PR1_EX2_1", "Initialize an organization");
    
    organization_init(&org1, "org1", &guests1);
    if(org1.guests == &guests1) {
        organization_init(&org2, "org2", &guests2);
        if(org2.guests == &guests2) {
            organization_init(&org1_2, "org1", &guests3);
            if(org1_2.guests != &guests3)
                failed = true;
        }
        else
            failed = true;
    }
    else
        failed = true;
    
    if(failed) {
        end_test(test_section, "PR1_EX2_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX2_1", true);
    }

    // TEST 2: Get guests from organization
    failed = false;
    start_test(test_section, "PR1_EX2_2", "Get guests from organization");

    if(organization_getGuests(&org1) != &guests1)
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX2_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX2_2", true);
    }

    // TEST 3: Compare organizations
    failed = false;
    start_test(test_section, "PR1_EX2_3", "Compare organizations");
    
    if(organization_equals(&org1, &org1)) {
        if(!organization_equals(&org1, &org2))
        {
            if(!organization_equals(&org1, &org1_2))
                failed = true;
        }
        else
            failed = true;
    }
    else
        failed = true;
    
    if(failed) {
        end_test(test_section, "PR1_EX2_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX2_3", true);
    }

    // TEST 4: Copy an organization
    failed = false;
    start_test(test_section, "PR1_EX2_4", "Copy an organization");

    err = organization_cpy(&orgAux, &org1);
    if(err != OK)
        failed = true;

    if(!organization_equals(&org1, &orgAux))
        failed = true;
        
    if(!organization_equals(&orgAux, &org1_2))
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX2_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX2_4", true);
    }

    // Remove used memory
    organization_free(&org1);
    organization_free(&org2);
    organization_free(&org1_2);
    organization_free(&orgAux);
    guestTable_free(&guests1);
    guestTable_free(&guests2);
    guestTable_free(&guests3);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    
    return passed;
}

// Run tests for PR1 exercice 3
bool run_pr1_ex3(tTestSection* test_section) {
    bool passed = true, failed = false;
    tOrganizationTable tt;
    tGuest g1, g2, g3;
    tGuestTable guests1, guests2;
    tOrganization org1, org2;
    tError err;

    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guestTable_init(&guests1);
    guestTable_add(&guests1, &g1);
    guestTable_add(&guests1, &g2);
    guestTable_init(&guests2);
    guestTable_add(&guests2, &g3);    
    organization_init(&org1, "org1", &guests1);
    organization_init(&org2, "org2", &guests2);
        
    // TEST 1: Initialize an organization table
    failed = false;
    start_test(test_section, "PR1_EX3_1", "Initialize an organization table");

    organizationTable_init(&tt);
    if ((tt.elements != NULL) || (tt.size != 0))
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_1", true);
    }
    
    // TEST 2: Add an organization to the table
    failed = false;
    start_test(test_section, "PR1_EX3_2", "Add an organization to the table");

    err = organizationTable_add(&tt, &org1);
    if ((err == OK) && (tt.size == 1))
    {
        if (!organization_equals(&tt.elements[0], &org1))
            failed = true;
    }
    else
        failed = true;
        
    err = organizationTable_add(&tt, &org2);
    if ((err == OK) && (tt.size == 2))
    {
        if (!organization_equals(&tt.elements[1], &org2))
            failed = true;
    }
    else
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_2", true);
    }
    
    // TEST 3: Get table organization size
    failed = false;
    start_test(test_section, "PR1_EX3_3", "Get table organization size");

    if (organizationTable_size(&tt) != 2)
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_3", true);
    }
    
    // TEST 4: Find organization
    failed = false;
    start_test(test_section, "PR1_EX3_4", "Find organization");

    if (!organizationTable_find(&tt, "org1"))
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_4", true);
    }
    
    // TEST 5: Add duplicated organization
    failed = false;
    start_test(test_section, "PR1_EX3_5", "Add duplicated organization");

    err = organizationTable_add(&tt, &org2);
    if (err != ERR_DUPLICATED)
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_5", true);
    }
    
    // TEST 6: Remove organization
    failed = false;
    start_test(test_section, "PR1_EX3_6", "Remove organization");

    err = organizationTable_remove(&tt, &org2);
    if (err != OK)
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_6", true);
    }
    
    // TEST 7: Remove non existing organization
    failed = false;
    start_test(test_section, "PR1_EX3_7", "Remove non existing organization");

    err = organizationTable_remove(&tt, &org2);
    if (err != ERR_NOT_FOUND)
        failed = true;

    if(failed) {
        end_test(test_section, "PR1_EX3_7", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX3_7", true);
    }
        
    // Remove used memory
    organization_free(&org1);
    organization_free(&org2);
    guestTable_free(&guests1);
    guestTable_free(&guests2);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);    
    organizationTable_free(&tt);
    
    return passed;
}

// Run tests for PR1 exercice 4
bool run_pr1_ex4(tTestSection* test_section) {
    bool passed = true, failed = false;
    tCongress cong1;
    tGuest g1, g2, g3, g4;
    tGuestTable guests1, guests2, guests3, guestsAux1, guestsAux2;
    tOrganization org1, org2, org3, *orgAux;
    tError err;

    guest_init(&g1, "g1", "name of g1", "g1@uoc.edu");
    guest_init(&g2, "g2", "name of g2", "g2@uoc.edu");
    guest_init(&g3, "g3", "name of g3", "g3@uoc.edu");
    guest_init(&g4, "g4", "name of g4", "g4@uoc.edu");
    guestTable_init(&guests1);
    guestTable_add(&guests1, &g1);
    guestTable_add(&guests1, &g2);
    guestTable_init(&guests2);
    guestTable_add(&guests2, &g3);
    guestTable_init(&guests3);
    guestTable_add(&guests3, &g1);
    guestTable_add(&guests3, &g3);
    guestTable_add(&guests3, &g4);
    organization_init(&org1, "org1", &guests1);
    organization_init(&org2, "org2", &guests2);
    organization_init(&org3, "org3", &guests3);

    // TEST 1: Initialize congress
    failed = false;
    start_test(test_section, "PR1_EX4_1", "Initialize congress");
    
    congress_init(&cong1, "cong1");
    
    if ((cong1.name == NULL) || (strcmp(cong1.name, "cong1") != 0) || (organizationTable_size(cong1.organizations) != 0))
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_1", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_1", true);
    }
    
    // TEST 2: Add organization to congress
    failed = false;
    start_test(test_section, "PR1_EX4_2", "Add organization to congress");
    
    err = congress_registerOrganization(&cong1, &org1);
    if (err != OK)
        failed = true;
        
    err = congress_registerOrganization(&cong1, &org2);
    if (err != OK)
        failed = true;
        
    if ((cong1.name != NULL) && (strcmp(cong1.name, "cong1") == 0)){
        if ((organizationTable_size(cong1.organizations) != 2) || 
            (strcmp(cong1.organizations->elements[0].name, "org1") != 0) || 
            (strcmp(cong1.organizations->elements[1].name, "org2") != 0)){
                failed = true;
            }
    }
    else
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_2", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_2", true);
    }
    
    // TEST 3: Add duplicated organization to congress
    failed = false;
    start_test(test_section, "PR1_EX4_3", "Add duplicated organization to congress");
    
    err = congress_registerOrganization(&cong1, &org2);
    if (err != ERR_DUPLICATED)
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_3", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_3", true);
    }
    
    // TEST 4: Find organization
    failed = false;
    start_test(test_section, "PR1_EX4_4", "Find organization");
    
    orgAux = congress_findOrganization(&cong1, "org1");
    if ((orgAux == NULL) || (strcmp(orgAux->name, "org1") != 0))
        failed = true;
    
    orgAux = congress_findOrganization(&cong1, "org2");
    if ((orgAux == NULL) || (strcmp(orgAux->name, "org2") != 0))
        failed = true;
        
    orgAux = congress_findOrganization(&cong1, "org3");
    if (orgAux != NULL)
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_4", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_4", true);
    }
    
    // TEST 5: Remove organization to congress
    failed = false;
    start_test(test_section, "PR1_EX4_5", "Remove organization to congress");
    
    err = congress_removeOrganization(&cong1, &org1);
    if ((err != OK) || (organizationTable_size(cong1.organizations) != 1))
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_5", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_5", true);
    }
    
    // TEST 6: Remove non existing organization to congress
    failed = false;
    start_test(test_section, "PR1_EX4_6", "Remove non existing organization to congress");
    
    err = congress_removeOrganization(&cong1, &org1);
    if ((err != ERR_NOT_FOUND) || (organizationTable_size(cong1.organizations) != 1))
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_6", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_6", true);
    }
    
    // TEST 7: Get all guests from congress
    failed = false;
    start_test(test_section, "PR1_EX4_7", "Get all guests from congress");
    
    guestTable_init(&guestsAux2);
    guestTable_add(&guestsAux2, &g1);
    guestTable_add(&guestsAux2, &g2);
    guestTable_add(&guestsAux2, &g3);
    
    err = congress_registerOrganization(&cong1, &org1);
    if (err == OK){
        guestTable_init(&guestsAux1);
        err = congress_getGuests(&cong1, &guestsAux1);
        if (err == OK) {
            if (!guestTable_equals(&guestsAux1, &guestsAux2))
                failed = true;
        }
        else
            failed = true;
    }
    else
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_7", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_7", true);
    }
    
    
    // TEST 8: Get all guests from congress (with duplicates)
    failed = false;
    start_test(test_section, "PR1_EX4_8", "Get all guests from congress (with duplicates)");
    
    err = congress_registerOrganization(&cong1, &org3);
    if (err == OK){
        guestTable_add(&guestsAux2, &g4);
        guestTable_init(&guestsAux1);
        err = congress_getGuests(&cong1, &guestsAux1);
        if (err == OK) {
            if (!guestTable_equals(&guestsAux1, &guestsAux2))
                failed = true;
        }
        else
            failed = true;
    }
    else
        failed = true;
        
    if(failed) {
        end_test(test_section, "PR1_EX4_8", false);
        passed = false;
    } else {
        end_test(test_section, "PR1_EX4_8", true);
    }
    
    // Remove used memory
    organization_free(&org1);
    organization_free(&org2);
    organization_free(&org3);
    guestTable_free(&guests1);
    guestTable_free(&guests2);
    guestTable_free(&guests3);
    guestTable_free(&guestsAux2);
    guest_free(&g1);
    guest_free(&g2);
    guest_free(&g3);
    guest_free(&g4);
    congress_free(&cong1);
    
    return passed;
}
