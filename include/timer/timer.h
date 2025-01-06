#pragma once

#include <chrono>
#include <print>

namespace lap {

struct Timer {
  private:
    std::chrono::time_point< std::chrono::high_resolution_clock > start, end;

  public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }

    void stop() { end = std::chrono::high_resolution_clock::now(); }

    // Returns elapsed time in milliseconds
    double elapsed() {
        using namespace std::chrono;
        stop();
        return duration_cast< milliseconds >(end - start).count();
    }

    void reset() { start = std::chrono::high_resolution_clock::now(); }

    ~Timer() = default;
};

struct TimerRAII : public Timer {
  public:
    TimerRAII() : Timer() {}

    ~TimerRAII() {
        this->stop();
        double elapsed_milliseconds = this->elapsed();
        std::println("Elapsed time: {}ms", elapsed_milliseconds);
    }
};

} // namespace lap
