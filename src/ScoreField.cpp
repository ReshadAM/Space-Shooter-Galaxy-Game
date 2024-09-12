//
// Created by jbunt on 26-Oct.-22.
//
#include "ScoreField.h"

using namespace std;

ScoreField::ScoreField(string playerName, string score) {
    this->_playerName = playerName;
    this->_score = score;
}

ScoreField::~ScoreField() {}

string ScoreField::getPlayerName() const {
    return this->_playerName;
}

string ScoreField::getScore() const {
    return this->_score;
}