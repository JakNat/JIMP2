//
// Created by WiktorW on 3/12/2018.
//

#include "GreatestProduct.h"
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k)
{
    vector<int> results;
    for (int i = 0; i < k; ++i) {
        results.push_back(numbers[i]);
    }
    sort(results.begin(),results.end());

   if(results.size() % 2 == 0) {
     /*  for (int v : numbers) {
          v = abs(v);
           if (v > results[0] && v > results[1]) {
               if (results[0] > results[1]) {
                   results[1] = v;
               } else {
                   results[0] = v;
               }
           } else if (v > results[0] || v > results[1]) {
               if (results[0] > results[1]) {
                   results[1] = v;
               } else {
                   results[0] = v;
               }
           }


       }
        */
       for( int i = k ; i < numbers.size(); i++){
           for (int i = 0; i < k ; i++) {
               if(results[i] < numbers[i]){
                   results[i] = numbers[i];
                   sort(results.begin(),results.end());
                   break;
               }
           }
       }
       return results[0] * results[1];
   }

}