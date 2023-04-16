//
// Created by divyansh on 16-04-2023.
//

#ifndef MASTERING_WEB3_0_RECRUITMENT_CAR_H
#define MASTERING_WEB3_0_RECRUITMENT_CAR_H

#include <bits/stdc++.h>

using namespace std;

const double eps = 0.000001;

class Car {
private:
    string make, model;
    int year;
    int speed_x, speed_y, speed_z;
    int x, y, z;

public:

    Car(string make, string model, int year, int speed_x, int speed_y, int speed_z, int x, int y, int z) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->speed_x = speed_x;
        this->speed_y = speed_y;
        this->speed_z = speed_z;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void accelerate(int increment_x, int increment_y, int increment_z){
        speed_x += increment_x;
        speed_y += increment_y;
        speed_z += increment_z;
    }

    void brake(int decrement_x, int decrement_y, int decrement_z){
        speed_x -= decrement_x;
        speed_y -= decrement_y;
        speed_z -= decrement_z;
    }
    void move(int time){
        x += speed_x * time;
        y += speed_y * time;
        z += speed_z * time;
    }

    bool detect_collision(const Car& car) const{
        if(x == car.x && y == car.y && z == car.z) {
            return true;
        }

        return false;
    }

    pair<bool, int> time_to_collision(const Car& car) const{
        double time_x, time_y, time_z;
        bool ignore_x = false, ignore_y = false, ignore_z = false;

        if(car.x != x && speed_x == car.speed_x) {
            ignore_x = true;
            return {false, -1};
        }

        if(car.y != y && speed_y == car.speed_y) {
            ignore_y = true;
            return {false, -1};
        }

        if(car.z != z && speed_z == car.speed_z) {
            ignore_z = true;
            return {false, -1};
        }

        if(!ignore_x) time_x = (double) (car.x - x) / (double) (speed_x - car.speed_x);
        if(!ignore_y) time_y = (double) (car.y - y) / (double) (speed_y - car.speed_y);
        if(!ignore_z) time_z = (double) (car.z - z) / (double) (speed_z - car.speed_z);

        vector<double> consider;

        if(!ignore_x) consider.push_back(time_x);
        if(!ignore_y) consider.push_back(time_y);
        if(!ignore_z) consider.push_back(time_z);

        bool colliding = true;

        for(double t1 : consider)
            for(double t2 : consider)
                if(abs(t1 - t2) > eps)
                    colliding = false;

        if(colliding)
            return {true, time_x};

        return {false, -1};
    }
};

#endif //MASTERING_WEB3_0_RECRUITMENT_CAR_H