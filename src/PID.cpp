/*
* @Author: Udacity
* @Last Modified by:   debasis
*/

#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(const double Kp, const double Ki, const double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error_ = 0.0;
  i_error_ = 0.0;
  d_error_ = 0.0;
}

void PID::UpdateError(const double cte) {
  d_error_ = cte - p_error_;
  p_error_ = cte;
  i_error_ += cte;
}

double PID::TotalError() {
  return -(Kp_*p_error_ + Ki_*i_error_ + Kd_*d_error_);
}
