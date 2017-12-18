#pragma once


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