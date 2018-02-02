//
//  montecarlo.cpp
//  Lab7.3
//
//  Created by Thomas Tylek on 2/23/15.
//  Copyright (c) 2015 Thomas Tylek. All rights reserved.
//

#include "montecarlo.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float randRange();
void polarCoor(float x, float y, float &r, float &theta);

int main(void)
{
    int seed = static_cast<int>(time(0));
    srand(seed);
    float x;
    float y;
    float r;
    float theta;
    int inCircle = 0;
    float accuracy;
    cout << "Enter amount of randoms to be generated: ";
    cin >> accuracy;
    for (int i = 0; i < accuracy; i++) 
    {
        x = randRange();
        y = randRange();
        polarCoor(x, y, r, theta);
        if (r <= 1.0)
            inCircle++;
    }
    cout << "Pi estimate is " << ((inCircle/accuracy)*4) << endl;
    return 0;
}
float randRange()
{
    float n = ((float)rand()/RAND_MAX)*2-1;
    return n;
}
void polarCoor(float x, float y, float &r, float &theta)
{
    if (x < 0 && y > 0)
        theta = atan2(y,x) + 180;
    else if (x < 0 && y < 0)
        theta = atan2(y,x) + 180;
    else if (x > 0 && y < 0)
        theta = atan2(y,x) + 360;
    else
        theta = atan2(y,x);
    r = sqrt((pow(x,2.0))+(pow(y,2.0)));
}