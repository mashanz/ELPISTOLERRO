/*==================================================================================
 *                                  LIBRARY
 *================================================================================*/
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include "L3G.h"
#include "LSM303.h"
#include "sensor.c"
#include "i2c-dev.h"
#include <sys/time.h>
#include <pthread.h>

#define X   0
#define Y   1
#define Z   2
#define DT 0.02 // [s/loop] loop period. 20ms
#define AA 0.98 // complementary filter constant
#define A_GAIN 0.0573 // [deg/LSB]
#define G_GAIN 0.070 // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

	int  *Pacc_raw;
	int  *Pmag_raw;
	int  acc_raw[3];
	int  mag_raw[3];
	int i 				= 0;
	float AccYangle 	= 0.0;
	float AccXangle 	= 0.0;
	float AcceleroY 	= 0.0;
	float AcceleroX 	= 0.0;
	float MagOut 		= 0.0;
	float Magneto 		= 0.0;
	int batas_atas_M  	= 200;	// nilai magneto tertinggi ,arah gawang musuh
	int batas_bawah_M 	= 100;	// nilai magneto terendah  ,arah gawang musuh
	int batas_atas_S  	= 300;	// nilai magneto tertinggi ,arah gawang sendiri
	int batas_bawah_S 	= 200;	// nilai magneto terendah  ,arah gawang sendiri
	int gawang_f    	= 0; 	// nilai found or not gawang "embeded universal"
	int jatoh_depan_a	= 20;	// nilai range atas ,kondisi jatoh depan
	int jatoh_depan_b	= 10;	// nilai range bawah ,kondisi jatoh depan
	int jatoh_belakang_a= 50;	// nilai range atas ,kondisi jatoh bealakang
	int jatoh_belakang_b= 40;	// nilai range bawah ,kondisi jatoh belakang
	int jatoh_kanan_a	= 20;	// nilai range atas ,kondisi jatoh kanan
	int jatoh_kanan_b	= 10;	// nilai range bawah ,kondisi jatoh kanan
	int jatoh_kiri_a	= 30;	// nilai range atas ,kondisi jatoh kiri
	int jatoh_kiri_b	= 40;	// nilai range bawah ,kondisi jatoh kiri
	int enable_move		= 0;	//

/*==================================================================================
 *                                  enable accelero
 *================================================================================*/
void enableACC(){
	//  z,y,x axis enabled , 100Hz data rate
	writeAccReg(LSM303_CTRL_REG1_A, 0b01010111);
	// +/- 8G full scale: FS = 10 on DLHC, high resolution output mode
	writeAccReg(LSM303_CTRL_REG4_A, 0b00101000);
}
/*==================================================================================
 *                                  enable magneto
 *================================================================================*/
void enableMAG(){
	writeMagReg(LSM303_MR_REG_M, 0x00);
}
/*==================================================================================
 *                                  read magneto
 *================================================================================*/
void bacaACC(){
	readACC(Pacc_raw);
	AccXangle = (float) (atan2(*(acc_raw+1),*(acc_raw+2))+M_PI)*RAD_TO_DEG;
	AccYangle = (float) (atan2(*(acc_raw+2),*acc_raw)+M_PI)*RAD_TO_DEG;
	//printf ("   AccXangle \e[m %7.3f \t --- AccYangle %7.3f \t \n",AccYangle,AccXangle);
	AcceleroX = AccXangle; //Output accelero for x angle "embeded universal"
	AcceleroY = AccYangle; //output accelero for y angle "embeded universal"
	usleep(100000);		
}
/*==================================================================================
 *                                  Read magneto
 *================================================================================*/
void bacaMAG(){
	readMAG(Pmag_raw);
	MagOut = (float) (atan2(*(mag_raw+1),*(mag_raw))+M_PI)*RAD_TO_DEG;
	//printf ("   Output Magneto \e[m %7.3f \t \n",MagOut);
	usleep(100000);
	Magneto = MagOut; //output magneto "embeded universal"
}
/*==================================================================================
 *                                  jatohRobot
 *================================================================================*/
void jatohRobot(){
	//bacaACC();
	//jatoh depan
	if (jatoh_depan_b <= AcceleroX && AcceleroX <= jatoh_depan_a){
		enable_move = 0 ;
		printf("jatoh depan ,maka bangun depan panggil \n");
		//bangun_depan();  //pangil void bangun depan dari ELPmove.c
	}
	//jatoh belakang
	else if (jatoh_belakang_b <= AcceleroX && AcceleroX <= jatoh_belakang_a){
		enable_move = 0	;
		printf("jatoh belakang,maka bangun belakang \n");
		//bangun_belakang();   //panggil void bangun belakang dari ELPmove.c
	}
	//jatoh kiri
	else if (jatoh_kiri_b <= AcceleroY && AcceleroY <= jatoh_kiri_a){
		enable_move	= 0 ;
		printf("jatoh kiri,maka bangun kiri \n");
		//bangun_kiri();   //panggil void bangun belakang dari ELPmove.c
	}
	//jatoh kiri
	else if (jatoh_kanan_b <= AcceleroY && AcceleroY <= jatoh_kanan_a){
		enable_move	= 0;
		printf("jatoh kanan,maka bangun kanan \n");
		//bangun_kanan();   //panggil void bangun belakang dari ELPmove.c
	}
}
/*==================================================================================
 *                                  cekGawang
 *================================================================================*/
void cekGawang(){
	//bacaMAG();
	if (batas_bawah_M < MagOut && MagOut < batas_atas_M){
		printf("gawang musuh \n");
		gawang_f=1; //cek gawang "embeded universal"
	}
	else if (batas_bawah_S < MagOut && MagOut < batas_atas_S){
		printf("gawang sendiri \n");
		gawang_f=2; //cek gawang "embeded universal"
	}
	else{
		printf("gawang not found \n");
		gawang_f=0;	//cek gawang "embeded universal"
	}
}
/*==================================================================================
 *                                 .: main :.
 *================================================================================*/
void ELPsense(){
	Pacc_raw=acc_raw;
	Pmag_raw=mag_raw;
	
	char filename[20];
	sprintf(filename, "/dev/i2c-%d", 1);
	file = open(filename, O_RDWR);
	if (file<0) {
		printf("Unable to open I2C bus! \n");
		exit(1);
	}
	printf("I2C Openned \n");
	enableACC();
	enableMAG();
	while(1){
		enable_move = 1	;
		bacaACC();
		bacaMAG();
	}
	return 0;
}