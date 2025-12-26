int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the PhoneBook!\n";


    do
    {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";        
        std::getline(std::cin, command);

        if(std::cin.eof())
            break;
        
        if (command == "ADD")
        {
          
        }
        else if (command == "SEARCH")
        {
         
        }
        else if (command != "EXIT")
        {
            std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
        }
    } while (command != "EXIT");

    std::cout << GREEN << "Goodbye!" << RESET << std::endl;
    return(0);
}