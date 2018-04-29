#pragma once


class Collider;
class ColliderBox;
class ColliderCircle;


class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();


public:
	bool Init();
	void Update(Collider* collider, Collider* other);
	bool CheckCollisionBox(ColliderBox* pBox, ColliderBox* pOtherBox);
	bool CheckCollisionCircle(ColliderCircle* pCircle, ColliderCircle* pOtherCircle);
	bool CheckCollisionBoxCircle(ColliderBox* pBox, ColliderCircle* pCircle);



private:




private:




};
