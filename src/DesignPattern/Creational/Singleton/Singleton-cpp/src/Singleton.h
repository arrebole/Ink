class Singleton {
 private:
  Singleton(){};
  Singleton(const Singleton& other);

  static Singleton* _instance;
  char _data[4] = {'x', 'x', 'x', '\0'};

 public:
  char* data() { return _data; };
  // 线程不安全的单例模式
  static Singleton* Instance() {
    if (_instance == nullptr) {
      _instance = new Singleton();
    }
    return _instance;
  }
};

Singleton* Singleton::_instance = nullptr;