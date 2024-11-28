#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

/**
 * @file file_utils.hpp
 * @author Samuel Ethan Gan (samuelethangan@gmail.com)
 * @brief Contains some useful functions for doing various tasks.
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "../include/dictionary.hpp"

namespace FileUtils {
    /**
     * @brief Extract a dictionary of all the items within a csv file. 
     * It returns a dictionary which can be queried through the key 
     * (obtained from the header, or will be a number from 0 to no_columns)
     * 
     * @param filename string - filename
     * @param hasHeader bool
     * @return std::vector<Dictionary<std::string>> 
     */
    std::vector<Dictionary<std::string>> extractCSV(const std::string &filename, bool hasHeader = true);

    /**
     * @brief Splits a string based on the delimiter. Default is ","
     * 
     * @param str String to be split
     * @param delimiter Delimiter
     * @return std::vector<std::string> 
     */
    std::vector<std::string> splitString(const std::string &str, char delimiter = ',');

    /**
     * @brief Removes a matching string from a vector of strings.
     * 
     * @param vec vector of strings to be removed.
     * @param value string to be removed from the vector.
     * 
     */
    void removeStrFromVec(std::vector<std::string>& vec, const std::string& value);
};

#endif