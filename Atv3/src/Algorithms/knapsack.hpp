/**
* Knapsack 0-1 algorithm implemented by Lucas Bittencourt.
*
* Knapsack 0-1 is a Dynamic Programming algorithm. Given weights and values of
* products, it choses products that will fill a "knapsack" maximizing the
* value.
*/

#ifndef KNAPSACK_HPP_
#define KNAPSACK_HPP_

#include <iostream>
#include <vector>

typedef struct Product {
    int value;
    int weight;
} Product;

class Knapsack {

public:
    // Methods
    void knapsack(int, int, std::vector<Product>&);

private:
    // Methods
    int max(int a, int b) { return (a > b) ? a : b; }

};

#endif /* KNAPSACK_HPP_ */
