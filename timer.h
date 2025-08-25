#ifndef TIMER_H
#define TIMER_H


class Timer {
private:
  unsigned long lastVisit;
  unsigned long period;
  unsigned long pausedTime;
  bool paused;

public:
  Timer(unsigned long periodMs = 1000);
  bool expired();
  bool hasElapsed() const;
  void reset();
  bool pause();
  bool isPaused();
  bool resume();
  void setPeriod(unsigned long periodMs);
  inline unsigned long getPeriod() const {return period;}
  unsigned long getCurrentTime() const;

};


#endif