#include <vector>

class Observer {
 public:
  virtual void update() = 0;
};

class Monitor: public Observer {
 public:
  virtual void update(){
    printf("is update");
  };
};

class Subject {
 private:
  std::vector<Observer*> observers;

 public:
  virtual void Attact(Observer* observer) {
      this->observers.push_back(observer);
  }

  virtual void Notify() {
    for (auto observer : observers) {
      observer->update();
    }
  }
};

