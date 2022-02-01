#include "Player.hpp"

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::setX(int a) {
	x = a;
}

void Point::setY(int a) {
	y = a;
}

//
// P l a y e r
//

int Player::getRot() {
	return rot;
}

int Player::getXpos() {
	return pos.getX();
}

int Player::getYpos() {
	return pos.getY();
}

int Player::getID() {
	return id;
}

string Player::getStr() {
	return str;
}

void Player::setXpos(int a) {
	pos.setX(a);
}

void Player::setYpos(int a) {
	pos.setY(a);
}

void Player::incRot() {
	if (rot == 3)
		rot = 0;
	else
		rot++;
}

void Player::decRot() {
	if (rot == 0)
		rot = 3;
	else
		rot--;
}

void Player::setID(int a) {
	id = a;
}

void Player::setStr() {
	if (id == 0 && rot % 2 == 0)// 0
		str = "0\n0\n0\n0";
	else if (id == 0 && rot % 2 == 1)
		str = "0000";
	else if (id == 1 && rot % 4 == 0)// 1
		str = " 0 \n000";
	else if (id == 1 && rot % 4 == 1)
		str = "0 \n00\n0 ";
	else if (id == 1 && rot % 4 == 2)
		str = "000\n 0 ";
	else if (id == 1 && rot % 4 == 3)
		str = " 0\n00\n 0";
	else if (id == 2 && rot % 2 == 0)// 2
		str = " 0\n00\n0 ";
	else if (id == 2 && rot % 2 == 1)
		str = "00 \n 00";
	else if (id == 3 && rot % 2 == 0)// 3
		str = "0 \n00\n 0";
	else if (id == 3 && rot % 2 == 1)
		str = " 00\n00 ";
	else if (id == 4)// 4
		str = "00\n00";
	else if (id == 5 && rot % 4 == 0)// 5
		str = "0 \n0 \n00";
	else if (id == 5 && rot % 4 == 1)
		str = "000\n0  ";
	else if (id == 5 && rot % 4 == 2)
		str = "00\n 0\n 0";
	else if (id == 5 && rot % 4 == 3)
		str = "  0\n000";
	else if (id == 6 && rot % 4 == 0)// 6
		str = " 0\n 0\n00";
	else if (id == 6 && rot % 4 == 1)
		str = "0  \n000";
	else if (id == 6 && rot % 4 == 2)
		str = "00\n0 \n0 ";
	else if (id == 6 && rot % 4 == 3)
		str = "000\n  0";
}

//
//  o   o    o  o   oo  o    o                              
//  o  ooo  oo  oo  oo  o    o                               
//  o       o    o      oo  oo                               
//  o                                                        
// 
//  0  1    2   3   4   5   6
//