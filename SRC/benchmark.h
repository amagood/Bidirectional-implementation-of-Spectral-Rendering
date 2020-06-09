//
// Created by amagood on 2019/9/24.
//

#ifndef HW1_BENCHMARK_H
#define HW1_BENCHMARK_H

#include <chrono>

class Benchmark
{
private:
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;
    float ms;

public:
    Benchmark();

    ~Benchmark();

};

#endif //HW1_BENCHMARK_H
