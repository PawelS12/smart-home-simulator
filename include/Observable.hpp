#pragma once

#include "IObserver.hpp"
#include "sh_std.hpp"

class Observable {
protected:
    sh::vector<IObserver*> observers;

public:
    virtual ~Observable();

    void addObserver(IObserver* obs);
    void removeObserver(IObserver* obs);
    void notifyObservers();
};

