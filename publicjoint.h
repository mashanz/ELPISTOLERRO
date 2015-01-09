#ifndef PUBLIC_JOINT_H_
#define PUBLIC_JOINT_H_

	#define P_GOAL_POSITION_L 30
	#define P_GOAL_POSITION_H 31
	#define SPEED_L 32
	#define SPEED_H 33
	#define P_PRESENT_POSITION_L 36
	#define P_PRESENT_POSITION_H 37
	#define P_MOVING 46
	#define PD 500

	const int IDservo [20]=       {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,  32,31};
	int dataArray [20];
	int condition;
	int Ball_Loc_X,Ball_Loc_Y;
	int Goal_Loc_X,Goal_Loc_Y;
	int jarakGawang;
	int jarakBola;
	int speed,G_delayKu;
	int kodegerak;
	int virtualGyroX,virtualGyroY;
	bool EnableMove;
	bool EnableSensor;
	bool EnableVision;
	bool ready;
	int walkParam1,walkParam2;
#endif
