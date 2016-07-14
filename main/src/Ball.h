#pragma once
#include "BaseEntity.h"

class Ball : public BaseEntity
{
public:
	Ball();
	Ball(Texture* a_texture, Transform& a_rootTransform);
	~Ball();

	void Update(float deltaTime);
	void Draw(SpriteBatch* a_spriteBatch);

};

