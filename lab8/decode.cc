/*
    @file:decode.cc
  @author:Colton Savage
    @date:3/7.2023
   @brief:encoding program to encode and decode files as requested
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <fstream>
using namespace std;

//function proto
//menut display function
int displaymenu();

//key function
int keyvalue();


//encryption function
int enfile(int key);

//decryption function
int defile(int key);




int main(){
int choice, key;
key = 3; //default
do{
    displaymenu();
    cin >> choice;
    if(choice == 1){
        key = keyvalue();
    }
    else if(choice == 2){
        enfile(key);
    }
    else if(choice == 3){
        defile(key);
    }
    }while(choice != 4);
    
    return 0;
}



int displaymenu(){
    cout << "1.) Set the shift key value (default is 3)" << endl << "2.) Encrypt a file" << endl << "3.) Decrypt a file" << endl << "4.) Quit" << endl;
    cout << "select an option: ";
    return(0);
    
}


//key value function
int keyvalue(){
    int key;
    cout << "select displacement value 1-10: ";
    cin >> key;
    if(key == 1){
        cout << "you selected dis of 1" << endl;
        return(1);
    }
    else if(key == 2){
        return(2);
    }
    else if(key == 3){
        return(3);
    }
    else if(key == 4){
        return(4);
    }
    else if(key ==5){
        return(5);
    }
    else if(key == 6){
        return(6);
    }
    else if(key == 7){
        return(7);
    }
    else if(key == 8){
        return(8);
    }
    else if(key == 9){
        return(9);
    }
    else if(key == 10){
        return(10);
    }
    else{
        return(0);
    }
}


//encryption funciton
int enfile(int key){
    string filein = "";
    string fileout = "";
    ifstream inputfile;
    ofstream outputfile;
    char ch;
    char newvalue;
    cout << "enter input file name: ";
    cin >> filein;
    cout << "enter output file name: ";
    cin >> fileout;


    //input file open and check for fail
    inputfile.open(filein);
    if(inputfile.fail()){
        cout << "Error input file not found" << endl;
        return(0);
    }
    //output file open and check for fail
    outputfile.open(fileout);
    if(outputfile.fail()){
        cout << "Error file output failed" << endl;
        return(0);
    }
    //reads input file and prints to a new file
    while(!inputfile.eof()){
        inputfile.get(ch);
        newvalue = ch + key;
        //cout << newvalue;
        outputfile << newvalue;
        
    }
    //close files and ends function
    inputfile.close();
    outputfile.close();
    //cout << "completed" << endl;
    return(0);


}
//decryption function
int defile(int key){
    string fileinput = "";
    string fileoutput = "";
    ifstream inputfile;
    ofstream outputfile;
    char ch;
    char newvalue;
    
    //user input 
    cout << "enter input file name: ";
    cin >> fileinput;
    cout << "enter output file name: ";
    cin >> fileoutput;

    //opens input file and checks for error
    inputfile.open(fileinput);
    if(inputfile.fail()){
        cout << "Error file not found" << endl;
        return(0);
    }

    //opens output file and checks for error
    outputfile.open(fileoutput);
    if(outputfile.fail()){
        cout << "Error file output failed" << endl;
        return(0);
    }

    //checks through file and minus the key value
    while(!inputfile.eof()){
        inputfile.get(ch);
        newvalue = ch - key;
        //cout << newvalue;
        outputfile.put(newvalue);
    }

    //closes both files and completes function
    inputfile.close();
    outputfile.close();
    //cout << "completed" << endl;
    return(0);


}

