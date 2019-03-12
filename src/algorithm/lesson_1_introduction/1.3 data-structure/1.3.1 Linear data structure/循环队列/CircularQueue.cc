class CircularQueue {
 private:
  int* data;
  int length;
  int capacity;
  int headIndex;
  int tailIndex;

 public:
  /** Initialize your data structure here. Set the size of the queue to be k.
   */
  CircularQueue(int k) {
    data = new int[k]();
    length = 0;
    capacity = k;
    headIndex = 0;
    tailIndex = -1;
  }
  ~CircularQueue() { delete[] data; }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return length <= 0; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return length >= capacity; }

  /** Insert an element into the circular queue. Return true if the operation
   * is successful. */
  bool enQueue(int value) {
    if (!isFull()) {
      tailIndex = (tailIndex + 1) % capacity;
      data[tailIndex] = value;
      length++;
      return true;
    }

    return false;
  }

  /** Delete an element from the circular queue. Return true if the operation
   * is successful. */
  bool deQueue() {
    if (!isEmpty()) {
      headIndex = (headIndex + 1) % capacity;
      length--;
      return true;
    }
    return false;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (isEmpty()) return -1;
    return data[headIndex];
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (isEmpty()) return -1;
    return data[tailIndex];
  }
};
