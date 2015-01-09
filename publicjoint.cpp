//#include "publicjoint.h"
#include <iostream>
#include <pthread.h>

#define P_GOAL_POSITION_L 30
#define P_GOAL_POSITION_H 31
#define SPEED_L 32
#define SPEED_H 33
#define P_PRESENT_POSITION_L 36
#define P_PRESENT_POSITION_H 37
#define P_MOVING 46
#define PD 500
#define PI 3.14159265
//////////////////////////// SETTING HERE! ////////////////////////
#define HEADX   20  	//SERVO GELENG
#define HEADY   19 	//SERVO ANGGUK
#define SELF_TIMING_DELAY 10000


//////////////////////////////////////////////////////////////////
/*******************************************************
 *                 PUBLIC VARIABLE                     *
 *******************************************************/
const int IDservo [20]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,HEADY,HEADX};
// [.:.] FUNCTION HEADER
// [.:.] THREADING LOCK
pthread_mutex_t	lock_intr, //for "INTERRUPT"
lock_move, 	//for "move access"
lock_callmove, //for calling move
lock_movecallback,
lock_EnableSensor,
lock_ready;

int modifierID,
	serX = 512,
	serY = 512,
	dcs = 30;
int DXLerrCode;
int condition;
int Ball_Loc_X,Ball_Loc_Y;
int Goal_Loc_X,Goal_Loc_Y;
int jarakGawang;
int jarakBola;
int speed,G_delayKu;
int virtualGyroX,virtualGyroY;
int kodegerak;
int dataArray [20];
bool ready=true;
bool EnableMove;
bool EnableSensor;
bool EnableWifi;
bool EnableVision;
int walkParam1,walkParam2;

//Stabilizier variable
int VarID[20];
int VarPID[20];

float MainHeadingThresh;

void PID();
void CallMove();
void WaitMove();
void resetStabilizer(int IDtubuh);
void stabilizer1(int IDtubuh, float errorValue, float gainKA1, float gainKI1,float gainKA2, float gainKI2,float gainKA3, float gainKI3);
void stabilizer2(int IDtubuh, int adderKA1, int adderKI1,int adderKA2, int adderKI2, int adderKA3, int adderKI3);

