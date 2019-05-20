#include <map>
// 享元抽象类
class Flyweight {
 protected:
  char value;

 public:
  virtual char getValue() = 0;
  virtual ~Flyweight(){};
};

// 享元具体类
class ConcreteFlyweight : public Flyweight {
 public:
  ConcreteFlyweight(char val) { this->value = val; }
  virtual char getValue() { return this->value; }
};

// 享元工厂
class FlyweightFactory {
 private:
  std::map<char, Flyweight*> cache;

 public:
  Flyweight* GetFlyweight(char sign) {
    std::map<char, Flyweight*>::iterator it;
    it = this->cache.find(sign);

    if (it == this->cache.end()) {
      Flyweight* item = new ConcreteFlyweight(sign);
      this->cache.insert(std::pair<char, Flyweight*>(sign, item));
      return item;
    }
    return cache[sign];
  };

  void Clear() {
    for (auto it = cache.begin(); it != cache.end(); it++) {
      auto item = it->second;
      delete item;
    }
    this->cache.clear();
  }
};
