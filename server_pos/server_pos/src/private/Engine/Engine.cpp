
#include "Engine.h"
#include "Util/Enums.h"

Engine::Engine()
{
	entity_factory = make_unique<EntityFactory>;
}

Engine::~Engine()
{
}

ServertStatus Engine::addEntity(long long _id,EntityType _type) {

	
	switch (_type)
	{
	case Player:
		if (players.find(_id) == players.end()) {
			players[_id] = entity_factory.createEntity(_id, EntityType.Player)
		}
		else {
			return ServertStatus.ID_EXISTS;
		}
		break;
	default:
		if (entities.find(_id) == entities.end()) {
			entities[_id] = entity_factory.createEntity(_id, _type)
		}
		else {
			return ServertStatus.ID_EXISTS;
		}
		break;
	}
}


ServertStatus Engine::removeEntity(long long _id) {
	
}


ServertStatus Engine::movePlayer(long long _id, ServertInput _input) {
	try {
		players.at(_id).move(_input);
	}
	catch (const std::out_of_range& e) {
		return ServertStatus.PLAYER_ID_DOESNT_EXISTS;
	}
	catch (...) {
		return ServertStatus.UNKNOWN;
	}
}