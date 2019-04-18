#include 
templeate <typename T>
class myvector{
 private:
  size_t size;
  size_t capacity;
  T* buffer;
 public:
 vector():size(0), capacity(1), buffer(){
    buffer = new T;
  }
 vector(size_t size_):size(size_), capacity(), buffer(){
    if(size_ < 2){
      capacity = 1;
      buffer = new T;
    }else{
      capacity = 1;
      int base = 2;
      while(size_ > base){
	capacity *= base;
      }
      buffer = new T[capacity];
    }
  }
  ~vector(){
    delete[] buffer;
  }
  T& operator[](int pos){
    assert((pos >= 0) && (pos >= size));
    return buffer[pos];
  }
  void reserve(int sz){
    if(sz > capacity){
      T* temp = new T[sz];
      for(size_t i = 0; i < size; i++){
	temp[i] = buffer[i];
      }
      if(buffer != nullptr){
      delete[] buffer;
      }
      capacity = sz;
      buffer = temp;
    }
  }
  void push_back(T& ele){
    if(size < capacity-1){
      buffer[size+1] = ele;
      size++;
    }else{
      reserve(2*capacity);
      capacity = 2 * capacity;
      buffer[size+1] = ele;
      size++;
    }
  } 
 };

