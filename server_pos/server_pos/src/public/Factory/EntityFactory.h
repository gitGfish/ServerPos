#pragma once

#include "../Entity/EntityPlayer.h"
#include "../Entity/EntityEnemy.h"
using namespace std;
class EntityFactory {

	unique_ptr<IEntity> createEntity(long long _uuid, EntityType _type) {
		switch (_type)
		{
		case Player:
			return make_unique< EntityPlayer>(_uuid);
				break;
		case Enemy:
			return make_unique< EntityEnemy>(_uuid);
			break;
		default:
			break;
		}
	}

};