/*
 *
 * name : Ji Woong Kim
 * descripttion : This program runs the multiple balls in the table simultaneously until no more balls are left on the table.
 *
 */


#include <stdio.h>
#include <stdlb.h>
#include "ballStructs.h"
#include "constants.h"



int readAll();
void oneSimStep(allBalls playingGroup);
void allBalls(allBalls playingGroup  );



void physics(singleBall ball);
void leftConstraint(singleBall ball);
void rightConstraint(singleBall ball);
void topConstraint(singleBall ball);
void adjustList( allBalls group, int slot );






int main(){
	allBalls everything;
	readAll( &everything);
	
	if( allBalls.count > 0  ){
		oneSimStep( &everything );
		printAll( everything );
	}
	
}

void readAll( allBalls ptr  ){
	double X,Y,VX,VY;

	
	ptr -> count = 0;

	ptr -> ballPtr -> X;
	( ptr -> ballPtr )[];   // question  

	
	while(  scanf( "%lf%lf%lf%lf",&X,&Y,&VX,&VY) == 4 ){

		allBalls.ballPtr = (singleBall *) realloc( singleBall* ,  count * sizeof( singleBall ) ;	
		ptr->ballPtr = 	(singleBall *) realloc( singleBall* ,  count * sizeof( singleBall ); // question	


	
		allBalls.ballPtr[allBalls.count].X = X;

		ptr->ballPt   [ptr -> count ];   // question

		allBalls.ballPtr[allBalls.count].Y = Y;
		allBalls.ballPtr[allBalls.count].VX = VX;
		allBalls.ballPtr[allBalls.count].VY = VY;

		allBalls.count++;
		
	}
}


void oneSimStep(allBalls playingGroup){
	

	for( int i = 0; i<playingGroup.count ; i++ ){
		
		updateOneBall( playingGroup.ballPtr[i]);
		
		if( playingGroup.ballPtr[i].Y < 0  ){
			adjustList(  playingGroup , i );   // what is the slot number???   		
		}		
	}	
}


void printAll( allBalls playingGroup ){


}

void updateOneBall(singleBall ball){
	
	physics(ball);
	leftConstraint(ball);
	rightConstraint(ball);
	topConstraint(ball);
}



void physics(singleBall ball){

	const double INTERVAL = 0.1;
	const double YACCELERATION = -47.052534795;	
	
	ball.X = X + ball.VX * INTERVAL;
	ball.Y = Y + ball.VY * INTERVAL;

	ball.VY = VY +  YACCELERATION  * INTERVAL
		
	leftConstraint(ball);
	rightContraint(ball);
	topConstraint(ball);

}

void leftConstraint(singleBall ball){
	
	const double REVERSER = -1.0;
	
	if(ball.X < 0 ){
		ball.VX = REVERSER * ball.VX;
		ball.X = REVERSER * ball.X;
	}
}


void rightConstraint(singleBall ball){
	const double REVERSER = -1.0;
	const double WIDTH = 22.0;
	if(ball.X > WIDTH){
		ball.VX = REVESER * ball.VX;	
		ball.X =  WIDTH - (ball.X - WIDTH); 
	} 
}


void topConstraint(singleBall ball){
	const double REVESER = -1.0;
	const double HEIGHT = 48.0;
	
	if( ball.Y > HEIGHT ){
		ball.VY = ball.VY * REVERSER;
		ball.Y = HEIGHT - (ball.Y - HEIGHT); 
	}
}

void adjustList( allBalls group, int slot  ){

	group.ballPtr[   slot  ] // I used array to bind each single ball, how can I delete  and move the element in the array

	for( int i = 0 ; i< count; i++ ){
			// move the list one by one?    check the note!
		}
	}
}
