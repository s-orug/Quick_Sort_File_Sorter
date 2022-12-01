#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <tuple>
#include <vector>

int main( void )
{
   char *stopstring;
   float x;

   std::string stri = "443.123211";

   std::stringstream ss;
   ss.precision(5);
   ss << stri;
   std::cout << ss.str() << std::endl;
   x = std::stof(ss.str(), NULL);
   printf("%f", x);
}