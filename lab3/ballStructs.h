typedef struct {
	char name;
	double X;
	double Y;
	double VY;
	double VX;
}singleBall;


typedef struct {
	int count ;
	singleBall * ballPtr;
}allBalls;
