/*
 * name : Ji Woong Kim
 * lab3
 *
 * BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 * ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 * ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 * OR ONE OF OUR UNDEGRADUATE GRADERS.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ballStructs.h"
#include "constants.h"

void readAll( allBalls * ptr );
void printAll( allBalls * allBallsPtr, double et );
void oneSimStep(  allBalls * allBallsPtr , double et);
void updateOneBall( singleBall * ball , double et);
void adjustList( allBalls * allBallsPtr, int slot );
void physics( singleBall * ball );
int leftConstraint( singleBall * ball , double et);
int rightConstraint( singleBall * ball , double et);
int topConstraint(singleBall * ball, double et);


int main(){
	double et = 0.0;
	allBalls group;
	readAll( &group );
	printf("Ball\tX\tY\tVX\tVY\tet\n");
	printAll(  &group ,et );	
	while( group.count > 0 ){
	    et += INTERVAL;
	    oneSimStep( &group, et );
	    printAll(  &group ,et );	
	}
	free( group.ballPtr);
	group.ballPtr = NULL;
}


void readAll( allBalls * allBallsPtr ){	
	int i = 0;
	singleBall * wp;
	allBallsPtr -> count = 0;
	allBallsPtr -> ballPtr = NULL;
	allBallsPtr -> ballPtr = (singleBall*)realloc(allBallsPtr -> ballPtr , sizeof(singleBall) );
	wp = allBallsPtr -> ballPtr; /* It points the memory to get a ball information, if there is ball that is ready to play in */
	while( scanf("%lf%lf%lf%lf", &(wp -> X) ,&(wp -> Y), &(wp -> VX), &( wp -> VY) ) == 4 ){   /* It catches balls information as long as there are still balls */
	    wp -> name = 'A' + i;
	    (allBallsPtr -> count)++;
	    allBallsPtr -> ballPtr = (singleBall*)realloc( allBallsPtr -> ballPtr , (allBallsPtr -> count+1)  * (sizeof(singleBall)) ); /*It adds the memory from initial allocated memory */		
	    i++;	
	    wp = (allBallsPtr -> ballPtr) + i; /* wp points the memory just in case if there is a more ball ready to play */	
	}
}

void printAll( allBalls * allBallsPtr, double et){
	int i=0 ;
	while( i < allBallsPtr -> count){	
	    printf( "%c\t%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%4.2lf\n", (allBallsPtr->ballPtr)[i].name, (allBallsPtr->ballPtr)[i].X, (allBallsPtr->ballPtr)[i].Y, (allBallsPtr->ballPtr)[i].VX,(allBallsPtr->ballPtr)[i].VY, et);  
	    i++;
	}
	printf("\n");
}


void oneSimStep( allBalls * allBallsPtr, double et){
	int i;	
	for( i = (allBallsPtr -> count)-1; i>=0 ; i-- ){  /* It checks every ball for one next step */
	    updateOneBall( ((allBallsPtr->ballPtr)+i ), et); /* It passes the the single ball pointer to get update value  */
	    if( (allBallsPtr -> ballPtr)[i].Y < 0  ){
		fprintf(stderr, "Ball %c leaves the table at %4.2lf seconds\n" , (allBallsPtr->ballPtr)[i].name, et);
		adjustList( allBallsPtr , i );
	    }	
	}
}

void updateOneBall(singleBall * ball, double et){
	int i;
	int (*fp[3])(singleBall * , double et)  = {  leftConstraint , rightConstraint  ,topConstraint  } ; 
	physics( ball);

	
	for(i = 0 ; i<3 ;  i ++){
		if( (fp[i])(ball ,et  )){
		    i=-1 ;
		}
	}
}

void physics(singleBall * ball){  /* It updates the ball movement */
	ball -> X = (ball -> X) + ( (ball->VX) * INTERVAL );
	ball -> Y = (ball -> Y) + ( (ball->VY) * INTERVAL ); 
	ball -> VY = (ball -> VY) + YACEL * INTERVAL; 
}

int leftConstraint(singleBall * ball , double et){
	int check = 0;
   	if(ball->X < LEFTWALL){
	     fprintf(stderr, "Ball %c hits left wall at %4.2lf seconds pos (%5.2lf, %5.2lf) vel (%6.2lf,%6.2lf)\n",ball->name,et,ball->X,ball->Y,ball->VX,ball->VY);
	     ball -> X = REVERSER * (ball -> X);
	     ball -> VX = REVERSER * (ball -> VX);
	     check=1;	 
						 
         }	
	return check;
}

int rightConstraint(singleBall * ball ,double et ){
	int check = 0 ;
	if( ball ->X > WIDTH ){
	    fprintf(stderr, "Ball %c hits right wall at %4.2lf seconds pos (%5.2lf, %5.2lf) vel (%6.2lf,%6.2lf)\n",ball->name,et,ball->X,ball->Y,ball->VX,ball->VY);
	    ball -> X = (ball -> X) -  2*( (ball -> X) - WIDTH );
	    ball -> VX = REVERSER * (ball -> VX);
	    check=1;
	}
    	return check;
}

int topConstraint(singleBall * ball ,double et ){
	int check = 0 ;
	if( ball -> Y > HEIGHT  ){
	    fprintf(stderr, "Ball %c hits top at %4.2lf seconds pos (%5.2lf, %5.2lf) vel (%6.2lf,%6.2lf)\n",ball->name,et,ball->X,ball->Y,ball->VX,ball->VY);
	    ball -> Y = (ball -> Y) -  2*( (ball -> Y) - HEIGHT );
	    ball -> VY = REVERSER * (ball -> VY);
	    check =1;
	}
	return check;
}



void adjustList( allBalls * allBallsPtr, int slot){
	int i = slot ;
	while( i  < allBallsPtr->count){ /* It moves up all balls which were behind the ball fallen off */
	    (allBallsPtr -> ballPtr) [i] = (allBallsPtr -> ballPtr)[i+1];
	    i++;
	}
	(allBallsPtr -> count) --;
}
