/*==================================================================================
 *                                  LIBRARY
 *================================================================================*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <dynamixel.h>
#include <math.h>
//#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

//#include "raspicam_still_cv.h"
//pengambilan liblary dari program lain
#include "ELPmove.cpp"
#include "ELPSense.c"
#include "ELPMain.cpp"
#include "GPIOClass.cpp"
//#include "ELPWifi.c"
#include "ELPCam.c"


/*==================================================================================
 *                                  Function
 *================================================================================*/
void case(){
	switch(CamCommand){
		//===================================== 1  =================================
		case 1:
			while(enable_move = 1){
				siapJalan()
				enable_move = 0;
				break;
			};
		break;
		//===================================== 2  =================================
		case 2:
			siapJalan():
			while(enable_move = 1){
				jalan2(100,1000)
				enable_move = 0;
				break;
			};
			siapJalan();
		break;
		//===================================== 3  =================================
		case 3:
			siapJalan();
		break;
		//===================================== 4  =================================
		case 4 : //hadap kiri
			//stabilizer2(2,-50,-50,0,0,-30,-30);
			while(enable_move = 1){
				putar_kiri(30000);
				enable_move = 0;
				break;
			};
			siapJalan();
			//resetStabilizer(2);
		break;
		//===================================== 5  =================================
		case 5 : //hadap kanan
			//stabilizer2(2,-50,-50,0,0,-30,-30);
			while(enable_move=1){
				putar_kanan(30000);
				enable_move = 0;
				break;
			};
			siapJalan();
			//resetStabilizer(2);
		break;
		//===================================== 6  =================================
		case 6 ://geser kiri
				//stabilizer2(2,-35,-35,0,0,-30,-30);
			while(enable_move=1){
				geser_kiri(30000);
				enable_move = 0;
				break;
			}
			siapJalan();
			//resetStabilizer(2);
		break;
		//===================================== 7  =================================
		case 7 : //geser kanan
			//stabilizer2(2,-35,-35,0,0,-30,-30);
			while(enable_move=1){geser_kanan(30000);
				enable_move = 0;
				break;
			}
			siapJalan();
			//resetStabilizer(2);
		break;
		//===================================== 8  =================================
		case 8 : //maju
			//setParameter(-15,15,3,-3);
			//jalan(300,16700); //pengulangan ada di voidnya
			//setParameter(-35,-35,-30,-30);//-35,-30//-35,-24
        	while(enable_move = 1){
				jalan1(100,10000); //fase start
				jalan2(100,10000);
				jalan2(100,12000);
				jalan2(100,14000);
				//stabilizer1(1,(serY-512),0.1,0.1,0,0,0,0);
				jalan2(100,13500);
				//resetStabilizer(1);
				sleep(5);
				jalan2(100,14000);
				jalan2(100,12000);
				jalan2(100,10000);
				jalan3(100,15500); //fase ending
				siapJalan();
				enable_move = 0;
				break;
			}
			//resetParameter();
		break;
		//===================================== 9  =================================
		case 9 : //tendang kiri
			while(enable_move = 1){
				Lshoot();
				siapJalan();
			}
		break;
		//===================================== 10 =================================
		case 10 : //tendang kanan
            while(enable_move = 1){
				Rshoot();
				siapJalan();
			}
		break;
		//===================================== 11 =================================
		case 11 : //spin kiri
			while(enable_move = 1){
				spin_kiri(30000);
				enable_move = 0;
				break;
			}
			siapJalan();
		break;
		//===================================== 12 =================================
		case 12 : //spin kanan
			while(enable_move = 1){
				spin_kanan(30000);
				enable_move = 0;
				break;
			}
            siapJalan();
		break;
		//===================================== 13 =================================
		case 13: //sprint
			//-20,-20,-10,-10
			//setParameter(-50,-50,-40,-40);
        	//jalan(150,12000); //pengulangan ada di voidnya
            //resetParameter();
			siapJalan();
		break;
		//===================================== 14 =================================
		case 14 : //dribble
			//setParameter(-15,15,3,-3);
        	//jalan(300,16700); //pengulangan ada di voidnya
			//setParameter(-35,-35,-30,-30);
        	while(enable_move = 1){
				jalan1(100,10000); //fase start
				jalan2(100,10000);
				jalan2(100,12000);
				jalan2(100,14000);
				//stabilizer1(1,(serY-512),0.1,0.1,0,0,0,0);
				jalan2(100,15500);
				//resetStabilizer(1);}
				jalan2(100,14000);
				jalan2(100,12000);
				jalan2(100,10000);
				jalan3(100,15500); //fase ending
				siapJalan();
				enable_move = 0;
				break;
			}
			//resetParameter();
		break;
		//===================================== 15 =================================
		case 15: //tangkap depan
			//while(EnableMove){putar_kiri(30000);}
			siapJalan();
		break;
		//===================================== 16 =================================
		case 16: //tangkap kiri
			//while(EnableMove){putar_kiri(30000);}
			siapJalan();
		break;
		//===================================== 17 =================================
		case 17: //tangkap kanan
			//while(EnableMove){putar_kiri(30000);}
			siapJalan();
		break;
		//===================================== 18 =================================
		case 18: //bangun depan
        	while(enable_move = 1){
				bangun_depan();
				siapJalan();
				enable_move = 0;
				break;
			}
		break;
		//===================================== 19 =================================
		case 19: //bangun belakang
        	bangun_belakang1();
			bangun_belakang2();
			bangun_belakang3();
            siapJalan();
		break;
		//===================================== 20 =================================
		case 20: //little walk
			//setParameter(-15,15,3,-3);
			//jalan(300,16700); //pengulangan ada di voidnya
			//setParameter(-35,-35,-30,-30);
        	while(enable_move = 1){
				jalan1(100,10000); //fase start
				jalan2(100,10000);
				jalan2(100,12000);
				jalan2(100,14000);
				//stabilizer1(1,(serY-512),0.1,0.1,0,0,0,0);
				jalan2(70,25000);
				//resetStabilizer(1);}
				jalan2(100,14000);
				jalan2(100,12000);
				jalan2(100,10000);
				jalan3(100,10000); //fase ending
				siapJalan();
				enable_move=0;
			}
			//resetParameter();
		break;
		//===================================== 21 =================================
		case 21:
			siapJalan();
		break;
		//===================================== 22 =================================
		case 22: //2x hadap kiri
        	putar_kiri(30000);
        	putar_kiri(30000);
			siapJalan();
		break;
		//===================================== 23 =================================
		case 23: //2x hadap kanan
			putar_kanan(30000);
			putar_kanan(30000);
			siapJalan();
		break;
		//=================================== default ==============================
		default:
			siapJalan();
		break;
		
		ready=1;
	}
}

/*==================================================================================
 *                                     .: main :.
 *================================================================================*/
int main() {
	ELP_initialize(0,1); //PORT=ttyUSB0 Baud=1Mbps
	ELP_StatReturnSet(0); //0 for no return, 1 for read only, 2 for return all
	setAllSpeed(100);
	ELP_SyncHead(512,200,0);
	ELP_SyncMove(SIT_1,1);
	printf("bismillah \n");
	printf("go international \n");
	int start = 1;

	while(1){
		if (start = 1){
			case();}
	}
	retrun(0);
}
