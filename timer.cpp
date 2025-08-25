#include "WString.h"
#include "Arduino.h"
#include "timer.h"

Timer::Timer(unsigned long periodMs)
  : lastVisit(0), period(periodMs), pausedTime(0UL), paused(0) {}


bool Timer::expired(){

  if((millis() - lastVisit) >= period){
    if(!paused){
      lastVisit = millis();
      return true;
    }   
  }
  return 0;
}

bool Timer::hasElapsed() const{
  return (!paused && ((millis() - lastVisit) >= period));
}

void Timer::reset(){
  lastVisit = millis();
}

//return 1 if successfuly perfome the pause
//return 0 if pause faild
//successful pausing required following two conditions
// 1. timer must be at below value than supplied time period
// 2. paused must be false
bool Timer::pause(){

  if(!paused){
    pausedTime = millis() - lastVisit;
    paused = true;
    return 1;
  }
  else{
    return 0;
  }

}

bool Timer::isPaused(){
  return paused;
}

//return 1 if successfuly perfome the resume
//return 0 if resume faild
//to resume the pasueFlag must be at true
bool Timer::resume(){
  if(paused){
    paused = false;
    lastVisit = millis() - pausedTime;
    pausedTime = false;
    return 1;
  }else{
    return 0;
  }
}

void Timer::setPeriod(unsigned long periodMs){
  period = periodMs;
}

unsigned long Timer::getCurrentTime() const{
  if(paused){
    return pausedTime;
  }
  return (millis() - lastVisit);
}