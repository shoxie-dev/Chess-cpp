#ifndef _PLAYER_
#define _PLAYER_
#include <string>
class Player{
    public:
        Player() = default;
        //Player(std::string name_param, char color_param);

        std::string getName() const{
            return name;
        }

        char getColor() const{
            return color;
        }

        void setName(std::string name_param){
            name = name_param;
        }

        void setColor(char color_param){
            color = color_param;
        }



    private:
        std::string name;
        char color;

};

#endif