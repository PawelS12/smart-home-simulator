#include "Observable.hpp"
#include <algorithm>

Observable::~Observable() = default;

void Observable::addObserver(IObserver* obs) {
    observers.push_back(obs);
}

void Observable::removeObserver(IObserver* obs) {
    observers.erase(sh::remove(observers.begin(), observers.end(), obs), observers.end());
}

void Observable::notifyObservers() {
    for (auto* obs : observers) {
        obs->onNotify();
    }
}
