#include "Picture.h"
#include <iostream>
#include <fstream>
#include <sstream> // Para usar stringstream
#include <regex>   // Para usar expresiones regulares

void Picture::readFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::pair<std::string, int>> row;
        std::stringstream ss(line);
        std::string item;
        while (ss >> item)
        {
            // Remove brackets, commas, and single quotes
            item.erase(std::remove(item.begin(), item.end(), '['), item.end());
            item.erase(std::remove(item.begin(), item.end(), ']'), item.end());
            item.erase(std::remove(item.begin(), item.end(), ','), item.end());
            item.erase(std::remove(item.begin(), item.end(), '\''), item.end());

            // Check if the item starts with 'p(' and ends with ')'
            if (item.substr(0, 2) == "p(" && item[item.length() - 1] == ')')
            {
                // Extract the numbers between '(' and ')'
                std::string numbers = item.substr(2, item.length() - 3);
                std::stringstream numStream(numbers);
                std::string number;
                // int value1, value2;
                //  if (std::getline(numStream, number, ',')) {
                //      value1 = std::stoi(number);
                //      if (std::getline(numStream, number, ',')) {
                //          value2 = std::stoi(number);
                //      } else {
                //          value2 = 0;
                //      }
                //  }
                row.push_back(std::make_pair(item, 0)); // value1 * 10 + value2));
            }
            else
            {
                // For items that do not match 'p(x,y)', assume value as 0
                row.push_back(std::make_pair(item, 0));
            }
        }
        if (!row.empty())
        {
            matrix.push_back(row);
        }
    }

    file.close();
}

void Picture::printMatrix()
{
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            std::cout << elem.first << "(" << elem.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Picture::setValue(int rowIdx, int colIdx, int value)
{
    if (rowIdx < 0 || static_cast<std::size_t>(rowIdx) >= matrix.size() || colIdx < 0 || static_cast<std::size_t>(colIdx) >= matrix[static_cast<std::size_t>(rowIdx)].size())
    {
        std::cerr << "Error: Index out of range." << std::endl;
        return;
    }
    matrix[static_cast<std::size_t>(rowIdx)][static_cast<std::size_t>(colIdx)].second = value;
}

std::string Picture::getId(int rowIdx, int colIdx)
{
    if (rowIdx < 0 || static_cast<std::size_t>(rowIdx) >= matrix.size() || colIdx < 0 || static_cast<std::size_t>(colIdx) >= matrix[static_cast<std::size_t>(rowIdx)].size())
    {
        std::cerr << "Error: Index out of range." << std::endl;
        return "Error";
    }
    else 
        return matrix[static_cast<std::size_t>(rowIdx)][static_cast<std::size_t>(colIdx)].first;
}

Picture Picture::clone() const {
    // Utilizar el constructor de copia para crear una nueva instancia
    return Picture(*this);
}

const std::vector<std::vector<std::pair<std::string, int>>>& Picture::getMatrix() const {
    return matrix;
}
