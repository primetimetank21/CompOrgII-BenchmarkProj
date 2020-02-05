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
    floatOpBenchmark();
    memoryOpBenchmark();
//    hardDriveOpBenchmark();
    cout << "32-bit Integer operation benchmark: "
         << int_microseconds   << " microseconds\n";
    cout << "32-bit Floating point operation benchmark: "
         << float_microseconds << " microseconds\n";
    cout << "Memory benchmark: "
         << memory_microseconds << " microseconds\n";
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // //
void intOpBenchmark() {
    auto int_t1 = Clock::now();
    const unsigned int n = 2;
    
    for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}   // 10^11 additions
    for(unsigned long long int i = 0; i < 5 * pow(10,10); i++) {n*n;}   // 5 * 10^10 multiplication
    for(unsigned long long int i = 0; i < 2 * pow(10,10); i++) {n/n;}   // 2 * 10^10 division
    
    auto int_t2 = Clock::now();

    int_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(int_t2 - int_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // //

void floatOpBenchmark() {
   auto float_t1 = Clock::now();
   const float n = 2;
   
   for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}    // 10^11 additions
   for(unsigned long long int i = 0; i < 5 * pow(10,10); i++) {n*n;}    // 5 * 10^10 multiplication
   for(unsigned long long int i = 0; i < 2 * pow(10,10); i++) {n/n;}    // 2 * 10^10 division
   
   auto float_t2 = Clock::now();
    
   float_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(float_t2 - float_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // //

void memoryOpBenchmark() {
    auto memory_t1 = Clock::now();
    const long long int _size = 5 * pow(10,9);
    long int array[_size];
    
    for(unsigned long long int i = 0; i < _size; i++) {array[i] = 1;}   // 5 * 10^9 writes of elements
    for(long int i : array)                           {i;}              // 5 * 10^9 reads  of elements
    
    auto memory_t2 = Clock::now();
    memory_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(memory_t2 - memory_t1).count();
}
