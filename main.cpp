//
//  main.cpp
//  benchmarkMaker.cpp
//
//  Created by Earl Tankard, Jr. on 2/1/20.
//  Copyright © 2020 Earl Tankard, Jr. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;

// Global Variable Declarations
typedef chrono::high_resolution_clock Clock;
float int_microseconds       = NULL;
float float_microseconds     = NULL;
float memory_microseconds    = NULL;
float hardDrive_microseconds = NULL;

// Function Declaration
void intOpBenchmark();
void floatOpBenchmark();
void memoryOpBenchmark();
void hardDriveOpBenchmark();

// Main
int main() {
    intOpBenchmark();
//    floatOpBenchmark();
//    memoryOpBenchmark();
//    hardDriveOpBenchmark();
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // //
void intOpBenchmark() {
    auto int_t1 = Clock::now();
    const unsigned int n = 2;
    
    for(unsigned long long int i = 0; i < pow(10,11); i++)     {n+n;}
    for(unsigned long long int i = 0; i < 5 * pow(10,10); i++) {n*n;}
    for(unsigned long long int i = 0; i < 2 * pow(10,10); i++) {n/n;}
    
    auto int_t2 = Clock::now();

    int_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(int_t2 - int_t1).count();

    
}
// // // // // // // // // // // // // // // // // // // // // // // //

void floatOpBenchmark() {
   
}
