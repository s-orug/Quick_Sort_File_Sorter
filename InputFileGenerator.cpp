#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  int sizes[] = {10, 100, 1000};
  std::string text[] = {"ten", "hundread", "thousand"};
  std::string pre_filename = "input_";

  for (int l = 0; l < (int)(sizeof(sizes) / sizeof(int)); ++l) {
    for (int i = 0; i < 25; ++i) {
      std::string filename = "";

      // GENERATING ARRAY WITH RANDOM VALUES OF SIZE 'sizes[l]'

      float array[sizes[l]];
      int upper = 500, lower = -500;

      srand(time(NULL));

      for (int i = 0; i < sizes[l]; ++i) {
        float num = lower + static_cast<float>(rand()) * static_cast<float>(upper - lower) / (float)RAND_MAX;
        array[i] = num;
      }

      // FILE CREATING PROCESS
      std::stringstream ss;
      ss << sizes[l] << "_" << std::to_string(i + 1);
      filename = pre_filename + ss.str();
      std::ofstream input_file(filename);
      std::cout << filename << std::endl;

      input_file << std::fixed << std::setprecision(5);

      // WRITING TO THE FILE
      for (int s = 0; s < sizes[l] - 1; ++s) {
        input_file << array[s] << " ";
      }
      input_file << array[sizes[l] - 1];

      input_file.close();
    }
  }
  return 0;
}
