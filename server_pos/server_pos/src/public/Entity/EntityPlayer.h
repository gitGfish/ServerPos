#pragma once

#include "Entity.h"
#include "../Util/Math.h"
#include "../Util/Enums.h"

class EntityPlayer : public IEntity
{
public:
	EntityPlayer(long long _uuid);
	~EntityPlayer() override;

	void move(ServertInput _input) {

	}

private:
	

};

