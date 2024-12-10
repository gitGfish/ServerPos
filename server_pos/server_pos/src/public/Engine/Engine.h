#pragma once

#include "../Util/Enums.h"
#include "../Entity/Entity.h"
#include "../Factory/EntityFactory.h"
#include <unordered_map>
using namespace std;

class Engine
{
public:
	Engine();
	~Engine();
	ServertStatus addEntity(long long _id,EntityType _type);
	ServertStatus removeEntity(long long _id);
	ServertStatus movePlayer(long long _id, ServertInput i);

	void* BrodcastPositions();
	void Tick();

private:

	

	unique_ptr<EntityFactory> entity_factory;
	unordered_map<long long, unique_ptr<IEntity>> players;
	unordered_map<long long, unique_ptr<IEntity>> entities;

};
