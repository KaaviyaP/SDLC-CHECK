/**
 * @file Feature5.c
 * @author Souhardya Sengupta ()
 * @brief Validating Innings and showing Match scorecard. Also,a sub-game RivalGame
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "virtual_cricket.h"
 
/**
 * @brief Function to display the scorecard
 * 
 */
void showScoreCard(char batsman_name[50],int batsman_runsScored,int batsman_ballsPlayed,int battingTeam_totalRunsScored,int battingTeam_wicketsLost,char bowler_name[50],int bowler_runsGiven,int bowler_ballsBowled,int bowlingTeam_totalBallsBowled,char TeamA[4][50],char TeamB[4][50]) {
    
   printf("\n\t\t\t\t|=============================== BATTING STATS ================================|"); 
   printf("\n\t\t\t\t____");
   printf("\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
   printf("\n\t\t\t\t    Total Team-Score  %d  -  TOTAL-WICKET-LOST%d",battingTeam_totalRunsScored,battingTeam_wicketsLost);
   printf("\n\t\t\t\t____");
   printf("\n\t\t\t\t|=============================== BOWLING STATS ================================|");
   printf("\n\t\t\t\t____");
   printf("\n\t\t\t\t  TOTAL-RUN-GIVEN %d  BALLSBOWLED(  %d  )",bowler_runsGiven,bowler_ballsBowled);
   printf("\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
   printf("\n\t\t\t\t____");
batsman_runsScored=0;
batsman_ballsPlayed=0;
batsman_name=TeamA[battingTeam_wicketsLost];

}


/**
 * @brief Function to Validate the innings
 * 
 * @return int 
 */
int validateInnings(int battingTeam_totalRunsScored, int bowlingTeam_totalRunsScored,int isFirstInnings,int wicketlost,int maxBalls,char TeamA[4][50],char TeamB[4][50],char batsman_name[50],char bowler_name[50]) {
    
    if(isFirstInnings) {
            printf("\t\t\t\t _____ \n");
            printf("\t\t\t\t|                                                                                               |\n");
            printf("\t\t\t\t|====================================== FIRST-INNINGS-ENDS =====================================|\n");
            printf("\t\t\t\t|_____|\n");
            printf("\t\t\t\t|==============================  A  ===============================|\n");
            printf("\t\t\t\t\t\t\t  %d  -  %d \n",battingTeam_totalRunsScored,wicketlost);
            //printf("\t\t\t\t\t\t\t  %d  -  %d \n",battingTeam_totalRunsScored,battingTeam_wicketsLost);
            printf("\n\t\t\t\t\t\t!!! RESULT !!!");
            printf("\n\t\t\t\t TEAM-B  needs to  score  %d   runs",battingTeam_totalRunsScored + 1);
            printf(" in  %d  balls \n",maxBalls);
            return 0;

            
        }
        else {
            
            if (battingTeam_totalRunsScored > bowlingTeam_totalRunsScored) {	
                printf("\n\n\n\t\t\t\tTEAM-A WON THE MATCH \n\n");
                rivalGame(batsman_name,bowler_name,TeamA,TeamB);
            } 
            else if (battingTeam_totalRunsScored < bowlingTeam_totalRunsScored) {
            	printf("\n\n\n\t\t\t\tTEAM-B  WON THE MATCH  \n\n");
              rivalGame(batsman_name,bowler_name,TeamB,TeamA);
            	
            } 
            else {
            	printf("\n\n\n\t\t\t\tMATCH DRAW \n\n");
            	
            }
            }
    
    return 0;
}


/**
 * The Sub part is a sub game played between 2 players each selected between the rival teams.
 * This is a two-player game where there are a certain number of stacks of candies.
 * Each stack contains certain number of candies.
 * The stacks are arranged in non-decreasing order from left to right based on the number of candies in each stack.
 * Let the two players be named as Tom and Jerry. 
 * For every continuous subsequence of candies stacks, Tom and Jerry will play game on this subsequence of candies stacks, Tom plays first, and they play in turn.
 * In one move, the player can choose one of the stacks and remove at least one candy from it keeping in mind the non-decreasing order of the candies stacks which needs to be maintained. 
 * The last person to make a valid move wins.
 * We need to find the continuous subsequences of candies stacks that will make Tom win if both of them play optimally. 
 * The number of candies of each stack will be recovered after the game ends for each subsequences.
 */
void rivalGame(char batsman_name[50],char bowler_name[50],char battingTeam_teamName[4][50],char bowlingTeam_teamName[4][50]){

  int num_of_stacks=5;
  int evensize,oddsize;
  int sort_evensize,sort_oddsize;
  int iterator_first,iterator_second;
  int temp_var;
  int *dyn_ptr,*ddyn_ptr;
  int *dseven,*dsodd;
  int *sort_even,*sort_odd;
  int *count_even,*count_odd;
  int **even_table,**odd_table;
  long long ans=0;
   
  //scanf("%d",&num_of_stacks);
  dyn_ptr=(int*)malloc(num_of_stacks*sizeof(int));
  ddyn_ptr=(int*)malloc((num_of_stacks-1)*sizeof(int));
  evensize=oddsize=(num_of_stacks-1)/2;
  evensize+=(num_of_stacks-1)%2;
  dseven=(int*)malloc(evensize*sizeof(int));
  dsodd=(int*)malloc(oddsize*sizeof(int));
  sort_even=(int*)malloc(evensize*sizeof(int));
  sort_odd=(int*)malloc(oddsize*sizeof(int));
  count_even=(int*)malloc(evensize*sizeof(int));
  count_odd=(int*)malloc(oddsize*sizeof(int));
  int arr[5] = {1,1,2,2,3};
  int c=0;

  for(iterator_first=0;iterator_first<num_of_stacks;iterator_first++)
     *(dyn_ptr+iterator_first)=arr[c++];
    
  for(iterator_first=0;iterator_first<num_of_stacks-1;iterator_first++){
    ddyn_ptr[iterator_first]=dyn_ptr[iterator_first+1]-dyn_ptr[iterator_first];
    
    if(!iterator_first)
      dseven[iterator_first/2]=ddyn_ptr[iterator_first];
      
    else if(iterator_first==1)
      dsodd[iterator_first/2]=ddyn_ptr[iterator_first];
      
    else if(iterator_first%2)
      dsodd[iterator_first/2]=dsodd[iterator_first/2-1]^ddyn_ptr[iterator_first];
      
    else
      dseven[iterator_first/2]=dseven[iterator_first/2-1]^ddyn_ptr[iterator_first];
  }

  for(iterator_first=0;iterator_first<evensize;iterator_first++){
    sort_even[iterator_first]=dseven[iterator_first];
    count_even[iterator_first]=1;
  }
  
  for(iterator_first=0;iterator_first<oddsize;iterator_first++){
    sort_odd[iterator_first]=dsodd[iterator_first];
    count_odd[iterator_first]=1;
  }
  
  sort_array(sort_even,count_even,evensize,&sort_evensize);
  sort_array(sort_odd,count_odd,oddsize,&sort_oddsize);
  
  even_table=(int**)malloc(sort_evensize*sizeof(int*));
  
  for(iterator_first=0;iterator_first<sort_evensize;iterator_first++){
    even_table[iterator_first]=(int*)malloc((count_even[iterator_first]+1)*sizeof(int));
    even_table[iterator_first][0]=0;
  }
  
  odd_table=(int**)malloc(sort_oddsize*sizeof(int*));
  
  for(iterator_first=0;iterator_first<sort_oddsize;iterator_first++){
    odd_table[iterator_first]=(int*)malloc((count_odd[iterator_first]+1)*sizeof(int));
    
    odd_table[iterator_first][0]=0;
  }
  
  for(iterator_first=0;iterator_first<evensize;iterator_first++)
  {
    iterator_second=get_position(sort_even,dseven[iterator_first],sort_evensize);
    
    even_table[iterator_second][++even_table[iterator_second][0]]=iterator_first;
  }
  for(iterator_first=0;iterator_first<oddsize;iterator_first++)
  {
    iterator_second=get_position(sort_odd,dsodd[iterator_first],sort_oddsize);
    
    odd_table[iterator_second][++odd_table[iterator_second][0]]=iterator_first;
  }
  for(iterator_first=0;iterator_first<num_of_stacks-1;iterator_first++)
  
    if(iterator_first%2){
      temp_var=dyn_ptr[iterator_first]^dseven[(iterator_first-1)/2];
      iterator_second=get_position(sort_even,temp_var,sort_evensize);
      if(iterator_second>=0 && iterator_second<sort_evensize && sort_even[iterator_second]==temp_var){
        temp_var=get_position(even_table[iterator_second]+1,(iterator_first+1)/2,even_table[iterator_second][0]);
        ans+=even_table[iterator_second][0]-temp_var;
      }
      temp_var=0;
      if(iterator_first!=1)
        temp_var^=dsodd[(iterator_first-2)/2];
      iterator_second=get_position(sort_odd,temp_var,sort_oddsize);
      if(iterator_second>=0 && iterator_second<sort_oddsize && sort_odd[iterator_second]==temp_var){
        temp_var=get_position(odd_table[iterator_second]+1,iterator_first/2,odd_table[iterator_second][0]);
        ans+=odd_table[iterator_second][0]-temp_var;
      }
    }
    else{
      temp_var=dyn_ptr[iterator_first];
      if(iterator_first)
        temp_var^=dsodd[(iterator_first-1)/2];
      iterator_second=get_position(sort_odd,temp_var,sort_oddsize);
      if(iterator_second>=0 && iterator_second<sort_oddsize && sort_odd[iterator_second]==temp_var){
        temp_var=get_position(odd_table[iterator_second]+1,iterator_first/2,odd_table[iterator_second][0]);
        ans+=odd_table[iterator_second][0]-temp_var;
      }
      temp_var=0;
      if(iterator_first)
        temp_var^=dseven[(iterator_first-1)/2];
      iterator_second=get_position(sort_even,temp_var,sort_evensize);
      if(iterator_second>=0 && iterator_second<sort_evensize && sort_even[iterator_second]==temp_var){
        temp_var=get_position(even_table[iterator_second]+1,iterator_first/2,even_table[iterator_second][0]);
        ans+=even_table[iterator_second][0]-temp_var;
      }
    }
  ans=((long long)num_of_stacks)*(num_of_stacks-1)/2-ans;
  printf("\n|==========================RIVAL GAME==================================|\n");
  printf("\nPlayers chosen from either teams are %s and %s\n",batsman_name,bowler_name);
  
  if((ans)>=num_of_stacks && num_of_stacks>0){

  printf("|=====%s won the game from %s",batsman_name,battingTeam_teamName);
  }
  else
  {
   printf("|=====%s won the game from %s",bowler_name,bowlingTeam_teamName);
  }
  printf("\n|=====Thank you for playing this game\n");
  free(dyn_ptr);free(ddyn_ptr);
  free(dseven);free(dsodd);
  free(sort_even),free(sort_odd);
  free(count_even);free(count_odd);
  free(even_table);free(odd_table);
  return;
}

/**
 * @brief Function to sort the array
 * 
 * @param arr_name 
 * @param count 
 * @param size 
 * @param new_size 
 */
void sort_array(int*arr_name,int *count,int size,int*new_size){
  if (size < 2){
    (*new_size)=size;
    return;
  }
  int m = (size+1)/2,iterator_first;
  int *left,*right,*count_left,*count_right;
  left=(int*)malloc(m*sizeof(int));
  right=(int*)malloc((size-m)*sizeof(int));
  count_left=(int*)malloc(m*sizeof(int));
  count_right=(int*)malloc((size-m)*sizeof(int));
  for(iterator_first=0;iterator_first<m;iterator_first++){
    left[iterator_first]=arr_name[iterator_first];
    count_left[iterator_first]=count[iterator_first];
  }
  for(iterator_first=0;iterator_first<size-m;iterator_first++){
    right[iterator_first]=arr_name[iterator_first+m];
    count_right[iterator_first]=count[iterator_first+m];
  }
  int new_l_size=0,new_r_size=0;
  sort_array(left,count_left,m,&new_l_size);
  sort_array(right,count_right,size-m,&new_r_size);
  merge_array(arr_name,left,right,count,count_left,count_right,new_l_size,new_r_size,new_size);
  free(left);
  free(right);
  free(count_left);
  free(count_right);
  return;
}

/**
 * @brief Function to merge the arrays
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
void merge_array(int*arr_name,int*left,int*right,int *count,int*count_left,int*count_right,int left_size, int right_size,int*new_size){
  int iterator_first = 0, iterator_second = 0,index=0;
  while (iterator_first < left_size|| iterator_second < right_size) {
    if (iterator_first == left_size) {
      count[index] = count_right[iterator_second];
      arr_name[index++] = right[iterator_second];
      iterator_second++;
    } else if (iterator_second == right_size) {
      count[index] = count_left[iterator_first];
      arr_name[index++] = left[iterator_first];
      iterator_first++;
    } else if (left[iterator_first] <= right[iterator_second]) {
      count[index] = count_left[iterator_first];
      arr_name[index++] = left[iterator_first];
      iterator_first++;
    } else {
      count[index] = count_right[iterator_second];
      arr_name[index++] = right[iterator_second];
      iterator_second++;
    }
    if(index>1&&arr_name[index-2]==arr_name[index-1]){
      index--;
      count[index-1]+=count[index];
    }
  }
  (*new_size)=index;
  return;
}

/**
 * @brief Function to get the position object
 * 
 * @param arr_name 
 * @param num 
 * @param size 
 * @return int 
 */
int get_position(int*arr_name,int num,int size){
  if(size==0)
    return 0;
  if(num>median_of_array(arr_name,size))
    return get_position(&arr_name[(size+1)>>1],num,size>>1)+((size+1)>>1);
  else
    return get_position(arr_name,num,(size-1)>>1);
}

/**
 * @brief Function to get the median arrray
 * 
 * @param arr_name 
 * @param size 
 * @return int 
 */
int median_of_array(int*arr_name,int size){
  return arr_name[(size-1)>>1];
}
