#include "choix.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Choix& choix){
    switch (choix) {
        case Choix::Oui:
            out << "Oui";
            break;
        case Choix::Non:
            out << "Non";
            break;
        case Choix::Blanc:
            out << "Blanc";
            break;
    }
    return out;
}