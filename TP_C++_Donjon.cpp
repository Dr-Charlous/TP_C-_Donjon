// TP_C++_Donjon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"

int main()
{
    Character chara(100, 100, 25);
    std::cout << "Character : \n" << "- Life : " << chara.getLife() << " / " << chara.getLife() << "\n- Force : " << chara.getForce() << std::endl;
}