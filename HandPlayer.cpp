#include <iostream>
#include <sstream>
#include <set>
#include "HandPlayer.h"

static const std::string rankNames[] = {
    "","","2","3","4","5","6","7","8","9","10","J","Q","K","A"
};

static void printHand(const Hand& hand)
{
    std::cout << "\nYour 8 cards:\n";
    for (int i = 0; i < (int)hand.cards.size(); ++i)
    {
        const auto& card = hand.cards[i];
        std::cout << "  [" << i << "] "
                  << rankNames[card.rank] << card.suit << "\n";
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
        std::getline(std::cin >> std::ws, line);  // std::ws skips any leftover newline

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
                std::cout << "Duplicate index " << token << ". Each card can only be picked once.\n";
                valid = false;
                break;
            }
            parsed.insert(token);
        }

        // Check for non-numeric tokens by seeing if the stream failed mid-parse
        if (!ss.eof() && ss.fail())
        {
            std::cout << "Invalid input. Please enter numbers only.\n";
            continue;
        }

        if (!valid) continue;

        if (parsed.empty())
        {
            std::cout << "Please select at least 1 card.\n";
            continue;
        }

        if (parsed.size() > 5)
        {
            std::cout << "Too many cards selected. Please choose at most 5.\n";
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