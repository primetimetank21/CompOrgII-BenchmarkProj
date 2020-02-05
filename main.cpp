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

// Function Declarations
unsigned long long intOpBenchmark();
unsigned long long floatOpBenchmark();
unsigned long long memoryOpBenchmark();
unsigned long long hardDriveOpBenchmark();

// Main
int main() {
    // Variables to store results of each benchmark
    unsigned long long int_microseconds       = intOpBenchmark();
    unsigned long long float_microseconds     = floatOpBenchmark();
    unsigned long long memory_microseconds    = memoryOpBenchmark();
    unsigned long long hardDrive_microseconds = hardDriveOpBenchmark();

    // Output each result to console
    cout << "32-bit Integer operation benchmark:\t\t\t"    << int_microseconds       << " microseconds\n";
    cout << "32-bit Floating point operation benchmark:\t" << float_microseconds     << " microseconds\n";
    cout << "Memory benchmark:\t\t\t\t\t\t\t"              << memory_microseconds    << " microseconds\n";
    cout << "Hard drive benchmark:\t\t\t\t\t\t"            << hardDrive_microseconds << " microseconds\n";

    // Write results to a file
    ofstream results;
    results.open("/Users/earltankardjr/comporgii/benchmark_project/benchmarkmaker.cpp/benchmarkmaker.cpp/benchmark_results.txt");

    results << "Benchmark Results:\n";
    results << "32-bit Integer operation benchmark:\t\t"      << int_microseconds       << " microseconds\n"
            << "32-bit Floating point operation benchmark:\t" << float_microseconds     << " microseconds\n"
            << "Memory benchmark:\t\t\t\t"                    << memory_microseconds    << " microseconds\n"
            << "Hard drive benchmark:\t\t\t\t"                << hardDrive_microseconds << " microseconds\n";
    
    results.close();
    return 0;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // Function Definitions // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //


unsigned long long intOpBenchmark() {
    const unsigned int n = 2;
    auto int_t1 = Clock::now();         // starts timer
    
    for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}   // 10^11 additions
    for(unsigned long long int i = 0; i < pow(10,10) * 5; i++) {n*n;}   // 5 * 10^10 multiplication
    for(unsigned long long int i = 0; i < pow(10,10) * 2; i++) {n/n;}   // 2 * 10^10 division
    
    auto int_t2 = Clock::now();         // ends timer

    return chrono::duration_cast<chrono::microseconds>(int_t2 - int_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
unsigned long long floatOpBenchmark() {
    const float n = 2;
    auto float_t1 = Clock::now();       // starts timer
   
    for(unsigned long long int i = 0; i < pow(10,11)    ; i++) {n+n;}    // 10^11 additions
    for(unsigned long long int i = 0; i < pow(10,10) * 5; i++) {n*n;}    // 5 * 10^10 multiplication
    for(unsigned long long int i = 0; i < pow(10,10) * 2; i++) {n/n;}    // 2 * 10^10 division
   
    auto float_t2 = Clock::now();       // ends timer
    
    return chrono::duration_cast<chrono::microseconds>(float_t2 - float_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
unsigned long long memoryOpBenchmark() {
    const long long int _size = 5 * pow(10,5);
    int array0[_size];
    
    auto memory_t1 = Clock::now();      // starts timer

    
    for(long long int j = 0; j < pow(10,4); j++) {
        for(long long int i = 0; i < _size; i++) {
            array0[i] = 1;      // 5 * 10^9 writes of elements
        }
    }
    for(long long int j = 0; j < pow(10,4); j++) {
        for(int i : array0) {
            i;                  // 5 * 10^9 reads  of elements
        }
    }
    
    
    auto memory_t2 = Clock::now();      // ends timer
    
    return chrono::duration_cast<chrono::microseconds>(memory_t2 - memory_t1).count();
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
unsigned long long hardDriveOpBenchmark() {
    ifstream readfile;
    ofstream writefile;
    char chars[4];
    auto hardDrive_t1 = Clock::now();       // starts timer
    
    writefile.open("/Users/earltankardjr/comporgii/benchmark_project/benchmarkmaker.cpp/benchmarkmaker.cpp/benchmark.txt");
    for(unsigned long int i = 0; i < pow(10,9); i++) {
        writefile << 'a'<< 'b'<< 'c'<< ' ';     // 10^9 writes to a file (4 BYTES AT A TIME)
    }
    writefile.close();
    
    readfile.open("/Users/earltankardjr/comporgii/benchmark_project/benchmarkmaker.cpp/benchmarkmaker.cpp/benchmark.txt");
    for(unsigned long int i = 0; i < pow(10,9); i++) {
        readfile >> chars;      // 10^9 reads from a file (even though chars == 3 bytes, program still reads the space; therefore the 4th byte is being read)
    }
    readfile.close();
    
    auto hardDrive_t2 = Clock::now();       // ends timer
    
    return chrono::duration_cast<chrono::microseconds>(hardDrive_t2 - hardDrive_t1).count();
}
