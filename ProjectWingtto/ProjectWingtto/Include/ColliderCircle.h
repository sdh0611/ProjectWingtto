#pragma once

#include "../pch.h"
#include "./Collider.h"


class ColliderCircle :public Collider {

public:
	ColliderCircle();
	virtual ~ColliderCircle();


public:
	virtual bool Init(class Object* object) override;
	virtual void Update(const float& deltaTime) override;
	void SetRadius(float radius);
	inline const float& GetRadius() { return fRadius; }


private:



private:
	float fRadius;


};