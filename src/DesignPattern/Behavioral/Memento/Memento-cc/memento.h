class Memento {
 private:
  int state;

 public:
  int getState() { 
      return state; 
    }
  void setState(int state) { 
      this->state = state; 
    }
};

class Originator {
 private:
  int state;

 public:
  void setMemento(Memento* m) { 
      this->state = m->getState(); 
    }
  Memento* CreateMemento() {
    Memento* m = new Memento();
    m->setState(this->state);
    return m;
  }
};
