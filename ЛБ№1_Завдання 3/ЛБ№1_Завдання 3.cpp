// ЛБ№1_Завдання 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

size_t lenght(const char* msg, const size_t limit) {
    size_t value = 0;
    while (!value || value > limit) {
        cout << msg;
        cin >> value;
        cin.ignore(0x1000, '\n');
    }
    return value;
}
vector<int> create(const size_t N, int min, int max) {
    if (min > max) swap(min, max);
    vector<int> res(N);
    if (max - min < N) return res;
    uniform_int_distribution<> uid(min, max);
    mt19937 gen{ random_device()() };
    unordered_set<int> box;
    do box.insert(uid(gen)); while (box.size() != N);
    copy(box.begin(), box.end(), res.begin());
    return res;
}
int main() {
    const size_t limit = 400;
    const auto N = lenght("n: ", limit);
    auto A = create(N, -static_cast<int>(N), N);
    for (auto x : A) cout << x << ' ';
    puts("");
    auto max = *max_element(A.begin(), A.end());
    cout << "Max: " << max << '\n';
}
