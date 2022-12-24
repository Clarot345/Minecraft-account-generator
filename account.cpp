#include <iostream>
#include <string>
#include <unordered_set>

// Function to generate a random alphanumeric string of a given length
std::string generateRandomString(int length) {
  static const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";

  std::string result;
  result.reserve(length);

  for (int i = 0; i < length; ++i) {
    result.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
  }

  return result;
}

int main() {
  // Set to store generated accounts
  std::unordered_set<std::pair<std::string, std::string>> accounts;

  // Generate 100 random accounts
  for (int i = 0; i < 100; ++i) {
    std::string username = generateRandomString(8);
    std::string password = generateRandomString(12);
    accounts.emplace(username, password);
  }

  // Print generated accounts
  for (const auto& [username, password] : accounts) {
    std::cout << "Username: " << username << ", Password: " << password << std::endl;
  }

  return 0;
}
