#pragma once
#include "BaseEntity.h"
class Player2 : public BaseEntity
{
public:
	Player2();
	Player2(float a_speed, Texture* a_texture, Transform& a_rootTrans);
	~Player2();


	void Update(float deltaTime);
	void Draw(SpriteBatch* a_spriteBatch);
};

