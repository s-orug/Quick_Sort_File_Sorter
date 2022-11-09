#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <random>
#include <sstream>
#include <vector>

int partition(int array[], int low, int high) {
  int pivot = array[high], i = low - 1;
  for (int j = low; j < high; ++j) {
    if (array[j] <= pivot) {
      ++i;
      int tmp = array[j];
      array[j] = array[i];
      array[i] = tmp;
    }
  }

  int tmp = array[high];
  array[high] = array[i + 1];
  array[i + 1] = tmp;

  return ++i;
}

void sort(int array[], int low, int high, int size) {
  if (low < high) {
    sort(array, low, partition(array, low, high) - 1, size);
    sort(array, partition(array, low, high) + 1, high, size);
  }
}

int main(int argc, char **argv) {

  std::string number;

  std::cout << "\033[32mPROCESS INITIATED\033[039m" << std::endl;
  std::cout << "FILE NAME: " << argv[1] << std::endl;
  std::ifstream file(argv[1]);
  if (!file.good()) {
    std::cout << "\033[31mFILE DOES NOT EXIST\033[039m" << std::endl;
    return 0;
  }
  std::cout << "\033[32mFILE EXISTS\033[039m" << std::endl;

  std::vector<int> content;
  std::stringstream ss;

  while (getline(file, number, ' ')) {
    content.push_back(stoi(number));
  }
  std::cout << "FILE CONTENTS: ";
  for (auto i : content)
    std::cout << i << " ";
  std::cout << std::endl;

  int array[content.size()];
  std::copy(content.begin(), content.end(), array);

  // MEASURING TIME
  auto start = std::chrono::high_resolution_clock::now();
  sort(array, 0, content.size() - 1, content.size());
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

  std::cout << "SORTED CONTENTS: ";
  for (auto i : array)
    std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "\033[1mExecution Time: " << (float)duration.count() / 1000
            << " microseconds"
            << "\033[039m";

  file.close();
  return 0;
}