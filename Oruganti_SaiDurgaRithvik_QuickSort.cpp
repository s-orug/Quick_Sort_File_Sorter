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

bool OUTPUTFILECONTENT = false;

void swap(std::vector<float> &v, int x, int y) {
  float temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

void quicksort(std::vector<float> &vec, int L, int R) {
  int i, j, mid;
  float piv;
  i = L;
  j = R;
  mid = L + (R - L) / 2;
  piv = vec[mid];

  while (i < R || j > L) {
    while (vec[i] < piv)
      i++;
    while (vec[j] > piv)
      j--;

    if (i <= j) {
      swap(vec, i, j); // error=swap function doesnt take 3 arguments
      i++;
      j--;
    } else {
      if (i < R)
        quicksort(vec, i, R);
      if (j > L)
        quicksort(vec, L, j);
      return;
    }
  }
}

void outputFile(std::string filename, std::vector<float> array, int size) {

  std::ofstream output_file(filename);
  output_file << std::fixed << std::setprecision(5);
  for (int s = 0; s < size - 1; ++s) {
    output_file << array[s] << " ";
  }
  output_file << array[size - 1];
  output_file.close();
}

void executionTime(float time, int size) {

  std::string execution_time_file =
      "Oruganti_SaiDurgaRithvik_executionTime.txt";
  std::ofstream exec(execution_time_file, std::ios_base::app);
  std::ifstream file(execution_time_file);
  if (!(file.peek() == EOF)) {
    exec << std::endl;
  }

  exec << size << " " << time;
  exec.close();
}

int main(int argc, char **argv) {
  std::cout << std::endl;

  std::string number;

  std::cout << "\033[32mPROCESS INITIATED\033[039m" << std::endl;
  std::cout << "FILE NAME: " << argv[1] << std::endl;
  std::ifstream file(argv[1]);

  // Input File Check
  if (!file.good()) {
    std::cout << "\033[31mFILE DOES NOT EXIST\033[039m" << std::endl;
    return 0;
  }
  std::cout << "\033[32mFILE EXISTS\033[039m" << std::endl;

  std::vector<std::string> content{};
  std::stringstream ss;

  while (getline(file, number, ' ')) {
    content.push_back(number);
  }

  if (OUTPUTFILECONTENT) {
    std::cout << "FILE CONTENTS: ";
    for (auto i : content)
      std::cout << i << " ";
    std::cout << std::endl;
  }

  std::vector<float> array;
  file.close();

  //sort(array, 0, content.size() - 1, content.size());
  for (std::string i : content) {

    std::stringstream ss;
    ss << std::fixed << std::setprecision(5);
    ss << i;

    float x;
    ss >> x;
    std::cout << std::fixed << std::setprecision(5);
    array.push_back(x);
  }

  // Measuring Time
  auto start = std::chrono::high_resolution_clock::now();
  quicksort(array, 0, content.size() - 1);

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

  if (OUTPUTFILECONTENT) {
    std::cout << "SORTED CONTENTS: ";
    for (auto i : array)
      std::cout << i << " ";
    std::cout << std::endl;
  }

  std::cout << "\033[1mExecution Time: " << (float)duration.count() / 1000000
            << " milliseconds"
            << "\033[039m" << std::endl;

  // Output File
  if (argv[2]) {
    outputFile(argv[2], array, content.size());
    std::cout << "\033[22;32mOUTPUT FILE COMPLETE\033[039m" << std::endl;
  }

  // Execution Time
  executionTime((float)duration.count() / 1000000, content.size());

  return 0;
}