/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Miguel
 *
 * Created on 18 de noviembre de 2016, 16:37
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
 * This program generates prime numbers up to 'n'
 * Autor: Miguel Garnacho Velez
 */

int raw_input() {
    int result = 0;
    cout << "Please enter a positive integrer: ";
    cin >> result;
    cout << "\n";
    while (result < 1) {
        cout << "Please enter a positive integrer: ";
        cin >> result;
        cout << "\n";
    }
    return result;
}

/**
 * Checks if a value a its in a list b 
 * @param a int, value to check
 * @param b List to iterate
 * @return bool, if it is found or not
 */
bool in(int a, list <int> b) {
    for (auto it = begin(b); it!=end(b); ++it) {
        if (*it == a) {
            return true;
        }
    }
    return false;
}

void printList(list<int> l) {
  std::cout << "List contains:\n";
  for (auto it = begin(l); it!=end(l); ++it)
    std::cout << ' ' << *it << "\n";
}


void sieve(int num) 
{
    cout << "Creating primes form 1 to " << num << "\n";
    list<int> toSieve;
    //Create a list of size num filled of nums from 2 to num
    for (int i = 2;i < num+1;i++){
        toSieve.push_back(i);
    }
    //Main algorithm
    int loop = 1;
    for (auto it = begin(toSieve); it!=end(toSieve); ++it) {
        //if (it* == NULL) break;
        int number = *it;
        for (int multiply = 2;multiply < int(num / number) + 1;multiply++) {
            int multiple = number*multiply;
            if (in(multiple, toSieve)) {
                toSieve.remove(multiple);
            }
        }
        cout << "Loop: " << loop << "\n";
        loop++;
    }
   printList(toSieve); //Prints the list
} 

int main(int argc, char** argv) {

    bool loop = true;
    string answer;
    cout << "Eratosthenes sieve program V0.0 \n";
    while (loop) {
    int n = raw_input();
    sieve(n);
    cout << "Continue?(yes): ";
    cin >> answer;
    if (answer != "yes") {loop = false;}
    cout << "\n";
    }
    return 0;
}

