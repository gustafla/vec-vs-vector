#include <iostream>
#include <vector>
#include <chrono>

const size_t N = 100000;

size_t test() {
	std::vector<size_t> vec(N);
	for (size_t i = 0; i < N; i++) {
		vec[i] = i;
	}
	int sum = 0;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = i+1; j < N; j++) {
			sum += vec[i] * vec[j];
		}
	}
	return sum;
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	size_t result = test();
	auto duration = std::chrono::high_resolution_clock::now() - start;
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	std::cout << result << std::endl << "duration was " << seconds.count() << "s " << (duration-seconds).count() << "ns" << std::endl;
}
