/**
 * @file virtualcricket.h
 * Plays a virtual cricket with 2 teams
 * 
 */

#ifndef __VIRTUAL_CRICKET_H__
#define __VIRTUAL_CRICKET_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef enum error_t{
    SUCCESS=1,
    FAILURE=0,
}error_t;

/**
 * @brief 
 * 
 */
struct teams getdetails();

/**
 * @brief Welcome to Virtual Cricket function
 * 
 */
error_t welcome();


/**
 * @brief 
 * 
 * @param totalPlayers 
 */
error_t displayPoolPlayers(int totalPlayers);

/**
 * @brief 
 * 
 * @return int 
 */
int takeIntegerOnly();

/**
 * @brief 
 * 
 * @param lower 
 * @param upper 
 * @param count 
 * @return int 
 */
int getID(int lower, int upper, int count);

/**
 * @brief 
 * 
 * @param p_id 
 * @param x 
 * @param availibility 
 * @return int 
 */
int validateID(int p_id,int x,int availibility);


/**
 * @brief Function to check if IDs are between 1-8
 * 
 * @param x 
 * @return int 
 */
int checkIDRange(int x);

/**
 * @brief Function to validate player IDs for testing
 * 
 * @param p_id 
 * @param x 
 * @param availibility 
 * @return int 
 */
int validateeID(int p_id,int x,int availibility);

/**
 * @brief Defining the 8 players
 * 
 */
error_t defineplayers(int totalPlayers);

/**
 * @brief 
 * 
 */
error_t displayTeam(int n);

/**
 * @brief Get the Player Toss object
 * 
 * @param TeamA 
 * @param TeamB 
 * @param t 
 * @return struct Tuple 
 */
struct Tuple GetPlayerToss(char TeamA[],char TeamB[],struct teams t);

/**
 * @brief Get the Choice object
 * 
 * @param winner 
 * @param loser 
 * @return char* 
 */
char* getChoice(char winner[],char loser[]);

/**
 * @brief Checking the team for the Toss
 * 
 * @param t 
 * @return int 
 */
int checktossTeam(char t[50]);

/**
 * @brief Choice for Head or Tail
 * 
 * @param c 
 * @return int 
 */
int checktossChoice(char c[10]);

void play();


/**
 * @brief Function to start the first innings
 * 
 * @param TeamA 
 * @param TeamB 
 * @param maxballs 
 */
void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs);

/**
 * @brief Function for initialising the players
 * 
 * @param TeamA 
 * @param TeamB 
 * @param maxballs 
 */

void initialisingPlayers(char TeamA[4][50],char TeamB[4][50],int maxballs);

/**
 * @brief Function to start the Second Innings
 * 
 * @param TeamB 
 * @param TeamA 
 * @param maxballs 
 */
void startSecondInnings(char TeamB[4][50],char TeamA[4][50],int maxballs );

/**
 * @brief Function to start the play
 * 
 * @param TeamA 
 * @param TeamB 
 * @param batsman 
 * @param bowler 
 * @param maxballs 
 * @return int 
 */

int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs);

/**
 * @brief Function to start the batting
 * 
 * @param TeamA 
 * @param TeamB 
 * @param batsman 
 * @param bowler 
 * @return int 
 */

int bat(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50]);

/**
 * @brief Function to start the teams to Toss
 * 
 * @param t 
 * @param toss 
 */

/**
 * @brief Function to start the toss
 * 
 */

void start(struct teams t,struct Tuple toss);



/**
 * @brief 
 * Sort the array
 * 
 * @param arr_name 
 * @param count 
 * @param size 
 * @param new_size 
 */
void sort_array(int*arr_name, int *count,int size, int*new_size);
/**
 * @brief Merging the arrays
 * 
 * @param arr_name 
 * @param left 
 * @param right 
 * @param count 
 * @param count_left 
 * @param count_right 
 * @param left_size 
 * @param right_size 
 * @param new_size 
 */
void merge_array(int*arr_name, int*left,int*right, int *count, int*count_left,int*count_right, int left_size, int right_size, int*new_size);
/**
 * @brief Get the position object
 * 
 * @param arr_name 
 * @param num 
 * @param size 
 * @return int 
 */
int get_position(int*arr_name, int num, int size);
/**
 * @brief Median of array
 * 
 * @param arr_name 
 * @param size 
 * @return int 
 */
int median_of_array(int*arr_name, int size);

/**
 * @brief Sub game played between 2 players each selected between the rival teams
 * 
 */
void rivalGame();
/**
 * @brief Function to show the score card
 * 
 * @param batsman_name 
 * @param batsman_runsScored 
 * @param batsman_ballsPlayed 
 * @param battingTeam_totalRunsScored 
 * @param battingTeam_wicketsLost 
 * @param bowler_name 
 * @param bowler_runsGiven 
 * @param bowler_ballsBowled 
 * @param bowlingTeam_totalBallsBowled 
 * @param TeamA 
 * @param TeamB 
 */
void showScoreCard(char batsman_name[50],int batsman_runsScored,int batsman_ballsPlayed,int battingTeam_totalRunsScored,int battingTeam_wicketsLost,char bowler_name[50],int bowler_runsGiven,int bowler_ballsBowled,int bowlingTeam_totalBallsBowled,char TeamA[4][50],char TeamB[4][50]);
/**
 * @brief Function to validate the final Innings
 * 
 * @param battingTeam_totalRunsScored 
 * @param bowlingTeam_totalRunsScored 
 * @param isFirstInnings 
 * @param wicketlost 
 * @param maxBalls 
 * @param TeamA 
 * @param TeamB 
 * @param batsman 
 * @param bowler 
 * @return int 
 */
int validateInnings(int battingTeam_totalRunsScored, int bowlingTeam_totalRunsScored,int isFirstInnings,int wicketlost,int maxBalls,char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50]);
/**
 * @brief Function about the Rival Game
 * 
 * @param batsman_name 
 * @param bowler_name 
 * @param battingTeam_teamName 
 * @param bowlingTeam_teamName 
 */
void rivalGame(char batsman_name[50],char bowler_name[50],char battingTeam_teamName[4][50],char bowlingTeam_teamName[4][50]);


#endif  /* #define __VIRTUAL_CRICKET_H__ */
