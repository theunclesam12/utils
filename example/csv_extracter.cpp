#include "../include/file_utils/file_utils.hpp"

int main() {
    std::vector<std::string> files = {
        "move_final_poses.csv",
        "move_intermediate_poses.csv",
        "move_poses.csv"
    };
    for (const auto& filename : files)
    {
        std::cout << "\n\nProcessing the following file: " << filename << std::endl;

        auto csv_data = FileUtils::extractCSV(filename, true);
        
        auto key_list = csv_data[0].listKeys();
        
        // List all keys
        for (const auto& key : key_list)
        {
            std::cout << key << " ";
        }
        std::cout << std::endl;

        // Print all keys
        for (const auto& row : csv_data)
        {
            for (const auto& key : key_list)
            {
                std::cout << row.get(key) << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
