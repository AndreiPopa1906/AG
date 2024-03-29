
#include "Chromosome.h"
#include "MathFunction.h"
#include <random>
#include <vector>

std::random_device random_device;
std::mt19937 random_generator(random_device());

Chromosome::Chromosome(int number_of_genes) {
    std::uniform_int_distribution<int> distribution(0, 1);

    for (int i = 0; i < number_of_genes; i++) {
        int bit = distribution(random_generator);

        if (bit == 0)
            genes.push_back('0');
        else
            genes.push_back('1');
    }
};

void Chromosome::reset_change_counter() {
    no_change_counter = 0;
}

void Chromosome::increment_change_counter() {
    no_change_counter++;
}

bool Chromosome::is_stagnant(int stagnation_threshold) {
    return no_change_counter >= stagnation_threshold;
}

void Chromosome::flip_gene(int index) {
    auto&bit = genes.at(index);

    if (bit == '0')
        bit = '1';
    else
        bit = '0';
};

unsigned long long BinaryToGray(double num)
{
    return (int)num ^ ((int)num >> 1);
}

std::vector<double> Chromosome::to_numbers(MathFunction math_function, int dimensions) {
    std::vector<double> result;
    int genes_per_dimension = genes.size() / dimensions;

    for (int d = 0; d < dimensions; d++) {
        double sum = 0.0;
        for (int i = 0; i < genes_per_dimension; i++) {
            sum = sum * 2 + (genes[d * genes_per_dimension + i] - '0');
        }
        sum = BinaryToGray(sum);
        double real_val = math_function.bounds.min +
                          sum * (math_function.bounds.max - math_function.bounds.min) /
                          (pow(2, genes_per_dimension) - 1);
        result.push_back(real_val);
    }

    return result;
};

double Chromosome::calculate_function_value(MathFunction math_function, int dimensions) {
    std::vector<double> values = to_numbers(math_function, dimensions);
    return math_function.function(values, dimensions);
}

void Chromosome::randomize() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (auto& gene : genes) { // Assuming genes is a std::string or similar container
        gene = dis(gen) + '0'; // Randomly setting each gene to '0' or '1'
    }
}

// void Chromosome::calculate_fitness(MathFunction math_function, int dimensions) {
//     fitness = fabs(math_function.global_minimum - calculate_function_value(math_function, dimensions) + 30);
// }

void Chromosome::calculate_fitness(MathFunction math_function, int dimensions) {
    fitness = calculate_function_value(math_function, dimensions);
    if(math_function.function == michalewicz.function) {
        fitness = fitness + 30;
        fitness = 1 / (fitness + 1e-6);
    }
    else {
        if(math_function.function == schwefel.function)
            fitness += 16000;
        fitness = 1.8 / (fitness + 1e-6);
    }
}


std::vector<Chromosome> Chromosome::crossover(Chromosome* parent1, Chromosome* parent2, int crossover_point,
                                              double crossover_rate) {
    std::random_device random_device;
    std::mt19937 random_generator(random_device());
    std::uniform_real_distribution<double> distribution(0, 1);

    double random1 = distribution(random_generator);
    double random2 = distribution(random_generator);

    std::vector<Chromosome> result;

    auto child1 = new Chromosome(parent1->genes.size());
    auto child2 = new Chromosome(parent2->genes.size());

    for (int i = 0; i < parent1->genes.size(); i++) {
        if (i < crossover_point) {
            child1->genes[i] = parent1->genes[i];
            child2->genes[i] = parent2->genes[i];
        }
        else {
            child1->genes[i] = parent2->genes[i];
            child2->genes[i] = parent1->genes[i];
        }
    }

    // if (random1 <= crossover_rate) {
    //     result.push_back(*child1);
    // } else {
    //     result.push_back(*parent1);
    // }
    //
    // if (random2 <= crossover_rate) {
    //     result.push_back(*child2);
    // } else {
    //     result.push_back(*parent2);
    // }

    if(random1 <= crossover_rate)
        result.push_back(*child1);
    else if( random2 <= crossover_rate)
        result.push_back(*child2);
    else result.push_back(*parent1);


    return result;
}



void Chromosome::mutate(double mutation_rate) {
    std::uniform_real_distribution<double> distribution(0, 1);

    for (int i = 0; i < genes.size(); i++) {
        double random = distribution(random_generator);

        if (random <= mutation_rate) {
            flip_gene(i);
        }
    }
}