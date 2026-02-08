#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    return 0;
}