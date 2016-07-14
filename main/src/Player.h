#pragma once
#include "BaseEntity.h"
#include "SpriteBatch.h"
#include "Transform.h"
#include "Texture.h"
class Player //: public BaseEntity
{
public:
	Player();
	Player(float a_speed, Texture* a_texture, Transform& a_rootTrans, int a_objectID, std::string a_objectName);
	~Player();

	void Update(float deltaTime);
	void Draw(SpriteBatch* a_spriteBatch);

};

