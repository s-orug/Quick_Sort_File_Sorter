#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <random>
#include <sstream>
#include <vector>

bool OUTPUTFILECONTENT = false;

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

void outputFile(std::string filename, int array[], int size) {

  std::ofstream output_file(filename);
  for (int s = 0; s < size - 1; ++s) {
    output_file << array[s] << " ";
  }
  output_file << array[size - 1];
  output_file.close();
}

void executionTime(float time, int size) {

  std::string execution_time_file = "Oruganti_SaiDurgaRithvik_executionTime.txt";
  std::ofstream exec(execution_time_file, std::ios_base::app);
  std::ifstream file(execution_time_file);
  if (!(file.peek() == EOF)) {
    exec << std::endl;
  }

  exec << size << " " << time;
  exec.close();
}

int main(int argc, char **argv) {

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

  std::vector<int> content;
  std::stringstream ss;

  while (getline(file, number, ' ')) {
    content.push_back(stoi(number));
  }

  if (OUTPUTFILECONTENT) {
    std::cout << "FILE CONTENTS: ";
    for (auto i : content)
      std::cout << i << " ";
    std::cout << std::endl;
  }

  int array[content.size()];
  std::copy(content.begin(), content.end(), array);
  file.close();

  // Measuring Time
  auto start = std::chrono::high_resolution_clock::now();
  sort(array, 0, content.size() - 1, content.size());
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