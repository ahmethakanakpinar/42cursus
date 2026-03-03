#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "\033[1;95m╔════════════════════════════════════════════════════════════╗\033[0m" << std::endl;
    std::cout << "\033[1;95m║                      🎮 CLAPTRAP & SCAVTRAP 🎮             ║\033[0m" << std::endl;
    std::cout << "\033[1;95m║                       ex01 - Serena, my love!              ║\033[0m" << std::endl;
    std::cout << "\033[1;95m╚════════════════════════════════════════════════════════════╝\033[0m" << std::endl << std::endl;

    std::cout << "\033[1;33m🔥 ROUND 1: Deploying units\033[0m" << std::endl;
    ClapTrap jack("Jack the Destroyer");
    ScavTrap bob("Bob the Scavenger");

    std::cout << "\033[1;33m⚔️ ROUND 2: Different attack messages\033[0m" << std::endl;
    jack.attack("Enemy");
    bob.attack("Enemy");                    // ScavTrap message + 20 damage

    std::cout << "\033[1;33m🛡️ ROUND 3: ScavTrap special ability\033[0m" << std::endl;
    bob.guardGate();

    std::cout << "\033[1;33m💥 ROUND 4: Combat test\033[0m" << std::endl;
    bob.takeDamage(30);
    bob.beRepaired(15);

    std::cout << "\033[1;33m🧬 ROUND 5: Cloning Technology\033[0m" << std::endl;
    ScavTrap cloneBob(bob);                 // Copy Constructor + chaining
    cloneBob.attack("Clone Enemy");

    std::cout << "\033[1;33m📋 ROUND 6: Assignment Operator\033[0m" << std::endl;
    ScavTrap assigned;
    assigned = cloneBob;                    // Assignment Operator

    std::cout << "\033[1;33m🧪 ROUND 7: Constructor/Destructor Chaining Test\033[0m" << std::endl;
    {
        std::cout << "   → Creating temporary ScavTrap inside scope..." << std::endl;
        ScavTrap temp("Temporary");
        temp.guardGate();
        std::cout << "   → Leaving scope → temp will be destroyed now..." << std::endl;
    }   // (ScavTrap → ClapTrap)

    std::cout << "\033[1;33m🏆 ROUND 8: Final endurance test\033[0m" << std::endl;
    bob.takeDamage(90);          // Bob should be at 0 HP now
    bob.attack("Last Enemy");
    bob.beRepaired(10);
    bob.guardGate();

    std::cout << std::endl;
    std::cout << "\033[1;92m🏁 THE BATTLE HAS ENDED! \033[0m" << std::endl;

    return 0;
}