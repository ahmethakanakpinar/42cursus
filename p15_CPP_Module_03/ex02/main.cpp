#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "\033[1;95m╔════════════════════════════════════════════════════════════╗\033[0m" << std::endl;
    std::cout << "\033[1;95m║           🎮 CLAPTRAP & SCAVTRAP & FRAGTRAP 🎮           ║\033[0m" << std::endl;
    std::cout << "\033[1;95m║                    ex02 - Repetitive work                 ║\033[0m" << std::endl;
    std::cout << "\033[1;95m╚════════════════════════════════════════════════════════════╝\033[0m" << std::endl << std::endl;

    std::cout << "\033[1;33m🔥 ROUND 1: Deploying units\033[0m" << std::endl;
    ClapTrap jack("Jack the Destroyer");
    ScavTrap bob("Bob the Scavenger");
    FragTrap frag("Fraggy the Happy");

    std::cout << "\033[1;33m⚔️ ROUND 2: Different attack messages\033[0m" << std::endl;
    jack.attack("Enemy");
    bob.attack("Enemy");
    frag.attack("Enemy");                    // FragTrap + 30 damage

    std::cout << "\033[1;33m🛡️ ROUND 3: Special abilities\033[0m" << std::endl;
    bob.guardGate();
    frag.highFivesGuys();

    std::cout << "\033[1;33m💥 ROUND 4: Combat test\033[0m" << std::endl;
    frag.takeDamage(40);
    frag.beRepaired(20);

    std::cout << "\033[1;33m🧬 ROUND 5: Cloning Technology\033[0m" << std::endl;
    FragTrap cloneFrag(frag);                // Copy Constructor + chaining
    cloneFrag.attack("Clone Enemy");

    std::cout << "\033[1;33m📋 ROUND 6: Assignment Operator\033[0m" << std::endl;
    FragTrap assigned;
    assigned = cloneFrag;

    std::cout << "\033[1;33m🧪 ROUND 7: Constructor/Destructor Chaining Test\033[0m" << std::endl;
    {
        std::cout << "   → Creating temporary FragTrap inside scope..." << std::endl;
        FragTrap temp("Temporary");
        temp.highFivesGuys();
        std::cout << "   → Leaving scope → temp will be destroyed now..." << std::endl;
    }

    std::cout << "\033[1;33m🏆 ROUND 8: Final endurance test\033[0m" << std::endl;
    frag.takeDamage(90);
    frag.attack("Last Enemy");
    frag.beRepaired(10);
    frag.highFivesGuys();

    std::cout << std::endl;
    std::cout << "\033[1;92m🏁 THE BATTLE HAS ENDED! All destructors saying goodbye...\033[0m" << std::endl;

    return 0;
}