#include <iostream>
#include <vector>
#include <algorithm>

// Strategy interface
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) const = 0;
};

// Concrete strategies
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::cout << "Using Bubble Sort" << std::endl;
        std::sort(data.begin(), data.end());
    }
};

class SelectionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::cout << "Using Selection Sort" << std::endl;
        std::sort(data.begin(), data.end());
    }
};

class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::cout << "Using Quick Sort" << std::endl;
        std::sort(data.begin(), data.end());
    }
};

// Context class
class SortingContext {
private:
    SortingStrategy* strategy;
public:
    SortingContext(SortingStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortingStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void sort(std::vector<int>& data) const {
        strategy->sort(data);
    }
};

int main() {
    // Create strategies
    BubbleSort bubbleSort;
    SelectionSort selectionSort;
    QuickSort quickSort;

    // Create context with default strategy
    SortingContext context(&bubbleSort);

    // Test sorting with default strategy
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
    context.sort(data);

    // Switch strategy to selection sort
    context.setStrategy(&selectionSort);
    context.sort(data);

    // Switch strategy to quick sort
    context.setStrategy(&quickSort);
    context.sort(data);

    return 0;
}
