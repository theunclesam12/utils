#include "../../include/file_utils/dictionary.hpp"

/**
 * @brief Method to add a key-value pair
 * 
 * @param key string id
 * @param value Dictionary entry
 */
template<typename T>
void Dictionary<T>::add(const std::string &key, T value)
{
    dict[key] = value;
    keys.push_back(key);
}


/**
 * @brief Method to get a value by key
 * 
 * @param key string id
 * @return Stored value
 */
template<typename T>
T Dictionary<T>::get(const std::string &key) const
{
    auto it = dict.find(key);
    if (it != dict.end())
    {
        return it->second;
    }
    throw std::invalid_argument("Key not found");
}

/**
 * @brief Method to check if a key exists
 * 
 * @param key string id
 * @return true/false
 */
template<typename T>
bool Dictionary<T>::exists(const std::string &key) const
{
    return dict.find(key) != dict.end();
}

/**
 * @brief Method to remove a key-value pair
 * 
 * @param key string id
 */
template<typename T>
void Dictionary<T>::remove(const std::string &key)
{
    dict.erase(key);
    keys.erase(std::remove(keys.begin(), keys.end(), key), keys.end()); // Erase key from key list
}

/**
 * @brief Returns all keys
 * 
 * @return std::vector<std::string> 
 */
template<typename T>
std::vector<std::string> Dictionary<T>::listKeys() const
{
    return keys;
}