#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  //step 4 - initial values are passed from main 
  this->Kp =Kp;
  this->Ki =Ki;
  this->Kd =Kd;
  //initial errors 
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  //parameters for twiddle
//   tol = 0.001;
//   dp = -0.01;
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  //step5
  d_error = cte - p_error;  // at this step perror is our previous cte 
  p_error = cte;
  i_error += cte;
  
  

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //step3
  return Kp*p_error + Ki*i_error + Kd*d_error;
  //return 0.0;  // TODO: Add your total error calc here!
}


// void PID::twiddle(double err, double p){
//   static double best_err = 10000;
  
//   double prev_p = p;
//   p = p+dp;
  
  
  
  