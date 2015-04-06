#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Event.h"
#include "../Engine/Entity.h"
#include "../Engine/Action.h"
#include "../Engine/ProjectileManager.h"

using Marx::Entity;

/*
 * This Class provides a common interface for all "creature" in the game
 * including the player. This allows them to be buffed/debuffed identically.
 *
 * PROGRAMMER: Calvin Rempel
*				Thomas Tallentire
 */
class Creature
{
    public:
        Creature();
        ~Creature();
        virtual void setHealth(int health);
        virtual void setAttack(int attack);
		virtual int getHealth();
		virtual int getAttack();
		virtual Marx::Projectile* createAttack(AttackEvent&, SGO &sprite, float x, float y);
		virtual Marx::Projectile* createSkAttack(SkillAttackEvent& event, SGO &sprite, float x, float y);
        virtual Entity * getEntity();
	private:
		std::map<enum ActionType, Marx::Action*> actionList;
};

#endif
