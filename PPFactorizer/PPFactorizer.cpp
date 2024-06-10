#include "PPFactorizer.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <unordered_map>

using namespace std;

vector<vector<long long>> factors;

void factorize_subrange(long long number, int start, int end, vector<long long>& local_factors) {
    for (int i = start; i <= end; ++i) {
        while (number % i == 0 && number > 1) {
            local_factors.push_back(i);
            number /= i;
        }
    }
}

size_t get_max_size_subset_index() {
    size_t max_index = 0;
    size_t max_size = 0;
    for (size_t i = 0; i < factors.size(); ++i) {
        if (factors[i].size() > max_size) {
            max_index = i;
            max_size = factors[i].size();
        }
    }
    return max_index;
}

unordered_map<long long, int> countElements(const vector<long long>& vec) {
    unordered_map<long long, int> hashtable;
    for (const long long& element : vec) {
        hashtable[element]++;
    }
    return hashtable;
}

vector<long long> getExtraElements(const unordered_map<long long, int>& hashtable1, const unordered_map<long long, int>& hashtable2) {
    vector<long long> extraElements;
    for (const auto& pair : hashtable2) {
        long long element = pair.first;
        int count2 = pair.second;
        int count1 = (hashtable1.find(element) != hashtable1.end()) ? hashtable1.at(element) : 0;
        if (count2 > count1) {
            for (int i = 0; i < count2 - count1; ++i) {
                extraElements.push_back(element);
            }
        }
    }
    return extraElements;
}

void parallel_prime_factorization(long long number, int num_threads) {
    long long sqrt_number = (long long)sqrt(number);
    factors = vector<vector<long long>>(num_threads);

#pragma omp parallel num_threads(num_threads)
    {
        vector<long long> local_factors;
#pragma omp for schedule(dynamic)
        for (int i = 2; i <= sqrt_number; ++i) {
            long long temp_number = number;
            while (temp_number % i == 0 && temp_number > 1) {
                local_factors.push_back(i);
                temp_number /= i;
            }
        }

        int thread_id = omp_get_thread_num();
        factors[thread_id] = local_factors;
    }
}

vector<long long> reduce_factors() {
    vector<long long> all_factors;
    int max_size_index = (int)get_max_size_subset_index();
    all_factors = factors[max_size_index];
    unordered_map<long long, int> max_size_subset_elements_count = countElements(all_factors);
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i == max_size_index) continue;
        vector<long long>& subset = factors[i];
        unordered_map<long long, int> local_subset_count = countElements(subset);
        vector<long long> extras = getExtraElements(max_size_subset_elements_count, local_subset_count);
        if (!extras.empty()) {
            all_factors.insert(all_factors.end(), extras.begin(), extras.end());
        }
    }
    return all_factors;
}

void remove_divisibles(vector<long long>& factors) {
    for (auto it = factors.begin(); it != factors.end(); ++it) {
        auto inner_it = it;
        ++inner_it;
        while (inner_it != factors.end()) {
            if (*inner_it % *it == 0 && *inner_it != *it) {
                inner_it = factors.erase(inner_it);
            }
            else {
                ++inner_it;
            }
        }
    }
}

void print_factors(const vector<long long>& factors) {
    for (unsigned long long factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        long long number;
        cout << "Enter the number to factorize: ";
        cin >> number;
        int threads;
        cout << "Enter the number of threads: ";
        cin >> threads;
        double start_time = omp_get_wtime();
        parallel_prime_factorization(number, threads);
        double end_time = omp_get_wtime();
        vector<long long> prime_factors = reduce_factors();
        if (!prime_factors.empty()) {
            sort(prime_factors.begin(), prime_factors.end());
            remove_divisibles(prime_factors);
            end_time = omp_get_wtime();
            cout << "Prime factors of " << number << " are: ";
            print_factors(prime_factors);
            cout << "Execution time: " << end_time - start_time << " seconds\n";
        }
        else {
            cout << "The number " << number << " is a prime number\n";
            cout << "Execution time: " << end_time - start_time << " seconds\n";
        }
        cout << "\n";
        factors.clear();
    }
    return 0;
}
