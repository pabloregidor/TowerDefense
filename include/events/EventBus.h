#pragma once
#include "Event.h"
#include <functional>
#include <map>
#include <typeindex>
#include <vector>

class EventBus {
public:
  template <typename E>
  void subscribe(std::function<void(const E &)> cb) {
    subscribers[typeid(E)].push_back(
        [cb](const Event &e) { cb(static_cast<const E &>(e)); });
  }

  template <typename E> void publish(const E &e) {
    auto it = subscribers.find(typeid(E));
    if (it == subscribers.end())
      return;
    for (auto &cb : it->second)
      cb(e);
  }

private:
  std::map<std::type_index, std::vector<std::function<void(const Event &)>>>
      subscribers;
};