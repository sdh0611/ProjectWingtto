//SubSystem���� �̿��Ͽ� ��ü���� GameProgram�� �帧�� ������ Class
//SubSystem : SceneManager, 
//NOTE(18.04.16) ��ǻ� �־�� �� ������ �������� �Ǽ� �ϴ� ���½�Ŵ

#pragma once

#include "pch.h"

class SceneManager;
class Scene;

class GameDirector : public Singleton<GameDirector>
{
	DECLARE_SINGLETON(GameDirector)

public:
	

public:
	bool Init();
	void Run(HDC hDC);
	void Render();
	void Update();

private:



private:
	SceneManager*						mSceneManager;


};

