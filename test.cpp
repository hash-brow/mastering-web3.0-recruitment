#include "car.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Car car("Toyota", "Corolla", 2020, 0, 0, 0, 0, 0, 0);
    Car car2("Toyota", "Corolla", 2020, 1, 0, 0, -1, 0, 0);

    cout << car.time_to_collision(car2).second << '\n';

    return 0;
}
