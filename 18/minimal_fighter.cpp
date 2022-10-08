#include <iostream>
#include "minimal_fighter.h"

using namespace std;

MinimalFighter::MinimalFighter(){
        mHp = 0;
        mPower = 0;
        mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power){
        mHp = _hp;
        mPower = _power;
        if(mHp <= 0){
                mStatus = Dead;
        }
        else{
                mStatus = Alive;
        }
}

int MinimalFighter::hp(){
        return mHp;
}

int MinimalFighter::power(){
        return mPower;
}

FighterStatus MinimalFighter::status(){
        return mStatus;
}

void MinimalFighter::setHp(int _hp){
        mHp = _hp;
}

void MinimalFighter::setStatus(){
        if(mHp <= 0){
                mStatus = Dead;
        }
        else{
                mStatus = Alive;
        }
}

void MinimalFighter::hit(MinimalFighter *_enemy){
        this->mHp -= _enemy->mPower;
        _enemy->mHp -= this->mPower;
        this->setStatus();
        _enemy->setStatus();
}

void MinimalFighter::attack(MinimalFighter *_enemy){
        _enemy->mHp -= this->mPower;
        this->mPower = 0;
        this->setStatus();
        _enemy->setStatus();
}

void MinimalFighter::fight(MinimalFighter *_enemy){
        while(this->mStatus == Alive && _enemy->mStatus == Alive){
                this->mHp -= _enemy->mPower;
                _enemy->mHp -= this->mPower;
                if(this->mHp <= 0){
                        this->mStatus = Dead;
                }
                if(_enemy->mHp <= 0){
                        this->mStatus = Dead;
                }
        }
        _enemy->setStatus();
        this->setStatus();
}

