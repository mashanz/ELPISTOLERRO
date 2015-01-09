#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H
#include <fstream> 
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* GPIO Class
 * Purpose: Each object instantiated from this class will control a GPIO pin
 * The GPIO pin number must be passed to the overloaded class constructor
 */
class GPIOClass
{
public:
    GPIOClass();  // create a GPIO object that controls GPIO4 (default
    GPIOClass(string x); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    int export_gpio(); // exports GPIO
    int unexport_gpio(); // unexport GPIO
    int setdir_gpio1(string dir); // Set GPIO Direction
    int setval_gpio1(string val); // Set GPIO Value (putput pins)
    int getval_gpio1(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio2(string dir); // Set GPIO Direction
    int setval_gpio2(string val); // Set GPIO Value (putput pins)
    int getval_gpio2(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio3(string dir); // Set GPIO Direction
    int setval_gpio3(string val); // Set GPIO Value (putput pins)
    int getval_gpio3(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio4(string dir); // Set GPIO Direction
    int setval_gpio4(string val); // Set GPIO Value (putput pins)
    int getval_gpio4(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio5(string dir); // Set GPIO Direction
    int setval_gpio5(string val); // Set GPIO Value (putput pins)
    int getval_gpio5(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio6(string dir); // Set GPIO Direction
    int setval_gpio6(string val); // Set GPIO Value (putput pins)
    int getval_gpio6(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio7(string dir); // Set GPIO Direction
    int setval_gpio7(string val); // Set GPIO Value (putput pins)
    int getval_gpio7(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio8(string dir); // Set GPIO Direction
    int setval_gpio8(string val); // Set GPIO Value (putput pins)
    int getval_gpio8(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio9(string dir); // Set GPIO Direction
    int setval_gpio9(string val); // Set GPIO Value (putput pins)
    int getval_gpio9(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio10(string dir); // Set GPIO Direction
    int setval_gpio10(string val); // Set GPIO Value (putput pins)
    int getval_gpio10(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio11(string dir); // Set GPIO Direction
    int setval_gpio11(string val); // Set GPIO Value (putput pins)
    int getval_gpio11(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio12(string dir); // Set GPIO Direction
    int setval_gpio12(string val); // Set GPIO Value (putput pins)
    int getval_gpio12(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio13(string dir); // Set GPIO Direction
    int setval_gpio13(string val); // Set GPIO Value (putput pins)
    int getval_gpio13(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio14(string dir); // Set GPIO Direction
    int setval_gpio14(string val); // Set GPIO Value (putput pins)
    int getval_gpio14(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio15(string dir); // Set GPIO Direction
    int setval_gpio15(string val); // Set GPIO Value (putput pins)
    int getval_gpio15(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio16(string dir); // Set GPIO Direction
    int setval_gpio16(string val); // Set GPIO Value (putput pins)
    int getval_gpio16(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio17(string dir); // Set GPIO Direction
    int setval_gpio17(string val); // Set GPIO Value (putput pins)
    int getval_gpio17(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio18(string dir); // Set GPIO Direction
    int setval_gpio18(string val); // Set GPIO Value (putput pins)
    int getval_gpio18(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio19(string dir); // Set GPIO Direction
    int setval_gpio19(string val); // Set GPIO Value (putput pins)
    int getval_gpio19(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio20(string dir); // Set GPIO Direction
    int setval_gpio20(string val); // Set GPIO Value (putput pins)
    int getval_gpio20(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio21(string dir); // Set GPIO Direction
    int setval_gpio21(string val); // Set GPIO Value (putput pins)
    int getval_gpio21(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio22(string dir); // Set GPIO Direction
    int setval_gpio22(string val); // Set GPIO Value (putput pins)
    int getval_gpio22(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio23(string dir); // Set GPIO Direction
    int setval_gpio23(string val); // Set GPIO Value (putput pins)
    int getval_gpio23(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio24(string dir); // Set GPIO Direction
    int setval_gpio24(string val); // Set GPIO Value (putput pins)
    int getval_gpio24(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio25(string dir); // Set GPIO Direction
    int setval_gpio25(string val); // Set GPIO Value (putput pins)
    int getval_gpio25(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio26(string dir); // Set GPIO Direction
    int setval_gpio26(string val); // Set GPIO Value (putput pins)
    int getval_gpio26(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio27(string dir); // Set GPIO Direction
    int setval_gpio27(string val); // Set GPIO Value (putput pins)
    int getval_gpio27(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio28(string dir); // Set GPIO Direction
    int setval_gpio28(string val); // Set GPIO Value (putput pins)
    int getval_gpio28(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio29(string dir); // Set GPIO Direction
    int setval_gpio29(string val); // Set GPIO Value (putput pins)
    int getval_gpio29(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio30(string dir); // Set GPIO Direction
    int setval_gpio30(string val); // Set GPIO Value (putput pins)
    int getval_gpio30(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio31(string dir); // Set GPIO Direction
    int setval_gpio31(string val); // Set GPIO Value (putput pins)
    int getval_gpio31(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio32(string dir); // Set GPIO Direction
    int setval_gpio32(string val); // Set GPIO Value (putput pins)
    int getval_gpio32(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio33(string dir); // Set GPIO Direction
    int setval_gpio33(string val); // Set GPIO Value (putput pins)
    int getval_gpio33(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio34(string dir); // Set GPIO Direction
    int setval_gpio34(string val); // Set GPIO Value (putput pins)
    int getval_gpio34(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio35(string dir); // Set GPIO Direction
    int setval_gpio35(string val); // Set GPIO Value (putput pins)
    int getval_gpio35(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio36(string dir); // Set GPIO Direction
    int setval_gpio36(string val); // Set GPIO Value (putput pins)
    int getval_gpio36(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio37(string dir); // Set GPIO Direction
    int setval_gpio37(string val); // Set GPIO Value (putput pins)
    int getval_gpio37(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio38(string dir); // Set GPIO Direction
    int setval_gpio38(string val); // Set GPIO Value (putput pins)
    int getval_gpio38(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio39(string dir); // Set GPIO Direction
    int setval_gpio39(string val); // Set GPIO Value (putput pins)
    int getval_gpio39(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio40(string dir); // Set GPIO Direction
    int setval_gpio40(string val); // Set GPIO Value (putput pins)
    int getval_gpio40(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio41(string dir); // Set GPIO Direction
    int setval_gpio41(string val); // Set GPIO Value (putput pins)
    int getval_gpio41(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio42(string dir); // Set GPIO Direction
    int setval_gpio42(string val); // Set GPIO Value (putput pins)
    int getval_gpio42(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio43(string dir); // Set GPIO Direction
    int setval_gpio43(string val); // Set GPIO Value (putput pins)
    int getval_gpio43(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio44(string dir); // Set GPIO Direction
    int setval_gpio44(string val); // Set GPIO Value (putput pins)
    int getval_gpio44(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio45(string dir); // Set GPIO Direction
    int setval_gpio45(string val); // Set GPIO Value (putput pins)
    int getval_gpio45(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio46(string dir); // Set GPIO Direction
    int setval_gpio46(string val); // Set GPIO Value (putput pins)
    int getval_gpio46(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio47(string dir); // Set GPIO Direction
    int setval_gpio47(string val); // Set GPIO Value (putput pins)
    int getval_gpio47(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio48(string dir); // Set GPIO Direction
    int setval_gpio48(string val); // Set GPIO Value (putput pins)
    int getval_gpio48(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio49(string dir); // Set GPIO Direction
    int setval_gpio49(string val); // Set GPIO Value (putput pins)
    int getval_gpio49(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio50(string dir); // Set GPIO Direction
    int setval_gpio50(string val); // Set GPIO Value (putput pins)
    int getval_gpio50(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio51(string dir); // Set GPIO Direction
    int setval_gpio51(string val); // Set GPIO Value (putput pins)
    int getval_gpio51(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio52(string dir); // Set GPIO Direction
    int setval_gpio52(string val); // Set GPIO Value (putput pins)
    int getval_gpio52(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio53(string dir); // Set GPIO Direction
    int setval_gpio53(string val); // Set GPIO Value (putput pins)
    int getval_gpio53(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio54(string dir); // Set GPIO Direction
    int setval_gpio54(string val); // Set GPIO Value (putput pins)
    int getval_gpio54(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio55(string dir); // Set GPIO Direction
    int setval_gpio55(string val); // Set GPIO Value (putput pins)
    int getval_gpio55(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio56(string dir); // Set GPIO Direction
    int setval_gpio56(string val); // Set GPIO Value (putput pins)
    int getval_gpio56(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio57(string dir); // Set GPIO Direction
    int setval_gpio57(string val); // Set GPIO Value (putput pins)
    int getval_gpio57(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio58(string dir); // Set GPIO Direction
    int setval_gpio58(string val); // Set GPIO Value (putput pins)
    int getval_gpio58(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio59(string dir); // Set GPIO Direction
    int setval_gpio59(string val); // Set GPIO Value (putput pins)
    int getval_gpio59(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio60(string dir); // Set GPIO Direction
    int setval_gpio60(string val); // Set GPIO Value (putput pins)
    int getval_gpio60(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio61(string dir); // Set GPIO Direction
    int setval_gpio61(string val); // Set GPIO Value (putput pins)
    int getval_gpio61(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio62(string dir); // Set GPIO Direction
    int setval_gpio62(string val); // Set GPIO Value (putput pins)
    int getval_gpio62(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio63(string dir); // Set GPIO Direction
    int setval_gpio63(string val); // Set GPIO Value (putput pins)
    int getval_gpio63(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio64(string dir); // Set GPIO Direction
    int setval_gpio64(string val); // Set GPIO Value (putput pins)
    int getval_gpio64(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio65(string dir); // Set GPIO Direction
    int setval_gpio65(string val); // Set GPIO Value (putput pins)
    int getval_gpio65(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio66(string dir); // Set GPIO Direction
    int setval_gpio66(string val); // Set GPIO Value (putput pins)
    int getval_gpio66(string& val); // Get GPIO Value (input/ output pins)
	int setdir_gpio67(string dir); // Set GPIO Direction
    int setval_gpio67(string val); // Set GPIO Value (putput pins)
    int getval_gpio67(string& val); // Get GPIO Value (input/ output pins)
	
    string get_gpionum(); // return the GPIO number associated with the instance of an object
private:
    string gpionum; // GPIO number associated with the instance of an object
};
 
#endif
