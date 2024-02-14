#include <iostream>
#include <vector>
#include <algorithm>

// Observer interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Observable (Subject) class
class Observable {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

// Concrete Observer classes
class ConcreteObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;
    }
};

int main() {
    // Create observable object
    Observable observable;

    // Create observers
    ConcreteObserver observer1, observer2;

    // Register observers with the observable
    observable.addObserver(&observer1);
    observable.addObserver(&observer2);

    // Notify observers
    observable.notifyObservers("Hello, observers!");

    // Unregister one observer
    observable.removeObserver(&observer1);

    // Notify remaining observer
    observable.notifyObservers("Only one observer left!");

    return 0;
}
