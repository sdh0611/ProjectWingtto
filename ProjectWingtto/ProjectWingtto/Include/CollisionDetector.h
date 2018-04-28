#pragma once


class ColliderBox;
class ColliderCircle;


class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();


public:
	bool Init();
	void Update();
	bool CheckCollisionRect(ColliderBox* pBox, ColliderBox* pOtherBox);
	bool CheckCollisionCircle(ColliderCircle* pCircle, ColliderCircle* pOtherCircle);
	bool CheckCollisionRectCircle(ColliderBox* pBox, ColliderCircle* pCircle`);



private:




private:




};
