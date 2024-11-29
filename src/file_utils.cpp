/**
 * @file file_utils.cpp
 * @author Samuel Ethan Gan (samuelethangan@gmail.com)
 * @brief Contains implementation of functions for doing various tasks.
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/file_utils.hpp"


std::vector<Dictionary<std::string>> FileUtils::extractCSV(const std::string &filename, bool hasHeader)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::runtime_error("Error opening file!");
    }

    std::string line;
    bool isFirstLine = true;

    std::vector<Dictionary<std::string>> result;
    std::vector<std::string> dict_keys;
    int no_column;

    // Read the file line by line
    while (std::getline(file, line)) 
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            auto split_string = FileUtils::splitString(line);
            no_column = int(split_string.size());
            if (hasHeader)
            {
                dict_keys = split_string;
                continue;
            }
            else
            {
                // Parse first line and create a dict_key from 0 to no_column.
                // No "continue", and instead let it parse the first line as an input.
                for (int i = 0; i < no_column; i++)
                {
                    dict_keys.push_back(std::to_string(i));
                }
            }
        }

        Dictionary<std::string> row;
        try 
        {
            auto row_data = FileUtils::splitString(line);
            for (int i = 0; i < no_column; i++)
            {
                row.add(dict_keys[i], row_data[i]);
            }
        } 
        catch (const std::exception& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "One of the lines had an error. Gonna skip it." << std::endl;
            continue;
        }

        result.push_back(row);
    }

    file.close();
    return result;
}

std::vector<std::string> FileUtils::splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

void FileUtils::removeStrFromVec(std::vector<std::string>& vec, const std::string& value)
{
    vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}