#include <iostream>
#include <sstream>
#include <set>
#include "HandPlayer.h"

static const std::string rankNames[] =
{
    "","","2","3","4","5","6","7","8","9","10","J","Q","K","A"
};

static void printHand(const Hand& hand)
{
    std::cout << "\nYour 8 cards:\n";
    for (int i = 0; i < (int)hand.cards.size(); ++i)
    {
        const auto& card = hand.cards[i];
        std::cout << "  [" << i << "] " << rankNames[card.rank] << card.suit << "\n";
    }
    std::cout << "\n";
}

ChosenHand HandPlayer::playHand(const Hand& hand)
{
    printHand(hand);

    std::set<int> chosen;

    while (true)
    {
        std::cout << "Enter up to 5 card indices (0-7) separated by spaces: ";

        std::string line;
        std::getline(std::cin >> std::ws, line);

        std::istringstream ss(line);
        std::set<int> parsed;
        bool valid = true;
        int token;

        while (ss >> token)
        {
            if (token < 0 || token >= (int)hand.cards.size())
            {
                std::cout << "Index " << token << " is out of range. "
                          << "Please use numbers between 0 and "
                          << hand.cards.size() - 1 << ".\n";
                valid = false;
                break;
            }
            if (parsed.count(token))
            {
                std::cout << "Duplicate index " << token << ".\n";
                valid = false;
                break;
            }
            parsed.insert(token);
        }

        if (!ss.eof() && ss.fail())
        {
            std::cout << "Please enter numbers only.\n";
            continue;
        }

        if (!valid) continue;

        if (parsed.empty())
        {
            std::cout << "Please select at least 1 Card.\n";
            continue;
        }

        if (parsed.size() > 5)
        {
            std::cout << "Please choose at most 5 Cards.\n";
            continue;
        }

        chosen = parsed;
        break;
    }

    ChosenHand result;
    std::cout << "\nYou chose: ";
    for (int i : chosen)
    {
        result.cards.cards.push_back(hand.cards[i]);
        std::cout << rankNames[hand.cards[i].rank] << hand.cards[i].suit << " ";
    }
    std::cout << "\n";

    return result;
}