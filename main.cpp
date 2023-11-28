#include <iostream> //cin, cout
#include <stdlib.h> //calloc, free
#include <fstream> // fstream

void swap(unsigned long long *pA, unsigned long long *pB){ //swaps the values at two addresses
    unsigned long long temp = *pA;
    *pA = *pB;
    *pB = temp;
    return;
}

void export_primes(unsigned long long a, unsigned long long b, std::string filename){

    std::ofstream list(filename); //creates new file

    unsigned long long tally = 0;

    if(a > b){ //ensures that a is the smaller of the two numbers
        swap(&a, &b);
    }
    if(b == 0){
        //deal with a range of [0, 0]
        return;
    }

    /*
    this is an implementation of the sieve of eratosthenes
    positions in the array numbers[] will represent n, and the value at the position will indicate primality
    prime numbers will be marked with 0 (false), and composite numbers will be marked with 1 (true)
    */
    bool *numbers = (bool*) calloc(b + 1, sizeof(bool));
    numbers[0] = true;
    numbers[1] = true;

    for(unsigned long long i = 2; i <= b; i++){
        if(!numbers[i]){
            tally++;
            list << i << "\n";
            for(unsigned long long j = i * 2; j <= b; j += i){
                numbers[j] = true;
            }
        }
    }

    list << "total primes = " << tally;

    free(numbers);
    list.close();

    return;
}

int main(){

    unsigned long long a, b;
    std::string filename;

    std::cout << "---Prime Exporter---\nThis program uses the sieve of Eratosthenes to export a list of prime numbers to a file.\n\n";

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter filename: ";
    getline(std::cin >> std::ws, filename);

    export_primes(a, b, filename);

    std::cout << "\nPrimes exported.\n";

    return 0;
}
