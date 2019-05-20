#include <stdio.h>

class IFacade {
 public:
  virtual void TurnOff() = 0;
  virtual void PlayMusic() = 0;
  virtual ~IFacade(){};
};

class Light {
 public:
  void TurnOffLight() { printf("turn off the light\n"); }
};

class Mp3 {
 public:
  void PlayMusic() { printf("mp3 play music\n"); }
};

class Facade : public IFacade {
 private:
  Light* light;
  Mp3* mp3;

 public:
  Facade() {
    this->light = new Light();
    this->mp3 = new Mp3();
  }
  virtual void TurnOff() { this->light->TurnOffLight(); }
  virtual void PlayMusic() { this->mp3->PlayMusic(); }
  
  ~Facade() {
    delete light;
    delete mp3;
  }
};
