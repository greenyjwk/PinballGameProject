#include <stdio.h>

int main(){
	
	const double WIDTH = 22.0;
	const double HEIGHT = 48.0;
	const double YACCELERATION = -47.052534795;	
	const double REVERSER = -1;
	const double INTERVAL = 0.1;

	double xV ; 
 	double yV ;
	double xPosition ;
	double yPosition;
	double et = 0.0;	
	
	while( scanf("%lf%lf%lf%lf", &xPosition , &yPosition, &xV , &yV  )  == 4 ) {
		
		et =0.0;
		printf("start\n");
		printf("X\t\tY\t\tVX\t\tVY\t\tET\n");
		printf("%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV , et );
	
		while( yPosition >= 0 ){

			xPosition = xPosition + ( xV * INTERVAL );
			yPosition = yPosition + ( yV * INTERVAL );
			et = et + INTERVAL;
		
			yV = yV + YACCELERATION * INTERVAL;

			if( xPosition<0 ){
				if(yPosition>HEIGHT){
			
					printf("Ball hits left wall at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
					printf("Fixing position and velocity\n");
					xPosition = REVERSER * xPosition;
					xV = REVERSER * xV;					


					printf("Ball hits ceiling at %6.2lf seconds\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
					printf("Fixing position and velocity\n");
					yPosition = 2 * HEIGHT - yPosition;
					yV = REVERSER * yV;
						
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV ,et);
				

				}else if(yPosition<=HEIGHT && yPosition >= 0){
 					printf("Ball hits left wall at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
			
					xPosition = REVERSER * xPosition;
					xV = REVERSER * xV;
					
					printf("Fixing position and velocity\n");
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV ,et);
				
				}else{
					printf("Ball leaves table at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
				}
	
			}else if( xPosition > WIDTH){

				if(yPosition > HEIGHT){

					printf("Ball hits right wall at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
					printf("Fixing position and velocity\n");
					xPosition = 2 * WIDTH - xPosition;
					xV = REVERSER * xV;					

					printf("Ball hits ceiling at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
					printf("Fixing position and velocity\n");
					yPosition = 2 * HEIGHT -yPosition;
					yV = REVERSER * yV;		
		
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV , et);
				
				}else if(yPosition <= HEIGHT && yPosition >=0 ){
			
					printf("Ball hits right wall at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
			
					xPosition = 2 * WIDTH - xPosition;		
					xV = REVERSER * xV;
				
					printf("Fixing position and velocity\n");
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV,et );
		
				}else{
			
					printf("Ball leaves table at %6.2lf seconds:\n", et );
					printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
			
				}

			}else if(yPosition > HEIGHT ){
		
				printf("Ball hits the ceiling at %6.2lf seconds:\n", et );
				printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
		
				yPosition = 2 * HEIGHT - yPosition;		
				yV = REVERSER * yV;
			
				printf("Fixing position and velocity\n");
				printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV, et );
		
			}else if(yPosition < 0 ){
			
				printf("Ball leaves table at %6.2lf seconds:\n", et );
				printf( "%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\n", xPosition, yPosition , xV , yV );
		
			}else{
			
				printf("%8.4lf\t%8.4lf\t%8.4lf\t%8.4lf\t%6.2lf\n", xPosition, yPosition , xV , yV , et );
		
			}
		}
	}
}
