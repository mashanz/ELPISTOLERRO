/*==================================================================================
 *                                  LIBRARY
 *================================================================================*/
#include "GPIOClass.c"

 /*==================================================================================
 *                                  .: main :.
 *================================================================================*/
void GPIOclass (void){
//-----------PENDEFINISIAN-PIN-DAN-VARIABEL-INPUT-------------
  	string input1;
    string input2;	
	string input3;	
   	GPIOClass* gpio1 = new GPIOClass("1"); 
    GPIOClass* gpio2 = new GPIOClass("2");
    GPIOClass* gpio3 = new GPIOClass("3");
	GPIOClass* gpio4 = new GPIOClass("4");
	GPIOClass* gpio5 = new GPIOClass("5");
	GPIOClass* gpio6 = new GPIOClass("6");
	GPIOClass* gpio7 = new GPIOClass("7");
	GPIOClass* gpio8 = new GPIOClass("8");
	GPIOClass* gpio9 = new GPIOClass("9");
	GPIOClass* gpio10 = new GPIOClass("10");
	GPIOClass* gpio11 = new GPIOClass("11"); 
   	GPIOClass* gpio12 = new GPIOClass("12");
	GPIOClass* gpio13 = new GPIOClass("13");
	GPIOClass* gpio14 = new GPIOClass("14");
	GPIOClass* gpio15 = new GPIOClass("15");
	GPIOClass* gpio16 = new GPIOClass("16");
	GPIOClass* gpio17 = new GPIOClass("17");
	GPIOClass* gpio18 = new GPIOClass("18");
	GPIOClass* gpio19 = new GPIOClass("19");
	GPIOClass* gpio20 = new GPIOClass("20");
	GPIOClass* gpio21 = new GPIOClass("21"); 
   	GPIOClass* gpio22 = new GPIOClass("22");
	GPIOClass* gpio23 = new GPIOClass("23");
	GPIOClass* gpio24 = new GPIOClass("24");
	GPIOClass* gpio25 = new GPIOClass("25");
	GPIOClass* gpio26 = new GPIOClass("26");
	GPIOClass* gpio27 = new GPIOClass("27");
	GPIOClass* gpio28 = new GPIOClass("28");
	GPIOClass* gpio29 = new GPIOClass("29");
	GPIOClass* gpio30 = new GPIOClass("30");
	GPIOClass* gpio31 = new GPIOClass("31"); 
  	GPIOClass* gpio32 = new GPIOClass("32");
	GPIOClass* gpio33 = new GPIOClass("33");
	GPIOClass* gpio34 = new GPIOClass("34");
	GPIOClass* gpio35 = new GPIOClass("35");
	GPIOClass* gpio36 = new GPIOClass("36");
	GPIOClass* gpio37 = new GPIOClass("37");
	GPIOClass* gpio38 = new GPIOClass("38");
	GPIOClass* gpio39 = new GPIOClass("39");
	GPIOClass* gpio40 = new GPIOClass("40");
	GPIOClass* gpio41 = new GPIOClass("41"); 
   	GPIOClass* gpio42 = new GPIOClass("42");
	GPIOClass* gpio43 = new GPIOClass("43");
	GPIOClass* gpio44 = new GPIOClass("44");
	GPIOClass* gpio45 = new GPIOClass("45");
	GPIOClass* gpio46 = new GPIOClass("46");
	GPIOClass* gpio47 = new GPIOClass("47");
	GPIOClass* gpio48 = new GPIOClass("48");
	GPIOClass* gpio49 = new GPIOClass("49");
	GPIOClass* gpio50 = new GPIOClass("50");
	GPIOClass* gpio51 = new GPIOClass("51"); 
   	GPIOClass* gpio52 = new GPIOClass("52");
	GPIOClass* gpio53 = new GPIOClass("53");
	GPIOClass* gpio54 = new GPIOClass("54");
	GPIOClass* gpio55 = new GPIOClass("55");
	GPIOClass* gpio56 = new GPIOClass("56");
	GPIOClass* gpio57 = new GPIOClass("57");
	GPIOClass* gpio58 = new GPIOClass("58");
	GPIOClass* gpio59 = new GPIOClass("59");
	GPIOClass* gpio60 = new GPIOClass("60");
	GPIOClass* gpio61 = new GPIOClass("61"); 
   	GPIOClass* gpio62 = new GPIOClass("62");
	GPIOClass* gpio63 = new GPIOClass("63");
	GPIOClass* gpio64 = new GPIOClass("64");
	GPIOClass* gpio65 = new GPIOClass("65");
	GPIOClass* gpio66 = new GPIOClass("66");
	GPIOClass* gpio67 = new GPIOClass("67");
//-------------------------------------MAIN-PROGRAM--------------------------------------------------------  
	int GPIO = 0;
	gpio11 -> export_gpio();
	gpio10 -> export_gpio();
	gpio3 -> export_gpio();
	usleep(20000);
	
	gpio11 -> setdir_gpio11("in");
	gpio10 -> setdir_gpio10("in");
	gpio3 -> setdir_gpio3("in");
	cout << " INISIALISASI " << endl;
	usleep(1000000);
    while(1){
        usleep(500000);  
        gpio11->getval_gpio11(input1);
		gpio10->getval_gpio10(input2);
		gpio3->getval_gpio3(input3);
        cout << "Current input pin1 state is " << input1 << endl;
        cout << "Current input pin2 state is " << input2 << endl;
		cout << "Current input pin3 state is " << input3 << endl;
		usleep(2000000);
		if ( input1 == "0" && input2 == "1" && input3 == "1" ){
			cout << " Executing include wifi program... " << endl;
			GPIO = 1;
       		usleep(1000000);
			break;
        }
		else if ( input1 == "1" && input2 == "0" && input3 == "1" ){
			cout << " Executing without wifi program... " << endl;
			GPIO = 2;
			usleep(1000000);
			break;
		}
		else if ( input1 == "1" && input2 == "1" && input3 == "0" ){
			cout << " Executing pinalty program... " << endl;
			GPIO = 3;
			usleep(1000000);
			break;
		}
		else {
			cout << " Nothing Happened (?) " << endl;
			GPIO = 0;
			usleep(1000000);
			break
		}
    }
    gpio11 -> unexport_gpio();
	gpio10 -> unexport_gpio();
	gpio3 -> unexport_gpio();
    cout << "Exiting....." << endl;
    usleep(1000000);
    return 0;
	break;
}
