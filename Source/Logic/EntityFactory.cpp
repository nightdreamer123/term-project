#include "GateKeeperSource/src/GateKeeper.h"
#include "EnemyControllerInit.h"
#include "EntityFactory.h"
#include "EnemyTypes.h"
#include "Creature.h"

#include "../Engine/Controller.h"
#include "../Engine/TextureManager.h"

#include "../Network/Message.h"

#include "../Multimedia/graphics/object/SGO.h"

#include "Entities/ProperEntity.h"

using Networking::Message;
using Marx::Controller;
using Marx::Entity;
using Marx::Map;

EntityFactory* EntityFactory::instance = 0;

EntityFactory::EntityFactory()
{
    // initialize instance variables
    gkSprite = Manager::TextureManager::store(
        Manager::TextureManager::load("Assets/Art/Misc/placeholder_32.png")
    );

    gkSGO.sprite().setTexture(*Manager::TextureManager::get(gkSprite));
    gkSGO.sprite().setTextureRect(sf::IntRect(0, 0, 32, 32));
    gkSGO.sprite().setScale(2, 2);
    gkSGO.middleAnchorPoint(true);
}

EntityFactory::~EntityFactory()
{
    // release recourses
}

EntityFactory* EntityFactory::getInstance()
{
    if(instance == 0)
    {
        instance = new EntityFactory();
    }
    return instance;
}

Entity* EntityFactory::makeEntityFromNetworkMessage(Map* cMap, Message* msg, Controller* cont)
{
    // Parse Network Message
    EnemyControllerInit* init = (EnemyControllerInit*) msg->data;

    // Init Data:
    // init->type  ENEMY_TYPES
    // init->x     float
    // init->y     float

    // Create the enemy
    return EntityFactory::makeEntity(init->type,cont,cMap,init->x,init->y);
}


Entity* EntityFactory::makeEntity(ENEMY_TYPES type, Controller* cont,Map* map, float x, float y)
{
    Entity* entity;

    switch(type)
    {
        case BASIC_TYPE:
            entity = new ProperEntity(map,x,y,cont,1.0,1.0);
            // entity = new GateKeeper(gkSGO,map,x,y,cont,1,1);

            break;
        case I_DONT_KNOW:
            // CREATE NEW ENEMY OF GIVEN TYPE
            // RETURN ENEMY
            break;

        default:
            break;
    }

    return entity;
}
