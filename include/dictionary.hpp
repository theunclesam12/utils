#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/**
 * @file dictionary.hpp
 * @author Samuel Ethan Gan (samuel.gan@deakin.edu.au)
 * @brief Generic dictionary class for any type
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <unordered_map>
#include <stdexcept>
#include <vector>
#include <algorithm>

template<typename T>
class Dictionary
{
private:
    std::unordered_map<std::string, T> dict;
    std::vector<std::string> keys;

public:
    /**
     * @brief Method to add a key-value pair
     * 
     * @param key string id
     * @param value Dictionary entry
     */
    void add(const std::string &key, T value);

    /**
     * @brief Method to get a value by key
     * 
     * @param key string id
     * @return Stored value
     */
    T get(const std::string &key) const;

    /**
     * @brief Method to check if a key exists
     * 
     * @param key string id
     * @return true/false
     */
    bool exists(const std::string &key) const;

    /**
     * @brief Method to remove a key-value pair
     * 
     * @param key string id
     */
    void remove(const std::string &key);

    /**
     * @brief Returns all keys
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> listKeys() const;
};

#include "../include/dictionary.inl"

#endif // DICTIONARY_HPP
