#include <filesystem>
#include <glob.h>
#include <iostream>
#include <random>
#include <regex>
#include <sstream>
#include <vector>

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

std::vector<std::string> dirList() {
  struct dirent *entry;
  std::vector<std::string> files;
  std::string directory = "input/";
  DIR *dir = opendir(directory.c_str());

  if (dir == NULL)
    return {""};

  while ((entry = readdir(dir)) != NULL) {
    std::string file = entry->d_name;
    if ((file != ".") && (file != "..")) {

      files.push_back(directory + file);
    }
  }
  closedir(dir);

  return files;
}

int main(int argc, char **argv) {

  std::vector<std::string> files = dirList();
  

  // Generating input
  system("./InputFileGenerator");

  // Delete "executionTime.txt"
  system("echo -n "
         " > Oruganti_SaiDurgaRithvik_executionTime.txt");

  for (auto file : files) {

    std::string output_file =
        std::regex_replace(file, std::regex("\\input"), "output");

    std::stringstream command;
    command << "./Oruganti_SaiDurgaRithvik_QuickSort"
            << " " << file << " " << output_file;
    std::cout << command.str() << std::endl;

    system(command.str().c_str());
    std::cout << std::endl;
  }
  // Sort "executionTime.txt" file
  system("sort -k2 -n -o Oruganti_SaiDurgaRithvik_executionTime.txt "
         "Oruganti_SaiDurgaRithvik_executionTime.txt");
  // Find the average of the execution time
  system(
      "awk '{t[$1]+=$2;n[$1]++}END{for(i in t){print i,t[i]/n[i]}}' "
      "Oruganti_SaiDurgaRithvik_executionTime.txt > Oruganti_SaiDurgaRithvik_averageExecutionTime.txt");
  return 0;
}