#include <benchmark/benchmark.h>

static constexpr unsigned SIZE = 1024;
static constexpr unsigned MASK = SIZE - 1;

static void BM_Mod(benchmark::State& state) {
    unsigned x = 0;
    for (auto _ : state) {
        benchmark::DoNotOptimize(x = x % SIZE);
    }
}
BENCHMARK(BM_Mod);

static void BM_Mask(benchmark::State& state) {
    unsigned x = 0;
    for (auto _ : state) {
        benchmark::DoNotOptimize(x = x & MASK);
    }
}
BENCHMARK(BM_Mask);

BENCHMARK_MAIN();

