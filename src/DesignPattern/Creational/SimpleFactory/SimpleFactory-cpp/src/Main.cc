#include "./computer/Computer.h"

int main() {
  Computer* appleComputer = ComputerFactory::createComputer(ComputerTypes::apple);
  Computer* ibmComputer = ComputerFactory::createComputer(ComputerTypes::ibm);
  
  appleComputer->use();
  ibmComputer->use();
  
  return 0;
}