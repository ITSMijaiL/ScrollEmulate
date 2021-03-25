

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <fstream>
const int minWheelMovement = 120;
int cooldown = 100;
int configUP = VK_SUBTRACT;
int configDOWN = VK_ADD;


void SetUP(std::string inp) {
    char k;
    std::transform(inp.begin(), inp.end(), inp.begin(), ::toupper);
    k = inp.c_str()[0];
    if (configDOWN == int(k)) {
        std::cout << "Key was already binded to scroll up." << std::endl;
    }
    else {
        std::cout << "Binded " << k << " to scroll UP!" << std::endl;
        configUP = int(k);
    }
}

void SetDOWN(std::string inp) {
    char k;
    std::transform(inp.begin(), inp.end(), inp.begin(), ::toupper);
    k = inp.c_str()[0];
    if (configUP == int(k)) {
        std::cout << "Key was already binded to scroll up." << std::endl;
    }
    else {
        std::cout << "Binded " << k << " to scroll DOWN!" << std::endl;
        configDOWN = int(k);
    }
}

bool file_exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

std::string generate_filename() {//lol
    std::string res = "";
    std::string txt = ".txt";
    int idx = 0;
    while (true) {
        if (!file_exists("Config " + idx + txt)) {
            res = "Config " + std::to_string(idx) + txt;
            break;
        }
        idx = idx + 1;
    }
    return res;
}

void Load(std::string filename) {
    std::string conf;
    std::ifstream file(filename);
    int idx = 0;
    while (std::getline(file, conf)) {
        if (idx == 0) {
            if (conf.length() != 1) {
                std::cout << "[ERROR WHILE LOADING FILE]Key was not set / key is more than 1 character." << std::endl;
            }
            else {
                SetUP(conf);
            }
        }
        if (idx == 1) {
            if (conf.length() != 1) {
                std::cout << "[ERROR WHILE LOADING FILE]Key was not set / key is more than 1 character." << std::endl;
            }
            else {
                SetDOWN(conf);
            }
        }
        if (idx + 1 >= 2) { return; }
        idx = idx + 1;
    }

}

void Save(std::string filename) {
    std::ofstream file(filename);
    file << char(configUP) << std::endl;
    file << char(configDOWN) << std::endl;
    file.close();
}

int main()
{
    SetConsoleTitleA("ScrollEmulate 0.01");
    std::cout << "Welcome to ScrollEmulate Alpha\n";
    std::cout << "To open the program's console, use SHIFT + M\n";
    //char a = 'A';
    //std::cout << int(a);
    while (true) {
        //if (GetKeyState(VK_OEM_MINUS) & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        /*if(GetKeyState(0x32) & 0x8000)
        {
            Sleep(500);
            std::cout << "2 was pressed" << std::endl;
        }*/

        if (GetAsyncKeyState(configUP) & 0x8000) {
            //std::cout << "minus key from numpad pressed" << std::endl;
            std::cout << "[DEBUG]Moving up" << std::endl;
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 2 * minWheelMovement, 0);
            Sleep(cooldown);
        }
        if (GetAsyncKeyState(configDOWN) & 0x8000) {
            //std::cout << "add key from numpad pressed" << std::endl;
            std::cout << "[DEBUG]Moving down" << std::endl;
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 2 * minWheelMovement * -1, 0);
            Sleep(cooldown);
        }
        
        if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState(0x4D) & 0x8000)) { // shift + M
            std::string cmd;
            std::cout << ">>";
            std::cin >> cmd;
            if (cmd == "exit") {
                exit(0);
            }
            if (cmd == "save") {
                std::string randfilename = generate_filename();
                Save(randfilename);
                std::cout << "Saved configuration at " + randfilename;
                std::cout << std::endl;
            }
            if (cmd == "load") {
                int idx = 0;
                std::cout << "Insert a config file's index:";
                std::cin >> idx;
                Load("Config "+std::to_string(idx)+".txt");
            }
            if (cmd == "config_up") {
                char k;
                std::string k2="";
                std::cout << "Insert the key to bind to scroll up:";
                std::cin >> k2;
                if (k2.length() != 1) {
                    std::cout << "Key was not set / input is more than 1 character." << std::endl;
                }
                else {
                    SetUP(k2);
                }
            }
            if (cmd == "config_down") {
                char k;
                std::string k2 = "";
                std::cout << "Insert the key to bind to scroll down:";
                std::cin >> k2;
                if (k2.length() != 1) {
                    std::cout << "Key was not set / input is more than 1 character." << std::endl;
                }
                else {
                    SetDOWN(k2);
                }
            }
            if (cmd == "config_cooldown") {
                int cool;
                std::cout << "Insert cooldown (in milliseconds):";
                std::cin >> cool;
                if (cool == 0) {
                    cool = 100;
                }
                cooldown = cool;
                std::cout << "Setted cooldown to " << cool << std::endl;
            }
            if (cmd == "help") {
                std::cout << "COMMANDS:";
                std::cout << "--MISC--" << std::endl;
                std::cout << "help: displays this msg" <<std::endl;
                std::cout << "clear: clears the console output." << std::endl;
                std::cout << "--CONFIG--" << std::endl;
                std::cout << "config_up: binds a key to scroll up." << std::endl;
                std::cout << "config_down: binds a key to scroll down." << std::endl;
                std::cout << "config_cooldown: sets the milliseconds cooldown to what you chose." << std::endl;
                std::cout << "--CONFIG SAVING/LOADING (CURRENTLY EXPERIMENTAL, CAN CHANGE)--" << std::endl;
                std::cout << "load: loads a config file using an index." << std::endl;
                std::cout << "save: writes a config file in the same directory where the program is." << std::endl;
            }

            if (cmd == "clear") {
                system("CLS");
            }
        }
    }
}
