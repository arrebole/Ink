#pragma one
#include <math.h>
#include <stdio.h>
#include <vector>
#define DBL_MAX 1.7976931348623158e+308  // max value

struct Point {
  double x, y;
};
class CloestPair {
 private:
  int size;
  char flage;
  Point* aux;     // 辅助函数
  Point* axis_x;  // x轴排序
  Point* axis_y;  // y轴排序

  void clean() {
    if (aux != nullptr) delete[] aux;
    if (axis_x != nullptr) delete[] axis_x;
    if (axis_y != nullptr) delete[] axis_y;
  };

  void merge(Point* a, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    // copy to aux array
    for (int k = lo; k <= hi; k++) {
      this->aux[k] = a[k];
    }
    if (this->flage == 'x') {
      for (int k = lo; k <= hi; k++) {
        if (i > mid)
          a[k] = aux[j++];
        else if (j > hi)
          a[k] = aux[i++];
        else if (aux[j].x < aux[i].x)
          a[k] = aux[j++];
        else
          a[k] = aux[i++];
      }
    } else if (this->flage == 'y') {
      for (int k = lo; k <= hi; k++) {
        if (i > mid)
          a[k] = aux[j++];
        else if (j > hi)
          a[k] = aux[i++];
        else if (aux[j].y < aux[i].y)
          a[k] = aux[j++];
        else
          a[k] = aux[i++];
      }
    }
  };
  void MergeSort(Point* a, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    MergeSort(a, lo, mid);
    MergeSort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
  };
  void copy(Point* from, Point* to, int len) {
    for (int i = 0; i < len; i++) {
      to[i] = from[i];
    }
  };
  double min(double a, double b) {
    if (a > b) {
      return b;
    }
    return a;
  }
  double EfficientClosestPair(Point* P, Point* Q, int _size) {
    double dminsq = DBL_MAX;

    if (_size <= 3) {
      // copy to aux array a;
      // 将点合并到一个辅助数组
      int len = _size * 2;
      Point* a = new Point[len];
      for (int i = 0; i < _size; i++) {
        a[i] = P[i];
      }
      for (int i = _size; i < len; i++) {
        a[i] = Q[i];
      }
      // Brute force method for the shortest distance
      // 蛮力法求最近距离
      for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
          double dis = pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2);
          if (dis != 0 && dis < dminsq) dminsq = dis;
        }
      }
      delete[] a;

    } else {
      int mid = _size / 2;

      Point* Pl = new Point[mid];
      Point* Ql = new Point[mid];
      Point* Pr = new Point[_size - mid];
      Point* Qr = new Point[_size - mid];

      copy(P, Pl, mid);
      copy(Q, Ql, mid);
      copy(P, Pr, _size - mid);
      copy(Q, Qr, _size - mid);

      double Dl = EfficientClosestPair(Pl, Ql, mid);
      double Dr = EfficientClosestPair(Pr, Qr, _size - mid);

      double d = min(Dl, Dr);
      double m = P[(_size / 2) - 1].x;

      std::vector<Point> vec;
      for (int i = 0; i < _size; i++) {
        if (abs(Q[i].x - m) < d) {
          vec.push_back(Q[i]);
        }
      }
      dminsq = pow(d, 2);

      int num = vec.size();
      for (int i = 0; i < num; i++) {
        int k = i + 1;
        while (k <= num - 1 && pow(vec[k].y - vec[i].y, 2) < dminsq) {
          double t = pow(vec[k].x - vec[i].x, 2) + pow(vec[k].y - vec[i].y, 2);
          dminsq = min(t, dminsq);
          k++;
        }
      }
    }

    return sqrt(dminsq);
  };

 public:
  // 构造函数
  CloestPair() {
    this->aux = nullptr;
    this->axis_x = nullptr;
    this->axis_y = nullptr;
  };

  // 析构函数
  ~CloestPair() { this->clean(); };

  // 计算最近对
  double solveCloestPair(Point* a, int _size) {
    // 先清理内存
    this->clean();

    // 分配内存
    size = _size;
    aux = new Point[size]();
    axis_x = new Point[size]();
    axis_y = new Point[size]();

    // 复制内容
    for (int i = 0; i < _size; i++) {
      axis_x[i] = a[i];
      axis_y[i] = a[i];
    }

    // 排序
    flage = 'x';
    MergeSort(axis_x, 0, _size - 1);
    flage = 'y';
    MergeSort(axis_y, 0, _size - 1);

    // 分治求最短距离
    return EfficientClosestPair(axis_x, axis_y, this->size);
  }
};