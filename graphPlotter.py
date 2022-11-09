#!/usr/bin/env python3
import matplotlib.pyplot as plt


def main():
    ''' x, y = list(), list()
     for line in open('Oruganti_SaiDurgaRithvik_averageExecutionTime.txt', 'r'):
         lines = [i for i in line.split()]
         x.append(float(lines[0]))
         y.append(float(lines[1]))
     print(x, y)
 '''
    x, y = [5, 1, 8, 2, 5], [5, 6, 3, 1, 4]
    plt.plot(x, y)

    plt.show()


if __name__ == "__main__":
    main()
