/* 
 * File:   main.cpp
 * Author: ricardo
 *
 * Created on October 24, 2014, 7:56 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <omp.h>

#include "../FisioPacer2.0/Constants.h"
#include "../FisioPacer2.0/MyStdLib.h"
#include "../FisioPacer2.0/ReadMesh.h"
#include "../FisioPacer2.0/CellularAutomaton.h"
#include "../FisioPacer2.0/WriteOutput.h"
#include "../FisioPacer2.0/Stopwatch.h"
#include "../FisioPacer2.0/DataStructures.h"
#include "../FisioPacer2.0/Stopwatch.h"



/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
//    printf("FIsioPacer2.0\n");getchar();
    using namespace std;
    int   numThreads;
    double simulationTime;
    string inputFolder, outputFolder, paramFile;
    if(argc != 6)
    {
        setDefaultFolders();
        cout << "Correct usage:" << endl;
        cout << "\texecutable numthreads simulationTime InputFolder OutputFolder paramFile" << endl;
        exit(0);
    } else{
        numThreads      = atoi(argv[1]);
        simulationTime  = atof(argv[2]);
   
        //input folder
        inputFolder     = argv[3];
        //output folder
        outputFolder    = argv[4];
        paramFile       = argv[5];
    }
//    ./dist/Release/GNU-Linux-x86/fisiopacerrun 1 0.01 /home/ricardo/tese/cubo6/FibraX/malha /home/ricardo/outputFisioPacer/ /home/ricardo/tese/cubo6/malha.param
    Stopwatch watch;
    watch.start();
    int ioT=0, totalT=0;
    
    
    startCA(numThreads, simulationTime, inputFolder, outputFolder, paramFile, true, &ioT, &totalT);
    watch.stop();
    
    cout<<"Time "<< watch.timeMS() <<" "<< (watch.timeMS()/1000)/60 
    <<"'"<<(watch.timeMS()/1000)%60<<endl;

    return 0;
}

