//
//  main.cpp
//  benchmarkMaker.cpp
//
//  Created by Earl Tankard, Jr. on 2/1/20.
//  Copyright © 2020 Earl Tankard, Jr. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
using namespace std;

// Global Variable Declarations
typedef chrono::high_resolution_clock Clock;
//double int_microseconds       = NULL;
//double float_microseconds     = NULL;
//double memory_microseconds    = NULL;
//double hardDrive_microseconds = NULL;

// Function Declaration
double intOpBenchmark();
double floatOpBenchmark();
double memoryOpBenchmark();
double hardDriveOpBenchmark();

// Main
int main() {
    double int_microseconds       = intOpBenchmark();
    double float_microseconds     = floatOpBenchmark();
    double memory_microseconds    = memoryOpBenchmark();
    double hardDrive_microseconds = hardDriveOpBenchmark();

    cout << "32-bit Integer operation benchmark:\t\t\t"    << int_microseconds       << " microseconds\n";
    cout << "32-bit Floating point operation benchmark:\t" << float_microseconds     << " microseconds\n";
    cout << "Memory benchmark:\t\t\t\t\t\t\t"              << memory_microseconds    << " microseconds\n";
    cout << "Hard drive benchmark:\t\t\t\t\t\t"            << hardDrive_microseconds << " microseconds\n";
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // //
double intOpBenchmark() {
    auto int_t1 = Clock::now();
    const unsigned int n = 2;
    
    for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}   // 10^11 additions
    for(unsigned long long int i = 0; i < 5 * pow(10,10); i++) {n*n;}   // 5 * 10^10 multiplication
    for(unsigned long long int i = 0; i < 2 * pow(10,10); i++) {n/n;}   // 2 * 10^10 division
    
    auto int_t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(int_t2 - int_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // //

double floatOpBenchmark() {
   auto float_t1 = Clock::now();
   const float n = 2;
   
   for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}    // 10^11 additions
   for(unsigned long long int i = 0; i < 5 * pow(10,10); i++) {n*n;}    // 5 * 10^10 multiplication
   for(unsigned long long int i = 0; i < 2 * pow(10,10); i++) {n/n;}    // 2 * 10^10 division
   
   auto float_t2 = Clock::now();
    
   return std::chrono::duration_cast<std::chrono::microseconds>(float_t2 - float_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // //

double memoryOpBenchmark() {
    auto memory_t1 = Clock::now();
    const long long int _size = 5 * pow(10,9);
    long int array[_size];
    
    for(unsigned long long int i = 0; i < _size; i++) {array[i] = 1;}   // 5 * 10^9 writes of elements
    for(long int i : array)                           {i;}              // 5 * 10^9 reads  of elements
    
    auto memory_t2 = Clock::now();
    
    return std::chrono::duration_cast<std::chrono::microseconds>(memory_t2 - memory_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // //

double hardDriveOpBenchmark() {
    auto hardDrive_t1 = Clock::now();
    ifstream readfile;
    ofstream writefile;
    unsigned long long int num;
    
    writefile.open("/Users/earltankardjr/comporgii/benchmark_project/benchmarkmaker.cpp/benchmarkmaker.cpp/benchmark.txt");
    for(unsigned long long int i = 0; i < pow(10,9); i++) {writefile << i << ' ';}  // 10^9 writes to a file
    writefile.close();
    
    readfile.open("/Users/earltankardjr/comporgii/benchmark_project/benchmarkmaker.cpp/benchmarkmaker.cpp/benchmark.txt");
    for(unsigned long long int i = 0; i < pow(10,9); i++) {readfile >> num;}        // 10^9 reads from a file
    readfile.close();
    
    auto hardDrive_t2 = Clock::now();
    
    return std::chrono::duration_cast<std::chrono::microseconds>(hardDrive_t2 - hardDrive_t1).count();
}
