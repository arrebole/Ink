
// Prototype 接口
class IImage {
 public:
  IImage() {}
  virtual int getData() = 0;
  virtual ~IImage() {}
  virtual IImage* Clone() = 0;
};

// 具体的原型类
class ConcreteImage : public IImage {
 private:
  int data;

 public:
  ConcreteImage(int data) { this->data = data; }
  // 拷贝构造函数
  ConcreteImage(const ConcreteImage& p) { this->data = p.data; }
  virtual int getData() { return this->data; }
  virtual IImage* Clone() { return new ConcreteImage(*this); }
};