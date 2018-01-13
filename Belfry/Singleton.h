#pragma once

template <typename T> class Singleton {
public:
  static T& instance() {
    static T _instance;
    return _instance;
  }

protected:
  Singleton() {}
  ~Singleton() {}

public:
  Singleton(Singleton const &) = delete;
  Singleton& operator=(Singleton const &) = delete;
};

/*
class Singleton {
public:
  static Singleton& instance() {
    static Singleton _instance;
    return _instance;
  }

  Singleton(Singleton const&) = delete;
  void operator=(Singleton const&) = delete;

private:
  Singleton() {}
  Singleton(Singleton const&);
  void operator=(Singleton const&);
};
*/