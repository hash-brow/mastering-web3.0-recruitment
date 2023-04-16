# Recruitment Task - Mastering Web3.0

## Tasks to accomplish:
1. Create an object called Car with a given list of attributes and methods.
2. Design and test the object

## Attributes:
1. make(string) : Make of the Car
2. model(string) : Model of the Car
3. year(int) : Year it was made in
4. speed_x(int) : Speed in the x direction (can be negative)
5. speed_y(int) : Speed in the y direction (can be negative)
6. speed_z(int) : Speed in the z direction (can be negative)
7. x(int), y(int), z(int) : Coordinates of the car in 3D space

## Methods:
1. void accelerate(int, int, int) : increases speed of the car by given amounts
2. void brake(int, int, int) : decreases speed of the car by given amounts
3. void move(int) : updates the movement of a car for given amount of time assuming a constant speed in the entire interval
4. bool detect_collision(car2) : detects whether the car has collided with another car at an instant
5. pair<bool, double> time_to_collision(car2) : detects whether the car will collide with another car, and if it will, in how much time will it take for the two cars to collide

The Car class has been implemented in the header file Car.h to make for easier testing using the file test.cpp and various test scripts

## Implementation Details
1. time_to_collision(car2) : It takes into account the fact that the speed in a direction for both cars might be the same, and therefore ignores that direction provided that the coordinates of both cars in that direction are the same. 