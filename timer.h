#ifndef TIMER_H
#define TIMER_H


class Timer {
private:
  unsigned long lastVisit;
  unsigned long period;

public:
  Timer(unsigned long periodMs = 1000);
  bool expired();
  bool ready() const;
  void reset();
  void setPeriod(unsigned long periodMs);
  unsigned long getPeriod() const;

};


#endif