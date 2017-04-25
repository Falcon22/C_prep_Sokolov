//
//  main.cpp
//  vectorr
//
//  Created by Falcon on 13.04.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include <iostream>
//#include "vector.h"
#include <vector>
#include "vector.h"
#include <math.h>
#include <algorithm>
int main(int argc, const char * argv[]) {
  
  vct::vector<int> aaa = {1, 2, 3};
  
  for (auto v: aaa) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
  

  std::cout << aaa.size() << std::endl;
  

 if  (aaa.empty()) std::cout << "Empty\n"; else
  std::cout << "Not empty\n";
  
  
  aaa.clear();
  
  std::cout << aaa.size() << std::endl;
  
  if  (aaa.empty()) std::cout << "Empty\n"; else
  std::cout << "Not empty\n";
  return 0;
}
