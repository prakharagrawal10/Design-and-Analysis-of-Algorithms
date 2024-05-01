#include <iostream>
#include <chrono>

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    int count = 0;
    for (int i = 1; i <= 1000000000; ++i) {
        count++;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << "Counting to one million took " << elapsed_seconds.count() << " seconds." << std::endl;

    return 0;
}
