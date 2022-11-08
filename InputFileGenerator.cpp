#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

// NON-REPEATING ARRAY

bool array_checker(int array[], int value, int size) {

  // CHECKING IF THE VALUE EXISTS IN ARRAY TO ENSURE NON-REPEATING VALUES.
  for (int i = 0; i < size; ++i) {
    if (value == array[i])
      return true;
  }
  return false;
}

int main(int argc, char **argv) {
  int sizes[] = {10, 100, 1000};
  std::string pre_filename = "input/input", filename;

  for (int l = 0; l < (int)(sizeof(sizes) / sizeof(int)); ++l) {
    for (int i = 0; i < 25; ++i) {

      // GENERATING ARRAY WITH RANDOM VALUES OF SIZE 'sizes[l]'

      int array[sizes[l]];
      int upper = 50000, lower = 0;

      for (int i = 0; i < sizes[l]; ++i) {
        int num = rand() % upper + lower;
        while (array_checker(array, num, sizes[l])) {
          num = rand() % upper + lower;
        }
        array[i] = num;
      }

      // FILE CREATING PROCESS
      std::stringstream ss;
      ss << pre_filename << "_" << sizes[l] << "_" << std::to_string(i);
      filename = ss.str();
      std::ofstream input_file(filename);
      std::cout << filename << std::endl;

      // WRITING TO THE FILE
      for (int s = 0; s < sizes[l] - 1; ++s) {
        input_file << array[s] << " ";
      }
      input_file << array[sizes[l]-1];

      input_file.close();
    }
  }
  return 0;
}