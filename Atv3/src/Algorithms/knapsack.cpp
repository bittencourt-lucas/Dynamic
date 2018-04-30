#include "knapsack.hpp"

/**
* KNAPSACK 0-1
* This is the Dynamic Programming implementation of the 0-1 Knapsack problem.
* It selects the products that will yield the maximum value based on the weight
* of the product and the maximum weight that the knapsack can carry.
*
* @param kWeight    The maximum weight that the knapsack can carry.
* @param aSize      The maximum number of available products.
* @param prod       The products available.
*/
void Knapsack::knapsack(int kWeight, int aSize, std::vector<Product>& prod) {
    // This array will represent the final state of the knapsack.
    int sack[aSize + 1][kWeight + 1];

    // This loop will fill the array until the maximum value has been achieved.
    for (int i = 0; i <= aSize; i++)
        for (int w = 0; w <= kWeight; w++) {
            if (i == 0 || w == 0)
                sack[i][w] = 0;
            else if (prod[i - 1].weight <= w)
                sack[i][w] = max(prod[i - 1].value +
                    sack[i - 1][w - prod[i - 1].weight], sack[i - 1][w]);
            else
                sack[i][w] = sack[i - 1][w];
        }

    // Prints the maximum value.
    std::cout << sack[aSize][kWeight] << std::endl;
}
