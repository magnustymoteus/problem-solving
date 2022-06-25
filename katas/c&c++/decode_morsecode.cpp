#include <iostream>
#include <map>
#include <cstdint>
std::string decodeMorse(std::string morseCode)
{
    std::string decoded, word;
    std::map<std::string, std::string> morse_v1 = {
    {",", "--..--"},
    {".", ".-.-.-"},
    {"?", "..--.."},
    {"0", "----- "},
    {"1", ".---- "},
    {"2", "..--- "},
    {"3", "...-- "},
    {"4", "....- "},
    {"5", "..... "},
    {"6", "-.... "},
    {"7", "--... "},
    {"8", "---.. "},
    {"9", "----. "},
    {"A", ".-"},
    {"B", "-..."},
    {"C", "-.-."},
    {"D", "-.. "},
    {"E", "."},
    {"F", "..-."},
    {"G", "--."},
    {"H", "...."},
    {"I", ".."},
    {"J", ".---"},
    {"K", "-.-"},
    {"L", ".-.."},
    {"M", "--"},
    {"N", "-."},
    {"O", "---"},
    {"P", ".--."},
    {"Q", "--.-"},
    {"R", ".-."},
    {"S", "..."},
    {"T", "-"},
    {"U", "..-"},
    {"V", "...-"},
    {"W", ".--"},
    {"X", "-..-"},
    {"Y", "-.--"},
    {"Z", "--.."},
};
std::map<std::string, std::string> MORSE_CODE;
for(std::map<std::string, std::string>::iterator i = morse_v1.begin(); i != morse_v1.end(); ++i) {
    MORSE_CODE[i->second] = i->first;
}
    for (uint64_t spacesAm = 0, i = morseCode.find_first_not_of(" \t"); i <= morseCode.find_last_not_of(" \t") + 1; i++)
    {
        if (i == morseCode.length() || morseCode[i] == ' ')
        {
            decoded += (morseCode[i] == ' ' && ++spacesAm == 2) ? " " : MORSE_CODE[word];
            word = "";
        }
        else
        {
            spacesAm = 0;
            word += morseCode[i];
        }
    }
    return decoded;
}
int main()
{
    std::cout << decodeMorse(".... ..  ....... ... .- .-. .-"); // => HI SARA
}
