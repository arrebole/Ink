#include <fstream>

class Subject {
 public:
  virtual void TouchFile() = 0;
  virtual ~Subject(){};
};

class RealSubject : public Subject {
 public:
  virtual void TouchFile() {
    std::ofstream outfile("a.txt");
    if (!outfile) exit(0);

    outfile << "touch file a.txt\n";
    outfile.close();
  }
};

class Proxy : public Subject {
 public:
  virtual void TouchFile() {
    Subject* realSubject = new RealSubject();
    realSubject->TouchFile();
    delete realSubject;
  }
};
