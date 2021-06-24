/**
 * @file Feature2.c
 * @author Kaaviya Perumal(kaaviya.perumal@ltts.com)
 * @brief Creating Teams,defining its players and displaying them
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "virtual_cricket.h"

/**
 * @brief Structure to store all the player details
 * 
 */
struct players{
        char name[50];
        int id;  
        int runsScored;
        int ballsPlayed;
        int ballsBowled;
        int runsGiven;
        int wicketsTaken;
};
/**
 * @brief Structure to store all the Team A details
 * 
 */
struct teamA{
    struct players PA1;
    struct players PA2;
    struct players PA3;
    struct players PA4;
    struct players captainA;
};

/**
 * @brief Structure to store all the Team B details
 * 
 */
struct teamB{
    struct players PB1;
    struct players PB2;
    struct players PB3;
    struct players PB4;
    struct players captainB;
};

/**
 * @brief Structure for Team A,B
 * 
 */
struct teams{
    struct teamA A;
    struct teamB B;
};

/**
 * @brief Function to generate IDs
 * 
 * @param lower 
 * @param upper 
 * @param count 
 * @return int 
 */
int getID(int lower, int upper, int count)
{
        int id = (rand() %
           (upper - lower + 1)) + lower;
        return id;
}

/**
 * @brief Function to check if IDs are between 1-8
 * 
 * @param x 
 * @return int 
 */
int checkIDRange(int x)
{
    if(x>=1 && x<=8)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}

/**
 * @brief Function to validate player IDs
 * 
 * @param p_id 
 * @param x 
 * @param availibility 
 * @return int 
 */
int validateID(int p_id,int x,int availibility)
{
    int k=checkIDRange(x);
    int v=validateeID(p_id,x,availibility);
    if(p_id==x && availibility==1 && k!=0 && v!=0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Function to validate player IDs for testing
 * 
 * @param p_id 
 * @param x 
 * @param availibility 
 * @return int 
 */
int validateeID(int p_id,int x,int availibility)
{
    if(p_id==x && availibility==1 && p_id>=1 && p_id<=8)
    {
        return 1;
    }
    else{
        return -1;
    }
}

/**
 * @brief Structure to store status of players
 * 
 */
typedef struct p {
char name[50];
int id;
int available;
} player;

player p1;
player p2;
player p3;
player p4;
player p5;
player p6;
player p7;
player p8;

/**
 * @brief Function to define the 8 players
 * 
 * @param totalPlayers 
 * @return error_t 
 */
error_t defineplayers(int totalPlayers)
{   

    int i1=0;
    strcpy(p1.name, "Virat");
    p1.id=1;
    p1.available=1;
    i1++;
 
    strcpy(p2.name, "Rohit");
    p2.id=2;
    p2.available=1;
    i1++;

    strcpy(p3.name, "Dhoni");
    p3.id=3;
    p3.available=1;
    i1++;

    strcpy(p4.name, "Pant");
    p4.id=4;
    p4.available=1;
    i1++;
        
    strcpy(p5.name, "KLRahul");
    p5.id=5;
    p5.available=1;
    i1++;
        
    strcpy(p6.name, "Raina");
    p6.id=6;
    p6.available=1;
    i1++;
        
    strcpy(p7.name, "Jadeja");
    p7.id=7;
    p7.available=1;
    i1++;
        
    strcpy(p8.name, "Sachin");
    p8.id=8;
    p8.available=1;
    i1++;
        
    if(totalPlayers==i1)
    {
         return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
   
}

struct teams team;
struct teams createTeam();
char pool1[8][50];

/**
 * @brief Create a Team objectFunction to create 2 Teams with 4 player each
 * 
 * @return struct teams 
 */
struct teams createTeam()
{
    printf("The Teams will be created automatically. Please wait....\n\n");

    
    int i=0;
    while(i<8)
    {
        int lower = 1, upper = 8, count = 1;
        srand(time(0));
        int x=getID(lower, upper, count);

        if (validateID(p1.id,x,p1.available))
        {
            strcpy(pool1[i],p1.name);
            p1.available=0;
            i++;
        }
        else if (validateID(p2.id,x,p2.available))
        {
            strcpy(pool1[i],p2.name);
            p2.available=0;
            i++;
        }
        else if (validateID(p3.id,x,p3.available))
        {
            strcpy(pool1[i],p3.name);
            p3.available=0;
            i++;
        }
        else if (validateID(p4.id,x,p4.available))
        {
            strcpy(pool1[i],p4.name);
            p4.available=0;
            i++;
        }
        else if (validateID(p5.id,x,p5.available))
        {
           strcpy(pool1[i],p5.name);
            p5.available=0;
            i++;
        }
        else if (validateID(p6.id,x,p6.available))
        {
            strcpy(pool1[i],p6.name);
            p6.available=0;
            i++;
        }
        else if (validateID(p7.id,x,p7.available))
        {
            strcpy(pool1[i],p7.name);
            p7.available=0;
            i++;
        }
        else if (validateID(p8.id,x,p8.available))
        {
            strcpy(pool1[i],p8.name);
            p8.available=0;
            i++;
        }  
    }
    
    team.A.PA1.id=1;
    strcpy(team.A.PA1.name, pool1[0]);
    team.A.PA2.id=2;
    strcpy(team.A.PA2.name, pool1[1]);
    team.A.PA3.id=3;
    strcpy(team.A.PA3.name, pool1[2]);
    team.A.PA4.id=4;
    strcpy(team.A.PA4.name, pool1[3]);
    team.A.captainA.id=1;
    strcpy(team.A.captainA.name, pool1[0]);
    
    team.B.PB1.id=5;
    strcpy(team.B.PB1.name, pool1[4]);
    team.B.PB2.id=6;
    strcpy(team.B.PB2.name, pool1[5]);
    team.B.PB3.id=7;
    strcpy(team.B.PB3.name, pool1[6]);
    team.B.PB4.id=8;
    strcpy(team.B.PB4.name, pool1[7]);
    team.B.captainB.id=5;
    strcpy(team.B.captainB.name, pool1[4]);

    return team;

}

/**
 * @brief Function to display teams
 * 
 * @param n 
 * @return error_t 
 */
error_t displayTeam(int n)
{   
    int initial=0;
    printf("TEAM A :\n");
    for(int i=0;i<4;i++)
    {
        printf("%s\n", pool1+i);
        initial++;
    }
    printf("\n");
    printf("TEAM B :\n");
    for(int i=4;i<8;i++)
    {
        printf("%s\n", pool1+i);
        initial++;
    }
    printf("\n");
    if(initial==n){
     return SUCCESS;
    }
    else{
        return FAILURE;
    }
   
}

