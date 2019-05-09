#pragma one
#include <stdio.h>
#include "./Planet.h"

// 具体的产品：地球
class Earth : public IPlanet {
 public:
  virtual void rotation() { printf("Earth rotation\n"); }
};

// 具体的产品：火星
class Mars : public IPlanet {
 public:
  virtual void rotation() { printf("Mars rotation\n"); }
};

// 具体的工厂方法
class EarthCreator : public ICreator {
 public:
  virtual IPlanet* createPlanet() { return new Earth(); };
};

// 具体的工厂方法
class MarsCreator : public ICreator {
 public:
  virtual IPlanet* createPlanet() { return new Mars(); }
};