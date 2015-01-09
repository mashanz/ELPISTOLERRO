#include "GPIOClass.h"
 

 
GPIOClass::GPIOClass()
{
    this->gpionum = "4"; //GPIO4 is default
}
 
GPIOClass::GPIOClass(string gnum)
{
    this->gpionum = gnum;  //Instatiate GPIOClass object for GPIO pin number "gnum"
}
 
int GPIOClass::export_gpio()
{
    string export_str = "/sys/class/gpio/export";
    ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    if (exportgpio < 0){
        cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
    }
 
    exportgpio << this->gpionum ; //write GPIO number to export
    exportgpio.close(); //close export file
    return 0;
}
 
int GPIOClass::unexport_gpio()
{
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
    if (unexportgpio < 0){
        cout << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
    }
 
    unexportgpio << this->gpionum ; //write GPIO number to unexport
    unexportgpio.close(); //close unexport file
    return 0;
}
 
int GPIOClass::setdir_gpio1(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg3/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio1(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg3/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio1(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg3/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio2(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb19/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio2(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb19/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio2(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb19/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio3(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb18/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio3(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb18/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio3(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb18/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio4(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg6/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio4(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg6/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio4(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg6/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio5(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg5/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio5(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg5/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio5(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg5/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio6(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg4/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio6(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg4/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio6(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg4/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio7(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg1/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio7(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg1/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio7(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg1/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio8(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg2/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio8(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg2/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio8(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg2/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio9(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg0/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio9(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg0/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio9(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg0/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio10(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_ph14/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio10(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph14/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio10(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph14/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio11(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_ph15/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio11(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph15/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio11(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph15/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio12(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi6/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio12(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi6/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio12(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi6/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio13(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi5/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio13(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi5/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio13(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi5/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio14(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi4/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio14(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi4/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio14(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi4/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio15(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg11/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio15(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg11/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio15(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg11/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio16(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg10/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio16(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg10/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio16(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg10/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio17(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg9/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio17(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg9/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio17(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg9/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio18(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg8/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio18(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg8/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio18(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg8/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio19(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pg7/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio19(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg7/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio19(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pg7/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio20(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe8/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio20(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe8/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio20(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe8/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio21(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe7/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio21(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe7/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio21(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe7/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio22(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe6/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio22(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe6/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio22(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe6/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio23(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe5/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio23(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe5/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio23(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe5/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio24(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe4/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio24(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe4/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio24(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe4/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio25(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi9/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio25(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi9/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio25(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi9/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio26(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi8/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio26(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi8/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio26(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi8/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio27(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi7/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio27(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi7/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio27(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi7/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio28(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd4/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio28(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd4/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio28(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd4/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio29(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd3/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio29(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd3/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio29(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd3/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio30(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd2/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio30(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd2/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio30(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd2/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio31(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd1/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio31(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd1/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio31(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd1/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio32(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd0/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio32(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd0/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio32(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd0/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio33(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe11/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio33(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe11/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio33(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe11/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio34(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe10/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio34(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe10/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio34(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe10/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio35(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pe9/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio35(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe9/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio35(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pe9/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio36(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd12/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio36(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd12/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio36(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd12/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio37(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd11/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio37(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd11/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio37(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd11/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio38(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd10/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio38(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd10/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio38(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd10/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio39(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd9/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio39(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd9/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio39(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd9/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio40(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd8/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio40(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd8/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio40(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd8/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio41(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd7/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio41(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd7/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio41(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd7/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio42(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd6/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio42(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd6/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio42(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd6/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio43(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd5/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio43(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd5/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio43(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd5/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio44(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd20/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio44(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd20/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio44(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd20/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio45(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd19/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio45(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd19/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio45(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd19/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio46(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd18/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio46(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd18/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio46(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd18/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio47(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd17/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio47(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd17/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio47(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd17/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio48(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd16/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio48(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd16/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio48(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd16/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio49(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd15/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio49(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd15/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio49(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd15/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio50(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd14/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio50(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd14/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio50(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd14/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio51(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd13/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio51(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd13/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio51(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd13/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio52(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb2/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio52(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb2/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio52(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb2/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio53(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd25/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio53(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd25/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio53(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd25/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio54(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd24/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio54(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd24/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio54(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd24/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio55(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd26/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio55(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd26/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio55(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd26/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio56(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd27/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio56(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd27/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio56(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd27/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio57(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd23/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio57(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd23/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio57(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd23/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio58(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd22/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio58(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd22/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio58(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd22/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio59(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pd21/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio59(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd21/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio59(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pd21/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio60(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi11/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio60(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi11/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio60(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi11/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio61(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi13/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio61(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi13/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio61(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi13/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio62(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi10/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio62(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi10/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio62(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi10/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio63(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pi12/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio63(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi12/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio63(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pi12/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio64(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb13/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio64(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb13/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio64(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb13/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio65(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb11/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio65(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb11/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio65(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb11/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio66(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_pb10/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio66(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb10/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio66(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_pb10/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

int GPIOClass::setdir_gpio67(string dir)
{
 
    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "_ph7/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}
 
int GPIOClass::setval_gpio67(string val)
{
 
    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph7/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }
 
        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file 
        return 0;
}
 
int GPIOClass::getval_gpio67(string& val){
 
    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "_ph7/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }
 
    getvalgpio >> val ;  //read gpio value
 
    if(val != "0")
        val = "1";
    else
        val = "0";
 
    getvalgpio.close(); //close the value file
    return 0;
}

 
string GPIOClass::get_gpionum(){
 
return this->gpionum;
 
}
