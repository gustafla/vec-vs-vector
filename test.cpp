#include <iostream>
#include <vector>
#include <chrono>

const size_t N = 100000;

size_t testi() {
	std::vector<size_t> taulu(N);
	for (size_t i = 0; i < N; i++) {
		taulu[i] = i;
	}
	int summa = 0;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = i+1; j < N; j++) {
			summa += taulu[i] * taulu[j];
		}
	}
	return summa;
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	size_t tulos = testi();
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << tulos << " aikaa kului " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << std::endl;
}
