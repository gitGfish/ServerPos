#pragma once

#include "../Util/Math.h"
#include  <memory>
class IEntity
{
public:

	virtual ~IEntity() = default;

private:
	const long long uuid;
	Vec2 speed;
	Vec2 position;
};




