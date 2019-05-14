// 转换的目标接口
class ITarget {
 public:
  virtual int request() = 0;
  virtual ~ITarget(){};
};

// 需要转换的对象类接口
class IAdaptee {
 public:
  virtual int SpecificRequest() = 0;
  virtual ~IAdaptee(){};
};

//需要转换的具体类
class Asaptee : public IAdaptee {
 private:
  int data = 12;

 public:
  virtual int SpecificRequest() { return this->data; }
};

// 进行转换的适配器
class Adapter : public ITarget {
 private:
  IAdaptee* pAdaptee;

 public:
  Adapter(IAdaptee* adaptee) { this->pAdaptee = adaptee; }
  virtual int request() { return pAdaptee->SpecificRequest() + 100; }
};