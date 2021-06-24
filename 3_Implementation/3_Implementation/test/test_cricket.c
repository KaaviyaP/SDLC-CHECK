
#include "unity.h"
#include "virtual_cricket.h"
#define PROJECT_NAME "virtual_cricket"

/* Prototypes for all the test functions */
void test_defineplayers(void);
void test_validateeID(void);
void test_checkIDRange(void);
void test_displayTeam(void);
void test_welcome(void);
void test_checktossTeam(void);
void test_checktossChoice(void);
void test_displayPoolPlayers(void);
void test_sort_array(void);
void test_merge_array(void);
void test_get_position(void);
void test_median_of_array(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  
  RUN_TEST(test_welcome);
  RUN_TEST(test_displayPoolPlayers);
  
  RUN_TEST(test_defineplayers);
  RUN_TEST(test_validateeID);
  RUN_TEST(test_checkIDRange);
  RUN_TEST(test_displayTeam);

  RUN_TEST(test_checktossTeam);
  RUN_TEST(test_checktossChoice);
 
  RUN_TEST(test_sort_array);
  RUN_TEST(test_merge_array);
  RUN_TEST(test_get_position);
  RUN_TEST(test_median_of_array);
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/*Test Function to check id Instructions are displayed*/
void test_welcome(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,welcome());
}

/*Test function to check if the ool os players are displayed*/
void test_displayPoolPlayers(void)
{
    TEST_ASSERT_EQUAL(SUCCESS,displayPoolPlayers(8));
    TEST_ASSERT_EQUAL(FAILURE,displayPoolPlayers(-1));
    TEST_ASSERT_EQUAL(FAILURE,displayPoolPlayers(0));
}

/* Test function to check if 8 players are defined*/
void test_defineplayers(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,defineplayers(8));
  TEST_ASSERT_EQUAL(FAILURE,defineplayers(0));
  TEST_ASSERT_EQUAL(FAILURE,defineplayers(-1));
  TEST_ASSERT_EQUAL(FAILURE,defineplayers(9));
  TEST_ASSERT_EQUAL(FAILURE,defineplayers(7));
}

/* Test function to check validateID */ 
void test_validateeID(void) {
  TEST_ASSERT_EQUAL(1, validateeID(1,1,1));
  TEST_ASSERT_EQUAL(1, validateeID(5,5,1));
  TEST_ASSERT_EQUAL(1, validateeID(8,8,1));
  TEST_ASSERT_EQUAL(-1, validateeID(1,1,0));
  TEST_ASSERT_EQUAL(-1, validateeID(5,7,1));
  TEST_ASSERT_EQUAL(-1, validateeID(9,9,1));
  TEST_ASSERT_EQUAL(-1, validateeID(11,11,0));

}

/* Test function to check checkIDRange */ 
void test_checkIDRange(void)
{
  TEST_ASSERT_EQUAL(1,checkIDRange(8));
  TEST_ASSERT_EQUAL(1,checkIDRange(1));
  TEST_ASSERT_EQUAL(1,checkIDRange(5));
  TEST_ASSERT_EQUAL(-1,checkIDRange(-1));
  TEST_ASSERT_EQUAL(-1,checkIDRange(11));
}

/*Test Function to check id 8 player names are displayed*/
void test_displayTeam(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,displayTeam(8)); 
  TEST_ASSERT_EQUAL(FAILURE,displayTeam(7)); 
  TEST_ASSERT_EQUAL(FAILURE,displayTeam(-1)); 
  TEST_ASSERT_EQUAL(FAILURE,displayTeam(9)); 
}

/*Test function to Function to check the Teams(A/B) in toss*/
void test_checktossTeam(void)
{
  TEST_ASSERT_EQUAL(1,checktossTeam("TeamA"));
  TEST_ASSERT_EQUAL(1,checktossTeam("TeamB"));
  TEST_ASSERT_EQUAL(0,checktossTeam("TeamC"));                                                                    
}

/* Test function to test the choice of Batting/Bowling after toss*/
void test_checktossChoice(void)
{
  TEST_ASSERT_EQUAL(1,checktossChoice("BAT"));
  TEST_ASSERT_EQUAL(1,checktossChoice("BOWL"));
  TEST_ASSERT_EQUAL(0,checktossChoice("XYZ"));
}


/*Test function to check array sort*/
void test_sort_array(void) {
  //int s1[2]={2,2};
  //int s2[2]={1,1};
  //int s3[2]={0,0};
  //TEST_ASSERT_EQUAL(SUCCESS,sort_array(s1,s2,3,s3));
  /*TEST_ASSERT_EQUAL(NULL,sort_array(2 2,1 1,3,0 0));
  TEST_ASSERT_EQUAL(NULL,sort_array(2 2,1 1,2,0 0));
  TEST_ASSERT_EQUAL(NULL,sort_array(2 0,1 0,1,0 0));
  TEST_ASSERT_EQUAL(NULL,sort_array(1 1,1 1,2,0 0));
  TEST_ASSERT_EQUAL(NULL,sort_array(1 0,1 0,1,0 0));*/
  
  /* Dummy fail*/
  //TEST_ASSERT_EQUAL(15000, sort_array(7500, 7500));
}

/*Test function to check array merge*/
void test_merge_array(void) {
  //int a1[2]={2,2};
  //int a2[2]={1,0};
  //int a3[2]={1,1};
  //int a4[2]={2,1};
  //int a5[2]={2,2};
  //int a6[2]={0,0};
  //TEST_ASSERT_EQUAL(SUCCESS,merge_array(a1,a1,a2,a3,a4,a2,1,1,a6));
/* TEST_ASSERT_EQUAL(NULL,merge_array(2 2,2 2,1 0,1 1,2 1,1 0,1,1,0 0));
 TEST_ASSERT_EQUAL(NULL,merge_array(1 1,1 0,1 0,1 1,1 0,1 0,1,1,0 0)); */
  //TEST_ASSERT_EQUAL(merge_array(2 2,1 2,1 1,1 1,1 2,2 1,2,1,0 0));
  /* Dummy fail*/
  //TEST_ASSERT_EQUAL(100, merge_array(1000, 900));
}

/*Test function to check Object position*/
void test_get_position(void) {
  int t1[2]={0,0};
  TEST_ASSERT_EQUAL(0, get_position(t1,0,0));
  /*TEST_ASSERT_EQUAL(0, get_position(0 0,0,0));
  TEST_ASSERT_EQUAL(1, get_position(2 1,2,0));
  TEST_ASSERT_EQUAL(0, get_position(1 2,1,0));*/
  /* Dummy fail*/
 // TEST_ASSERT_EQUAL(10, get_position(2, 5));
}

/*Test function to check array median*/
void test_median_of_array(void) {
  int m1[2]={1,2};
  TEST_ASSERT_EQUAL(1, median_of_array(m1,2));
 /* TEST_ASSERT_EQUAL(1, median_of_array(1 2,2));
  TEST_ASSERT_EQUAL(0, median_of_array(1 2,0));
  TEST_ASSERT_EQUAL(0, median_of_array(0 0,1));
  TEST_ASSERT_EQUAL(0, median_of_array(0 0,0));*/
  /* Dummy fail*/
  //TEST_ASSERT_EQUAL(1, median_of_array(2, 2));
}




