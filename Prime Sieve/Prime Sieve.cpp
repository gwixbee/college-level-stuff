#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int main() {
    int upper_bound;
    cout << "Enter a number to find primes up to: ";
    cin >> upper_bound;

    vector<bool> is_prime(upper_bound + 1, true);

    auto start = high_resolution_clock::now();
    for (int p = 2; p * p <= upper_bound; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= upper_bound; i += p) {
                is_prime[i] = false;
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    long long seconds = duration.count() / 1000;
    long long milliseconds = duration.count() % 1000;

    int prime_count = 0;
    for (int i = 2; i <= upper_bound; ++i) {
        if (is_prime[i]) {
            prime_count++;
        }
    }

    cout << "Time taken: " << seconds << " seconds, " << milliseconds << " milliseconds" << endl;
    cout << "Number of primes found: " << prime_count << endl;

    return 0;
}