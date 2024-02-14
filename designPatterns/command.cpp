#include <iostream>
#include <vector>

// Receiver
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

// Command Interface
class Command {
public:
    virtual void execute() = 0;
};

// Concrete Command for turning on the light
class TurnOnCommand : public Command {
private:
    Light* light;

public:
    TurnOnCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOn();
    }
};

// Concrete Command for turning off the light
class TurnOffCommand : public Command {
private:
    Light* light;

public:
    TurnOffCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOff();
    }
};

// Invoker
class RemoteControl {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* cmd) {
        commands.push_back(cmd);
    }

    void pressButton(int index) {
        if (index >= 0 && index < commands.size()) {
            commands[index]->execute();
        }
    }
};

int main() {
    // Receiver
    Light light;

    // Concrete Commands
    TurnOnCommand turnOn(&light);
    TurnOffCommand turnOff(&light);

    // Invoker
    RemoteControl remote;

    // Add commands to the invoker
    remote.addCommand(&turnOn);
    remote.addCommand(&turnOff);

    // Press buttons on the remote control
    remote.pressButton(0); // Turn the light on
    remote.pressButton(1); // Turn the light off

    return 0;
}
