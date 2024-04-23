 #include <iostream>
 #include <string>
 #include <vector>

 class Letter {
 public:
     std::string address;
     std::string fullName;
 };

 class Mailman {
 private:
     std::string name;
     int number;
     int deliveredLettersCount;
     std::vector<Letter> lettersInStock;
     std::string postOfficeName;

 public:
     Mailman(std::string name, int number, std::string postOfficeName) {
         this->name = name;
         this->number = number;
         this->postOfficeName = postOfficeName;
         deliveredLettersCount = 0;
     }

     void deliverLetter(std::string address) {
         for (auto it = lettersInStock.begin(); it != lettersInStock.end(); ++it) {
             if (it->address == address) {
                 std::cout << "Delivering letter to: " << address << std::endl;
                 lettersInStock.erase(it);
                 deliveredLettersCount++;
                 return;
             }
         }
         std::cout << "No letter found for address: " << address << std::endl;
     }

     void receiveLetter(std::string address, std::string fullName) {
         Letter newLetter;
         newLetter.address = address;
         newLetter.fullName = fullName;
        lettersInStock.push_back(newLetter);
     }

     void printStatus() {
         std::cout << "Mailman: " << name << ", Number: " << number << ", Post Office: " << postOfficeName << std::endl;
         std::cout << "Delivered Letters Count: " << deliveredLettersCount << std::endl;
         std::cout << "Letters in Stock: " << lettersInStock.size() << std::endl;
     }
 };

 int main() {
     Mailman mailman("Kriss", 12345, "Central Post Office");
     mailman.receiveLetter("123 Main St", "Jordi Alba");
     mailman.receiveLetter("456 Elm St", "Tony Montana");

     mailman.printStatus();

     mailman.deliverLetter("123 Main St");
     mailman.deliverLetter("456 Elm St");
     mailman.deliverLetter("789 Oak St");

    mailman.printStatus();

   return 0;
 }










