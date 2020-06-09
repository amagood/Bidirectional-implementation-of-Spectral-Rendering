//
// Created by amagood on 2019/9/24.
//

#include "benchmark.h"
#include <stdio.h>
#include <chrono>
Benchmark::Benchmark()
{
    start = std::chrono::high_resolution_clock::now();
}

Benchmark::~Benchmark()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    ms = duration.count() * 1000.0f;
    fprintf(stderr, "Took %fms time to run\n", ms);
}