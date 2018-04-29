//SubSystem들을 이용하여 전체적인 GameProgram의 흐름을 제어할 Class
//SubSystem : SceneManager, 
//NOTE(18.04.16) 사실상 있어야 할 이유를 못느끼게 되서 일단 도태시킴

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

