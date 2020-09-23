#include<stdio.h>
#include "xml_header.h"
#include<stdlib.h>
#include "../Test/munit.h"
#include <libxml/parser.h>
/* 
munit testing
how to run:-
 gcc -Wall -I/usr/include/libxml2  -o hello parsing_bmd_munit.c xml_parsing.c  -lxml2 ${INCLUDE} ../Test/munit.c

*/

bmd *bmd_attributes()
{
  bmd *b = (bmd*)malloc(sizeof(bmd));
  bmd_envelop *e = (bmd_envelop*)malloc(sizeof(bmd_envelop));
  e->Sender = "756E-1D5B-4BC0-ACC4-4CEB66";
  e->Destination = "F82F-4687-433D-AA23-1966330381FE";
  e->CreationDateTime = "2020-08-12T05:18:00+0000";
  e->MessageID = "A9ECAEF2-107A-4452-9553-043B6D25386E";
  e->MessageType = "CreditReport";
  e->ReferenceID = "INV-PROFILE-889712";
  e->Signature = "63f5f61f7a79301f715433f8f3689390d1f5da4f855169023300491c00b8113c";
  b->envelop_value = e;
  b->payload = "001-01-1234";
  return b;
}

static void *bmd_setup(const MunitParameter params[], void *user_data)
{
   char *doc = "Testcases_extract_bmd/bmd.xml";
   bmd *b = (bmd*)malloc(sizeof(bmd));
   b->envelop_value = extract_envelop(doc);
   b->payload = extract_payload(doc);
   return b;
}


static MunitResult parse_test_xml_file(const MunitParameter params[], void *fixture)
{
  bmd *b = (bmd*)fixture;
  bmd *expected_b = bmd_attributes();
  munit_assert_string_equal(b->envelop_value->Sender,expected_b->envelop_value->Sender);
  munit_assert_string_equal(b->envelop_value->Destination,expected_b->envelop_value->Destination);
  munit_assert_string_equal(b->envelop_value->MessageType,expected_b->envelop_value->MessageType);
  munit_assert_string_equal(b->envelop_value->CreationDateTime,expected_b->envelop_value->CreationDateTime);
  munit_assert_string_equal(b->envelop_value->MessageID,expected_b->envelop_value->MessageID);
  munit_assert_string_equal(b->envelop_value->Signature,expected_b->envelop_value->Signature);
  munit_assert_string_equal(b->envelop_value->ReferenceID,expected_b->envelop_value->ReferenceID);
  munit_assert_string_equal(b->payload,expected_b->payload);
  return MUNIT_OK;
}

static void bmd_tear_down(void *fixture)
{
  bmd *b = (bmd*)fixture;
  free(b->envelop_value);
  free(b->payload);
  free(b);

}

bmd *bmd_attributes1()
{
  bmd *b = (bmd*)malloc(sizeof(bmd));
  bmd_envelop *e = (bmd_envelop*)malloc(sizeof(bmd_envelop));
  e->Sender = "756E2EAA";
  e->Destination = "6393F82F";
  e->CreationDateTime = "2020-08-12T05:18:00+0000";
  e->MessageID = "A9ECAEF2";
  e->MessageType = "CreditReport";
  e->ReferenceID = "INV-PROFILE-889712";
  e->Signature ="63f5f61f";
  b->envelop_value = e;
  b->payload = "001-01-1234";
  return b;
}
static void *bmd_setup1(const MunitParameter params[], void *user_data)
{
   char *doc = "Testcases_extract_bmd/bmd1.xml";
   bmd *b = (bmd*)malloc(sizeof(bmd));
   b->envelop_value = extract_envelop(doc);
   b->payload = extract_payload(doc);
   return b;
}
static MunitResult parse_test_xml_file1(const MunitParameter params[], void *fixture)
{
  bmd *b = (bmd*)fixture;
  bmd *expected_b = bmd_attributes1();
  munit_assert_string_equal(b->envelop_value->Sender,expected_b->envelop_value->Sender);
  munit_assert_string_equal(b->envelop_value->Destination,expected_b->envelop_value->Destination);
  munit_assert_string_equal(b->envelop_value->MessageType,expected_b->envelop_value->MessageType);
  munit_assert_string_equal(b->envelop_value->CreationDateTime,expected_b->envelop_value->CreationDateTime);
  munit_assert_string_equal(b->envelop_value->MessageID,expected_b->envelop_value->MessageID);
  munit_assert_string_equal(b->envelop_value->Signature,expected_b->envelop_value->Signature);
  munit_assert_string_equal(b->envelop_value->ReferenceID,expected_b->envelop_value->ReferenceID);
  munit_assert_string_equal(b->payload,expected_b->payload);
  return MUNIT_OK;
}
static void bmd_tear_down1(void *fixture)
{
  bmd *b = (bmd*)fixture;
  free(b->envelop_value);
  free(b->payload);
  free(b);

}
bmd *bmd_attributes2()
{
  bmd *b = (bmd*)malloc(sizeof(bmd));
  bmd_envelop *e = (bmd_envelop*)malloc(sizeof(bmd_envelop));
  e->Sender = "000E2EAA-1D5B-4BC0-ACC4-4C00069408DA";
  e->Destination = "0000F82F-4687-433D-AA23-1966330381FE";
  e->CreationDateTime = "2020-09-10T18:08:00+0000";
  e->MessageID = "55555EF2-107A-4452-9553-043B6D25PPPP";
  e->MessageType = "DebitCredit";
  e->ReferenceID = "8NV-PROFILE-999712";
  e->Signature = "63f5f61f7a99991f715433f8f3689390d1f5da4f855169023300491c00b8113c";
  b->envelop_value = e;
  b->payload = "333-22-4444";
  return b;
}

static void *bmd_setup2(const MunitParameter params[], void *user_data)
{
   char *doc = "Testcases_extract_bmd/bmd2.xml";
   bmd *b = (bmd*)malloc(sizeof(bmd));
   b->envelop_value = extract_envelop(doc);
   b->payload = extract_payload(doc);
   return b;
}


static MunitResult parse_test_xml_file2(const MunitParameter params[], void *fixture)
{
  bmd *b = (bmd*)fixture;
  bmd *expected_b = bmd_attributes2();
  munit_assert_string_equal(b->envelop_value->Sender,expected_b->envelop_value->Sender);
  munit_assert_string_equal(b->envelop_value->Destination,expected_b->envelop_value->Destination);
  munit_assert_string_equal(b->envelop_value->MessageType,expected_b->envelop_value->MessageType);
  munit_assert_string_equal(b->envelop_value->CreationDateTime,expected_b->envelop_value->CreationDateTime);
  munit_assert_string_equal(b->envelop_value->MessageID,expected_b->envelop_value->MessageID);
  munit_assert_string_equal(b->envelop_value->Signature,expected_b->envelop_value->Signature);
  munit_assert_string_equal(b->envelop_value->ReferenceID,expected_b->envelop_value->ReferenceID);
  munit_assert_string_equal(b->payload,expected_b->payload);
  return MUNIT_OK;
}

static void bmd_tear_down2(void *fixture)
{
  bmd *b = (bmd*)fixture;
  free(b->envelop_value);
  free(b->payload);
  free(b);

}
bmd *bmd_attributes3()
{
  bmd *b = (bmd*)malloc(sizeof(bmd));
  bmd_envelop *e = (bmd_envelop*)malloc(sizeof(bmd_envelop));
  e->Sender = "S3";
  e->Destination = "D3";
  e->CreationDateTime = "2020-08-12T05:18:00+00001";
  e->MessageID = "M3";
  e->MessageType = "Bal";
  e->ReferenceID = "R3";
  e->Signature = "S3";
  b->envelop_value = e;
  b->payload = "001-01-12347";
  return b;
}

static void *bmd_setup3(const MunitParameter params[], void *user_data)
{
   char *doc = "Testcases_extract_bmd/bmd3.xml";
   bmd *b = (bmd*)malloc(sizeof(bmd));
   b->envelop_value = extract_envelop(doc);
   b->payload = extract_payload(doc);
   return b;
}


static MunitResult parse_test_xml_file3(const MunitParameter params[], void *fixture)
{
  bmd *b = (bmd*)fixture;
  bmd *expected_b = bmd_attributes3();
  munit_assert_string_equal(b->envelop_value->Sender,expected_b->envelop_value->Sender);
  munit_assert_string_equal(b->envelop_value->Destination,expected_b->envelop_value->Destination);
  munit_assert_string_equal(b->envelop_value->MessageType,expected_b->envelop_value->MessageType);
  munit_assert_string_equal(b->envelop_value->CreationDateTime,expected_b->envelop_value->CreationDateTime);
  munit_assert_string_equal(b->envelop_value->MessageID,expected_b->envelop_value->MessageID);
  munit_assert_string_equal(b->envelop_value->Signature,expected_b->envelop_value->Signature);
  munit_assert_string_equal(b->envelop_value->ReferenceID,expected_b->envelop_value->ReferenceID);
  munit_assert_string_equal(b->payload,expected_b->payload);
  return MUNIT_OK;
}

static void bmd_tear_down3(void *fixture)
{
  bmd *b = (bmd*)fixture;
  free(b->envelop_value);
  free(b->payload);
  free(b);

}
bmd *bmd_attributes4()
{
  bmd *b = (bmd*)malloc(sizeof(bmd));
  bmd_envelop *e = (bmd_envelop*)malloc(sizeof(bmd_envelop));
  e->Sender = "S4";
  e->Destination = "D4";
  e->CreationDateTime = "2020-08-12T05:18:00+00001";
  e->MessageID = "M4";
  e->MessageType = "Bal";
  e->ReferenceID = "R4";
  e->Signature = "S4";
  b->envelop_value = e;
  b->payload = "001-01-12347";
  return b;
}

static void *bmd_setup4(const MunitParameter params[], void *user_data)
{
   char *doc = "Testcases_extract_bmd/bmd4.xml";
   bmd *b = (bmd*)malloc(sizeof(bmd));
   b->envelop_value = extract_envelop(doc);
   b->payload = extract_payload(doc);
   return b;
}


static MunitResult parse_test_xml_file4(const MunitParameter params[], void *fixture)
{
  bmd *b = (bmd*)fixture;
  bmd *expected_b = bmd_attributes4();
  munit_assert_string_equal(b->envelop_value->Sender,expected_b->envelop_value->Sender);
  munit_assert_string_equal(b->envelop_value->Destination,expected_b->envelop_value->Destination);
  munit_assert_string_equal(b->envelop_value->MessageType,expected_b->envelop_value->MessageType);
  munit_assert_string_equal(b->envelop_value->CreationDateTime,expected_b->envelop_value->CreationDateTime);
  munit_assert_string_equal(b->envelop_value->MessageID,expected_b->envelop_value->MessageID);
  munit_assert_string_equal(b->envelop_value->Signature,expected_b->envelop_value->Signature);
  munit_assert_string_equal(b->envelop_value->ReferenceID,expected_b->envelop_value->ReferenceID);
  munit_assert_string_equal(b->payload,expected_b->payload);
  return MUNIT_OK;
}

static void bmd_tear_down4(void *fixture)
{
  bmd *b = (bmd*)fixture;
  free(b->envelop_value);
  free(b->payload);
  free(b);

}


MunitTest tests[] = {
    {
        "/bmd_test",   /* name */
         parse_test_xml_file,  /* test function */
         bmd_setup,     /* setup function for the test */
         bmd_tear_down, /* tear_down */
         MUNIT_TEST_OPTION_NONE,  /* options */
         NULL                     /* parameters */
     },
   { "/bmd_test1",   /* name */
        parse_test_xml_file1,  /* test function */
        bmd_setup1,     /* setup function for the test */
        bmd_tear_down1, /* tear_down */
        MUNIT_TEST_OPTION_NONE,  /* options */
        NULL },                 /* parameters */
        { "/bmd_test2",   /* name */
        parse_test_xml_file2,  /* test function */
        bmd_setup2,     /* setup function for the test */
        bmd_tear_down2, /* tear_down */
        MUNIT_TEST_OPTION_NONE,  /* options */
        NULL },                 /* parameters */
         { "/bmd_test3",   /* name */
        parse_test_xml_file3,  /* test function */
        bmd_setup3,     /* setup function for the test */
        bmd_tear_down3, /* tear_down */
        MUNIT_TEST_OPTION_NONE,  /* options */
        NULL },                   /* parameters */
          { "/bmd_test4",   /* name */
        parse_test_xml_file4,  /* test function */
        bmd_setup4,     /* setup function for the test */
        bmd_tear_down4, /* tear_down */
        MUNIT_TEST_OPTION_NONE,  /* options */
        NULL },   
  {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};
  static const MunitSuite suite = {
    "/tests",                 /* name */
    tests,                    /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};


int main(int argc, const char *argv[])
{
  return munit_suite_main(&suite, NULL, argc, NULL);
}   

