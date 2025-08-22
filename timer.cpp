#include "Arduino.h"
#include "timer.h"

Timer::Timer(unsigned long periodMs)
  : lastVisit(lastVisit), period(periodMs) {}


bool Timer::expired(){
  if((millis() - lastVisit) >= period){
    lastVisit = millis();
    return true;
  }
  return false;
}

bool Timer::ready() const{
  return ((millis() - lastVisit) >= period);
}

void Timer::reset(){
  lastVisit = millis();
}

void Timer::setPeriod(unsigned long periodMs){
  period = periodMs;
}

unsigned long Timer::getPeriod() const{
  return period;
}