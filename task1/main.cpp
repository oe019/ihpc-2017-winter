// Olgun Ergüzel, 217205614, Computaitonal Physics
// other users
//

#include <iostream>

#pragma message ("please use -a or -b options for subquestions of task1.")
#pragma message ("please send -clock flag to enable clock time calculation.")

using namespace std;

//accepted commandline parameters

const string parameters[2] = {"-a", "-b"};

//global switches
static bool isA = false;
static bool isB = false;
static bool isClock = false;
//
//global variables;
string option;

//--------utilization functions

//writes given message to console or log file. // todo
void logMessage(string message){
    cout<< message << endl;
}

//-----User defined types

//initializes the system : parses commandline parameters, sets global switches for the program run mode
static class initializer{

public:static void Initialize(int arg, char** args){

        commandLineParser(arg, args);
    }

    //Parses command line parameters and sets the global switches for run mode.
private:static void commandLineParser(int arg, char** args){
        // cout<<"the parameter is"<<option<<endl;

        //no parameters provided
        if (arg == 1){
            isA = true;
            isB = true;
            logMessage("Multimode run is enabled.");
        }

        // firts argument is the file itself.
        //check argument number
        if (arg-1 > 2){
            logMessage("error.. too may arguments specified. Quitting...");
            return;
        }
        else{
            for (int i = 1 ; i < 4 ; i++){
                option = args[i];
                // if one of the parameters is -a
                if(option =="-a"){
                    logMessage("mod a is activated..");
                    isA = true;
                }
                    //if one if the parameters is -b
                else if (option == "-b"){
                    logMessage("mod b is activated..");
                    isB = true;
                }
                else{
                    cout<<"the argument " << args[i] << " is not supported yet"<<endl;
                }
            }
        }
    }
};



//--------main
int main(int arg, char** args) {

    initializer in;
    in.Initialize(arg,args);
}
