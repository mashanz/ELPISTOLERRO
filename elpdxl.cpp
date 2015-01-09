/*==================================================================================
 *                                  LIBRARY
 *================================================================================*/
#include "publicjoint.cpp"
#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <dynamixel.h>
#include <termios.h>
#include <time.h>

/*==================================================================================
 *                                  getch
 *================================================================================*/
int getch(void){
  int ch;
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  ch = getchar(); /* standard getchar call */
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
  return ch; /*return received char */
}
/*==================================================================================
 *                                  communication status
 *================================================================================*/
//int id[NUM_SERVOS];
int CommStatus;

/*==================================================================================
 *                                  inisialisasi
 *================================================================================*/
void ELP_initialize(int portNum,int baudnum){
    /*
     * One digit of motor represents 0.3515625 degrees.
     * One degree represents 2.8444444 values of motor turn
     */
    //int GoalPos[2] = {512, 512};
    /**
     * Middle Motor limits - [ -92.109, 101.25  ]
     */
    //int GoalPosMotor2[2] = { 250, 800 };
    /**
     * Base Motor limits - [-180, 180 ];
     */
    //int GoalPosMotor1[2] = { 0, 1024 };
    /**
     * Top Motor limits - [ 77.344, 125.859 ];
     */
    //int index = 0;
    int deviceIndex = portNum; //port USBttyX
    //int Moving, PresentPos;
    //int CommStatus;
    printf( "\n\nRead/Write example for Linux\n\n" );
    ///////// Open USB2Dynamixel ////////////
    if( dxl_initialize(deviceIndex, baudnum) == 0 ){
        printf( "Failed to open USB2Dynamixel!\n" );
        printf( "Press Enter key to terminate...\n" );
        getchar();
        DXLerrCode=100+deviceIndex;//return 0;
    }
    else{
		printf( "Succeed to open USB2Dynamixel!\n" );
		DXLerrCode = 0; //anything is OK!
	}
}

/*==================================================================================
 *                                  kill
 *================================================================================*/
void ELP_kill(){
    // Close device
    dxl_terminate();
    printf( "Press Enter key to terminate...\n" );
    getchar();
    //return 0;
}
/* Printing communication result */
/*==================================================================================
 *                                  set All Speed
 *================================================================================*/
void setAllSpeed( int speed){
	dxl_write_word(BROADCAST_ID,32,speed); //Send to all ID
	dxl_write_word(31,32,0); //reset headX speed
	dxl_write_word(32,32,0); //reset headY speed	
}
/*==================================================================================
 *                                  Status
 *================================================================================*/
void PrintCommStatus(int CommStatus){
    switch(CommStatus){
        case COMM_TXFAIL:
            printf("COMM_TXFAIL: Failed transmit instruction packet!\n");
        break;

        case COMM_TXERROR:
            printf("COMM_TXERROR: Incorrect instruction packet!\n");
        break;

        case COMM_RXFAIL:
            printf("COMM_RXFAIL: Failed get status packet from device!\n");
        break;

        case COMM_RXWAITING:
            printf("COMM_RXWAITING: Now recieving status packet!\n");
        break;

        case COMM_RXTIMEOUT:
            printf("COMM_RXTIMEOUT: There is no status packet!\n");
        break;

        case COMM_RXCORRUPT:
            printf("COMM_RXCORRUPT: Incorrect status packet!\n");
        break;

        default:
            printf("This is unknown error code!\n");
        break;
	}
}
/*==================================================================================
 *                                  error
 *================================================================================*/
/** Print error bit of status packet */
void PrintErrorCode(){
    if(dxl_get_rxpacket_error(ERRBIT_VOLTAGE) == 1)
        printf("Input voltage error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_ANGLE) == 1)
        printf("Angle limit error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_OVERHEAT) == 1)
        printf("Overheat error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_RANGE) == 1)
        printf("Out of range error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_CHECKSUM) == 1)
        printf("Checksum error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_OVERLOAD) == 1)
        printf("Overload error!\n");
    if(dxl_get_rxpacket_error(ERRBIT_INSTRUCTION) == 1)
        printf("Instruction code error!\n");
}
/*==================================================================================
 *                                  sinkronisasi
 *================================================================================*/
void ELP_SyncWrite(){
	// Make syncwrite packet
	dxl_set_txpacket_id(BROADCAST_ID);
	dxl_set_txpacket_instruction(INST_SYNC_WRITE);
	dxl_set_txpacket_parameter(0, P_GOAL_POSITION_L);
	dxl_set_txpacket_parameter(1, 2);

	// ID 1-3
	dxl_set_txpacket_parameter(2+3*0, 1);
	dxl_set_txpacket_parameter(2+3*0+1, dxl_get_lowbyte(dataArray[0]+VarID[0]+VarPID[0]));
	dxl_set_txpacket_parameter(2+3*0+2, dxl_get_highbyte(dataArray[0]+VarID[0]+VarPID[0]));
	dxl_set_txpacket_parameter(2+3*1, 2);
	dxl_set_txpacket_parameter(2+3*1+1, dxl_get_lowbyte(dataArray[1]-VarID[1]-VarPID[1]));
	dxl_set_txpacket_parameter(2+3*1+2, dxl_get_highbyte(dataArray[1]-VarID[1]-VarPID[1]));
	dxl_set_txpacket_parameter(2+3*2, 3);
	dxl_set_txpacket_parameter(2+3*2+1, dxl_get_lowbyte(dataArray[2]+VarID[2]+VarPID[2]));
	dxl_set_txpacket_parameter(2+3*2+2, dxl_get_highbyte(dataArray[2]+VarID[2]+VarPID[2]));

	// ID 4-6
	dxl_set_txpacket_parameter(2+3*3, 4);
	dxl_set_txpacket_parameter(2+3*3+1, dxl_get_lowbyte(dataArray[3]-VarID[3]-VarPID[3]));
	dxl_set_txpacket_parameter(2+3*3+2, dxl_get_highbyte(dataArray[3]-VarID[3]-VarPID[3]));
	dxl_set_txpacket_parameter(2+3*4, 5);
	dxl_set_txpacket_parameter(2+3*4+1, dxl_get_lowbyte(dataArray[4]+VarID[4]+VarPID[4]));
	dxl_set_txpacket_parameter(2+3*4+2, dxl_get_highbyte(dataArray[4]+VarID[4]+VarPID[4]));
	dxl_set_txpacket_parameter(2+3*5, 6);
	dxl_set_txpacket_parameter(2+3*5+1, dxl_get_lowbyte(dataArray[5]-VarID[5]-VarPID[5]));
	dxl_set_txpacket_parameter(2+3*5+2, dxl_get_highbyte(dataArray[5]-VarID[5]-VarPID[5]));

	// ID 7-9
	dxl_set_txpacket_parameter(2+3*6, 7);
	dxl_set_txpacket_parameter(2+3*6+1, dxl_get_lowbyte(dataArray[6]+VarID[6]+VarPID[6]));
	dxl_set_txpacket_parameter(2+3*6+2, dxl_get_highbyte(dataArray[6]+VarID[6]+VarPID[6]));
	dxl_set_txpacket_parameter(2+3*7, 8);
	dxl_set_txpacket_parameter(2+3*7+1, dxl_get_lowbyte(dataArray[7]-VarID[7]-VarPID[7]));
	dxl_set_txpacket_parameter(2+3*7+2, dxl_get_highbyte(dataArray[7]-VarID[7]-VarPID[7]));
	dxl_set_txpacket_parameter(2+3*8, 9);
	dxl_set_txpacket_parameter(2+3*8+1, dxl_get_lowbyte(dataArray[8]+VarID[8]+VarPID[8]));
	dxl_set_txpacket_parameter(2+3*8+2, dxl_get_highbyte(dataArray[8]+VarID[8]+VarPID[8]));

	// ID 10-12
	dxl_set_txpacket_parameter(2+3*9, 10);
	dxl_set_txpacket_parameter(2+3*9+1, dxl_get_lowbyte(dataArray[9]-VarID[9]-VarPID[9]));
	dxl_set_txpacket_parameter(2+3*9+2, dxl_get_highbyte(dataArray[9]-VarID[9]-VarPID[9]));
	dxl_set_txpacket_parameter(2+3*10, 11);
	dxl_set_txpacket_parameter(2+3*10+1, dxl_get_lowbyte(dataArray[10]+VarID[10]+VarPID[10]));
	dxl_set_txpacket_parameter(2+3*10+2, dxl_get_highbyte(dataArray[10]+VarID[10]+VarPID[10]));
	dxl_set_txpacket_parameter(2+3*11, 12);
	dxl_set_txpacket_parameter(2+3*11+1, dxl_get_lowbyte(dataArray[11]-VarID[11]-VarPID[11]));
	dxl_set_txpacket_parameter(2+3*11+2, dxl_get_highbyte(dataArray[11]-VarID[11]-VarPID[11]));

	// ID 13-15
	dxl_set_txpacket_parameter(2+3*12, 13);
	dxl_set_txpacket_parameter(2+3*12+1, dxl_get_lowbyte(dataArray[12]+VarID[12]+VarPID[12]));
	dxl_set_txpacket_parameter(2+3*12+2, dxl_get_highbyte(dataArray[12]+VarID[12]+VarPID[12]));
	dxl_set_txpacket_parameter(2+3*13, 14);
	dxl_set_txpacket_parameter(2+3*13+1, dxl_get_lowbyte(dataArray[13]-VarID[13]-VarPID[13]));
	dxl_set_txpacket_parameter(2+3*13+2, dxl_get_highbyte(dataArray[13]-VarID[13]-VarPID[13]));
	dxl_set_txpacket_parameter(2+3*14, 15);
	dxl_set_txpacket_parameter(2+3*14+1, dxl_get_lowbyte(dataArray[14]+VarID[14]+VarPID[14]));
	dxl_set_txpacket_parameter(2+3*14+2, dxl_get_highbyte(dataArray[14]+VarID[14]+VarPID[14]));

	// ID 16-18
	dxl_set_txpacket_parameter(2+3*15, 16);
	dxl_set_txpacket_parameter(2+3*15+1, dxl_get_lowbyte(dataArray[15]-VarID[15]-VarPID[15]));
	dxl_set_txpacket_parameter(2+3*15+2, dxl_get_highbyte(dataArray[15]-VarID[15]-VarPID[15]));
	dxl_set_txpacket_parameter(2+3*16, 17);
	dxl_set_txpacket_parameter(2+3*16+1, dxl_get_lowbyte(dataArray[16]+VarID[16]+VarPID[16]));
	dxl_set_txpacket_parameter(2+3*16+2, dxl_get_highbyte(dataArray[16]+VarID[16]+VarPID[16]));
	dxl_set_txpacket_parameter(2+3*17, 18);
	dxl_set_txpacket_parameter(2+3*17+1, dxl_get_lowbyte(dataArray[17]-VarID[17]-VarPID[17]));
	dxl_set_txpacket_parameter(2+3*17+2, dxl_get_highbyte(dataArray[17]-VarID[17]-VarPID[17]));

	// ID <KEPALA>
	dxl_set_txpacket_parameter(2+3*18, HEADX);
	dxl_set_txpacket_parameter(2+3*18+1, dxl_get_lowbyte(dataArray[18]+VarID[18]+VarPID[18]));
	dxl_set_txpacket_parameter(2+3*18+2, dxl_get_highbyte(dataArray[18]+VarID[18]+VarPID[18]));
	dxl_set_txpacket_parameter(2+3*19, HEADY);
	dxl_set_txpacket_parameter(2+3*19+1, dxl_get_lowbyte(dataArray[19]-VarID[19]-VarPID[19]));
	dxl_set_txpacket_parameter(2+3*19+2, dxl_get_highbyte(dataArray[19]-VarID[19]-VarPID[19]));

	dxl_set_txpacket_length((2+1)*20+4);
	dxl_txrx_packet();

	CommStatus = dxl_get_result();
	/*
	if( CommStatus == COMM_RXSUCCESS )
	{
		PrintErrorCode();
	}
	else
	{
		PrintCommStatus(CommStatus);
	}*/
}
/*==================================================================================
 *                                  sinkronisasi kepala
 *================================================================================*/
void ELP_SyncHead(int Xpos, int Ypos, bool ActiveMove){
	dataArray[18]=Xpos;
	dataArray[19]=Ypos;
	if (ActiveMove){ELP_SyncWrite();}
}

/*==================================================================================
 *                                  sinkronisasi gerak
 *================================================================================*/
void ELP_SyncMove(int buffArrayMove[],bool ActiveMove){
	//transfer array move ke array global
	for(int xyz=0;xyz<18;xyz++)
	{dataArray[xyz]=buffArrayMove[xyz];}
	//eksekusi array global di void ELP_Syncwrite
	if (ActiveMove){ELP_SyncWrite();}
}
/*==================================================================================
 *                                  setting kecepatan
 *================================================================================*/
void ELP_setSpeedArray(int dataArray[]){
	// Make syncwrite packet
	dxl_set_txpacket_id(BROADCAST_ID);
	dxl_set_txpacket_instruction(INST_SYNC_WRITE);
	dxl_set_txpacket_parameter(0, SPEED_L);
	dxl_set_txpacket_parameter(1, 2);

	// ID 1-3
	dxl_set_txpacket_parameter(2+3*0, 1);
	dxl_set_txpacket_parameter(2+3*0+1, dxl_get_lowbyte(dataArray[0]));
	dxl_set_txpacket_parameter(2+3*0+2, dxl_get_highbyte(dataArray[0]));
	dxl_set_txpacket_parameter(2+3*1, 2);
	dxl_set_txpacket_parameter(2+3*1+1, dxl_get_lowbyte(dataArray[1]));
	dxl_set_txpacket_parameter(2+3*1+2, dxl_get_highbyte(dataArray[1]));
	dxl_set_txpacket_parameter(2+3*2, 3);
	dxl_set_txpacket_parameter(2+3*2+1, dxl_get_lowbyte(dataArray[2]));
	dxl_set_txpacket_parameter(2+3*2+2, dxl_get_highbyte(dataArray[2]));

	// ID 4-6
	dxl_set_txpacket_parameter(2+3*3, 4);
	dxl_set_txpacket_parameter(2+3*3+1, dxl_get_lowbyte(dataArray[3]));
	dxl_set_txpacket_parameter(2+3*3+2, dxl_get_highbyte(dataArray[3]));
	dxl_set_txpacket_parameter(2+3*4, 5);
	dxl_set_txpacket_parameter(2+3*4+1, dxl_get_lowbyte(dataArray[4]));
	dxl_set_txpacket_parameter(2+3*4+2, dxl_get_highbyte(dataArray[4]));
	dxl_set_txpacket_parameter(2+3*5, 6);
	dxl_set_txpacket_parameter(2+3*5+1, dxl_get_lowbyte(dataArray[5]));
	dxl_set_txpacket_parameter(2+3*5+2, dxl_get_highbyte(dataArray[5]));

	// ID 7-9
	dxl_set_txpacket_parameter(2+3*6, 7);
	dxl_set_txpacket_parameter(2+3*6+1, dxl_get_lowbyte(dataArray[6]));
	dxl_set_txpacket_parameter(2+3*6+2, dxl_get_highbyte(dataArray[6]));
	dxl_set_txpacket_parameter(2+3*7, 8);
	dxl_set_txpacket_parameter(2+3*7+1, dxl_get_lowbyte(dataArray[7]));
	dxl_set_txpacket_parameter(2+3*7+2, dxl_get_highbyte(dataArray[7]));
	dxl_set_txpacket_parameter(2+3*8, 9);
	dxl_set_txpacket_parameter(2+3*8+1, dxl_get_lowbyte(dataArray[8]));
	dxl_set_txpacket_parameter(2+3*8+2, dxl_get_highbyte(dataArray[8]));

	// ID 10-12
	dxl_set_txpacket_parameter(2+3*9, 10);
	dxl_set_txpacket_parameter(2+3*9+1, dxl_get_lowbyte(dataArray[9]));
	dxl_set_txpacket_parameter(2+3*9+2, dxl_get_highbyte(dataArray[9]));
	dxl_set_txpacket_parameter(2+3*10, 11);
	dxl_set_txpacket_parameter(2+3*10+1, dxl_get_lowbyte(dataArray[10]));
	dxl_set_txpacket_parameter(2+3*10+2, dxl_get_highbyte(dataArray[10]));
	dxl_set_txpacket_parameter(2+3*11, 12);
	dxl_set_txpacket_parameter(2+3*11+1, dxl_get_lowbyte(dataArray[11]));
	dxl_set_txpacket_parameter(2+3*11+2, dxl_get_highbyte(dataArray[11]));

	// ID 13-15
	dxl_set_txpacket_parameter(2+3*12, 13);
	dxl_set_txpacket_parameter(2+3*12+1, dxl_get_lowbyte(dataArray[12]));
	dxl_set_txpacket_parameter(2+3*12+2, dxl_get_highbyte(dataArray[12]));
	dxl_set_txpacket_parameter(2+3*13, 14);
	dxl_set_txpacket_parameter(2+3*13+1, dxl_get_lowbyte(dataArray[13]));
	dxl_set_txpacket_parameter(2+3*13+2, dxl_get_highbyte(dataArray[13]));
	dxl_set_txpacket_parameter(2+3*14, 15);
	dxl_set_txpacket_parameter(2+3*14+1, dxl_get_lowbyte(dataArray[14]));
	dxl_set_txpacket_parameter(2+3*14+2, dxl_get_highbyte(dataArray[14]));

	// ID 16-18
	dxl_set_txpacket_parameter(2+3*15, 16);
	dxl_set_txpacket_parameter(2+3*15+1, dxl_get_lowbyte(dataArray[15]));
	dxl_set_txpacket_parameter(2+3*15+2, dxl_get_highbyte(dataArray[15]));
	dxl_set_txpacket_parameter(2+3*16, 17);
	dxl_set_txpacket_parameter(2+3*16+1, dxl_get_lowbyte(dataArray[16]));
	dxl_set_txpacket_parameter(2+3*16+2, dxl_get_highbyte(dataArray[16]));
	dxl_set_txpacket_parameter(2+3*17, 18);
	dxl_set_txpacket_parameter(2+3*17+1, dxl_get_lowbyte(dataArray[17]));
	dxl_set_txpacket_parameter(2+3*17+2, dxl_get_highbyte(dataArray[17]));

	/*// ID <KEPALA>
	dxl_set_txpacket_parameter(2+3*18, HEADX);
	dxl_set_txpacket_parameter(2+3*18+1, dxl_get_lowbyte(dataArray[18]));
	dxl_set_txpacket_parameter(2+3*18+2, dxl_get_highbyte(dataArray[18]));
	dxl_set_txpacket_parameter(2+3*19, HEADY);
	dxl_set_txpacket_parameter(2+3*19+1, dxl_get_lowbyte(dataArray[19]));
	dxl_set_txpacket_parameter(2+3*19+2, dxl_get_highbyte(dataArray[19]));
	*/
	dxl_set_txpacket_length((2+1)*18+4);
	dxl_txrx_packet();

	CommStatus = dxl_get_result();
	/*
	if( CommStatus == COMM_RXSUCCESS )
	{
		PrintErrorCode();
	}
	else
	{
		PrintCommStatus(CommStatus);
	}*/
}
