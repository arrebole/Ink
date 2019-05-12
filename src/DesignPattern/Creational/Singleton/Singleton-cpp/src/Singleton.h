class Singleton {
 private:
  Singleton(){};
  Singleton(const Singleton& other);

  static Singleton* uniqueInstance;
  char _data[4] = {'x', 'x', 'x', '\0'};

 public:
  char* data() { return _data; };
  // 线程不安全的单例模式
  static Singleton* Instance() {
    if (uniqueInstance == nullptr) {
      uniqueInstance = new Singleton();
    }
    return uniqueInstance;
  }
};

Singleton* Singleton::uniqueInstance = nullptr;