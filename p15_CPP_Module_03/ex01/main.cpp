#include "ClapTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "\033[1;95m╔════════════════════════════════════════════════════════════╗\033[0m" << std::endl;
    std::cout << "\033[1;95m║                     🎮 CLAPTRAP 🎮                         ║\033[0m" << std::endl;
    std::cout << "\033[1;95m║                          ex00                              ║\033[0m" << std::endl;
    std::cout << "\033[1;95m╚════════════════════════════════════════════════════════════╝\033[0m" << std::endl << std::endl;

    ClapTrap jack("Jack the Destroyer");
    ClapTrap bob("Bob the Tank");
    ClapTrap defaultTrap;

    std::cout << "\033[1;33m🔥 ROUND 1: The battle begins!\033[0m" << std::endl;
    jack.attack("Bob");
    bob.takeDamage(5);

    std::cout << "\033[1;33m🛠️ ROUND 2: Bob is angry and repairs himself\033[0m" << std::endl;
    bob.beRepaired(8);

    std::cout << "\033[1;33m⚔️ ROUND 3: Jack goes full power!\033[0m" << std::endl;
    jack.attack("Bob");
    bob.takeDamage(7);

    std::cout << "\033[1;33m💥 ROUND 4: JACK ENERGY RAMPAGE\033[0m" << std::endl;
    for (int i = 0; i < 11; i++)
        jack.attack("Bob");

    std::cout << "\033[1;33m🧟 ROUND 5: Bob is DEAD but still tries...\033[0m" << std::endl;
    bob.takeDamage(20);           // bob is dead after this
    bob.attack("Jack");           // bob is dead, can't attack
    bob.beRepaired(100);          // bob is dead, can't be repaired

    std::cout << "\033[1;33m🧬 ROUND 6: CLONING TECHNOLOGY ACTIVATED!\033[0m" << std::endl;
    ClapTrap cloneJack(jack);                  // Copy Constructor
    ClapTrap assignedFighter;                  
    assignedFighter = cloneJack;               // Assignment Operator

    std::cout << "\033[1;33m🏆 FINAL ROUND: The last survivor tries to repair\033[0m" << std::endl;
    jack.beRepaired(3);   // Jack is low on energy, can't be repaired

    std::cout << std::endl;
    std::cout << "\033[1;92m🏁 THE BATTLE HAS ENDED!🏁\033[0m" << std::endl;
    std::cout << "\033[1;90m(All destructors will now say goodbye...)\033[0m" << std::endl;

    return 0;
}