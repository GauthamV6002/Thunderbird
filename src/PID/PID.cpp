#include "../../include/PID/PID.hpp"
#include "PID.hpp"
#include "api.h"
#include <math.h>

PID::PID_System::PID_System(float error, float kp, float ki, float kd, float maxCumulativeError, float loopTime, bool holdIntegralAtEnd) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  maxCumulativeError(maxCumulativeError),
  loopTime(loopTime),
  holdIntegralAtEnd(holdIntegralAtEnd)
{};

PID::PID_System::PID_System(float error, float kp, float ki, float kd, float maxCumulativeError, float minSettleError, float minSettleTime, float timeout, float loopTime, bool holdIntegralAtEnd) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  maxCumulativeError(maxCumulativeError),
  minSettleError(minSettleError),
  minSettleTime(minSettleTime),
  timeout(timeout),
  loopTime(loopTime),
  holdIntegralAtEnd(holdIntegralAtEnd)
{};

float PID::PID_System::compute(float error){
  if (fabs(error) < maxCumulativeError){ // maxCumulativeError is used to prevent integral windup.
    cumulativeError += error; // CumulativeError is the integral term, or the accumulated error
  }

  if (((error>0 && prevError<0)||(error<0 && prevError>0)) && !holdIntegralAtEnd){ 
    cumulativeError = 0; 
  } // This if statement checks if the error has crossed 0, and if it has, it eliminates the integral term.

  output = kp*error + ki*cumulativeError + kd*(error-prevError);

  prevError=error;

  if(fabs(error)<minSettleError){
    timeSpentSettled += loopTime;
  } else {
    timeSpentSettled = 0;
  }

  timeSpentRunning += loopTime;

  pros::screen::print(pros::E_TEXT_MEDIUM, 8, "timeSpentSettled: %f", timeSpentSettled); 
  pros::screen::print(pros::E_TEXT_MEDIUM, 9, "run time: %f", timeSpentRunning); 

  return output;
}

bool PID::PID_System::isSettled(){
  if (timeSpentRunning>timeout && timeout != 0){
    return true;
  } // If timeout does equal 0, the move will never actually time out. Setting timeout to 0 is the 
    // equivalent of setting it to infinity.
  if (timeSpentSettled > minSettleTime){
    return true;
  }
  return false;
}

void PID::PID_System::resetSystem() {
  cumulativeError = 0;
  prevError = 0;
  output = 0;
  timeSpentSettled = 0;
  timeSpentRunning = 0;
}

void PID::PID_System::setkConstants(float kp, float ki, float kd, float maxCumulativeError) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
  this->maxCumulativeError = maxCumulativeError;
}

void PID::PID_System::setStopConditionConstants(float minSettleError, float minSettleTime, float timeout) {
  this->minSettleError = minSettleError;
  this->minSettleTime = minSettleTime;
  this->timeout = timeout;
}