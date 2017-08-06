#include "PID.h"
#include <stdlib.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double init_Kp, double init_Ki, double init_Kd) {
    //this->Kp = Kp;
    Kp = init_Kp;
    Ki = init_Ki;
    Kd = init_Kd;
    d_error = 0.0;
    p_error = 0.0;
    i_error = 0.0;
    mean_error = 0.0;
    samples = 0;
}

void PID::UpdateError(double cte) {
    samples += 1;
    d_error = cte - p_error;  // This assumes all time intervals are equal
    p_error = cte;
    i_error += cte;
    // this calculates mean of error on each new sample online
    mean_error = mean_error + (abs(cte) - mean_error) / samples;
}

double PID::TotalError() {
    return p_error * Kp + i_error * Ki + d_error * Kd;
}