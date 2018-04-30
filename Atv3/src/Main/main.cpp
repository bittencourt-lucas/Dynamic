#include <fstream>
#include "../Algorithms/knapsack.hpp"

int main() {
    std::vector<Product> prodAvailableM1;
    std::vector<Product> prodAvailableM2;
    int maxAvailableM1;
    int sackSizeM1;
    int maxAvailableM2;
    int sackSizeM2;
    int value;
    int weight;

    std::ifstream file;
    // Creates the items available for knapsack 1.
    file.open("../Instances/mochila01.txt");
    if (file.is_open()) {
        file >> maxAvailableM1 >> sackSizeM1;
        for (int i = 0; i < maxAvailableM1; i++) {
            file >> weight >> value;
            prodAvailableM1.push_back((Product){ value, weight });
        }
        file.close();
    }
    else
        std::cout << "ERROR: Unable to open file" << std::endl;
        
    // Creates the items available for knapsack 2.
    file.open("../Instances/mochila02.txt");
    if (file.is_open()) {
        file >> maxAvailableM2 >> sackSizeM2;
        for (int i = 0; i < maxAvailableM2; i++) {
            file >> weight >> value;
            prodAvailableM2.push_back((Product){ value, weight });
        }
        file.close();
    }
    else
        std::cout << "ERROR: Unable to open file" << std::endl;

    // Calculates the maximum value for both knapsacks.
    Knapsack* ks = new Knapsack();
    std::cout << "Maximum Value Sack 1: ";
    ks->knapsack(sackSizeM1, maxAvailableM1, prodAvailableM1);
    std::cout << "Maximum Value Sack 2: ";
    ks->knapsack(sackSizeM2, maxAvailableM2, prodAvailableM2);

    delete ks;
    return 0;
}
