#include <iostream>
#include <memory>
using namespace std;

// ==== Command Interface ====
class ICommand {
public:
    virtual void execute() = 0;
    virtual ~ICommand() {}
};

// ==== Concrete Command ====
// Concrete Command for turning a device ON
class FreeJokerCommand : public ICommand {
private:
    EnterShop* enterShop;
public:
    FreeJokerCommand(EnterShop* enterShop) : enterShop(enterShop) {}
    void execute() override {
        enterShop->freeJoker();
    }
};

// Concrete Command for changing TV channel
class DoubleMoneyCommand : public ICommand {
private:
    EnterShop* enterShop;
public:
    DoubleMoneyCommand(EnterShop* enterShop) : enterShop(enterShop) {}
    void execute() override {
        enterShop->doubleMoney();
    }
};

// Concrete Command for adjusting Stereo volume
class MegaBlindBuffCommand : public ICommand {
private:
    EnterBlind* enterblind;
public:
    MegaBlindBuffCommand(EnterBlind* enterblind) : enterblind(enterblind) {}
    void execute() override {
        enterblind->megaBlindBuff();
    }
};

// ==== Receiver ====
class RewardFactory {};

// Concrete Receiver: Enter Shop
class EnterShop : public RewardFactory {
public:
    void freeJoker() {
        std::cout << "Free Joker Given" << std::endl;
    }

    void doubleMoney() {
        std::cout << "Double Money Applied" << std::endl;
    }
};

// Concrete Receiver: Enter Blind
class EnterBlind : public RewardFactory {
public:
    void megaBlindBuff() {
        std::cout << "Bonus Multiplier Applied" << std::endl;
    }
};

// ==== Invoker ====
class RewardCommandManager {
private:
    std::unique_ptr<ICommand> command;

public:
    void setTag(std::unique_ptr<ICommand> command) {
        this->command = std::move(command);
    }

    void skipBlind() {
        if (command!= nullptr) {
            command->execute();
        } else {
            std::cout << "No command assigned" << std::endl;
        }
    }
};